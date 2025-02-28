#include "s21_decimal.h"

/*Write bit to big decimal by specified position*/
void s21_big_set_bit(s21_big_decimal *decimal, int position, int bit) {
  int mask = 1 << (position % 32);
  if (bit)
    decimal->bits[position / 32] |= mask;
  else
    decimal->bits[position / 32] &= ~mask;
}

/*Get bit from big decimal by specified position*/
int s21_big_get_bit(s21_big_decimal decimal, int position) {
  int mask = 1 << (position % 32);
  return !!(decimal.bits[position / 32] & mask);
}

/*Binary left shift of big decimal, shifts from 1 to 30*/
void s21_big_left_shift(s21_big_decimal *decimal, int shift) {
  unsigned int tmp = 0;
  for (int i = 0; i < 8; i++) {
    unsigned temp = decimal->bits[i];
    decimal->bits[i] <<= shift;
    decimal->bits[i] |= tmp;
    tmp = temp >> (32 - shift);
  }
}

/*Transforms decimal to big decimal*/
void num_to_big_decimal(s21_big_decimal *num_big_1, s21_decimal num_1) {
  for (int i = 0; i < 3; i++) {
    num_big_1->bits[i] = num_1.bits[i];
  }
}

/*Transforms big decimal to decimal*/
void big_decimal_to_num(s21_big_decimal num_big_1, s21_decimal *num_1) {
  for (int i = 0; i < 3; i++) {
    num_1->bits[i] = num_big_1.bits[i];
  }
}

/*Binary addition of two big decimals*/
void s21_big_sum(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  int tmp = 0;
  for (int i = 0; i < 224; i++) {
    int bits = s21_big_get_bit(value_1, i) + s21_big_get_bit(value_2, i) + tmp;
    s21_big_set_bit(result, i, bits % 2);
    tmp = bits / 2;
  }
}

/*Binary subtract of two big decimals*/
void s21_big_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  s21_big_decimal num = value_1;
  for (int i = 0; i < 224; i++) {
    int bits = s21_big_get_bit(num, i) - s21_big_get_bit(value_2, i);
    s21_big_set_bit(result, i, bits % 2);

    if (bits < 0) {
      int flag = 1;
      for (int j = i + 1; flag && j < 223; j++) {
        if (s21_big_get_bit(num, j)) {
          s21_big_set_bit(&num, j, 0);
          flag = 0;
        } else {
          s21_big_set_bit(&num, j, 1);
        }
      }
    }
  }
}

/*Multiplication big decimal by 10*/
void s21_big_multi_ten(s21_big_decimal *value) {
  s21_big_decimal num = *value;
  s21_big_left_shift(&num, 3);
  s21_big_left_shift(value, 1);
  s21_big_sum(num, *value, value);
}

/*Normilizes 2 big decimals to the same scale*/
void s21_big_normalization(s21_big_decimal *value_1, s21_big_decimal *value_2,
                           int scale_1, int scale_2) {
  int delta_scale = s21_abs(scale_1 - scale_2);
  if (delta_scale) {
    for (int i = 0; i < delta_scale; i++) {
      s21_big_multi_ten(scale_1 > scale_2 ? value_2 : value_1);
    }
  }
}

/*Removes sign from int number*/
int s21_abs(int num_1) {
  int mask = num_1 & 0x80000000 ? -1 : 0;
  return (num_1 + mask) ^ mask;
}

/*If big decimal is not empty returns 1, else 0*/
int s21_big_decimal_not_empty(s21_big_decimal *value) {
  return !!value->bits[0] + !!value->bits[1] + !!value->bits[2] +
         !!value->bits[3] + !!value->bits[4] + !!value->bits[5] +
         !!value->bits[6] + !!value->bits[7];
}

/*
Is big decimal arg_1 less then big decimal arg_2?
sign default = 0
*/
int s21_big_is_less(s21_big_decimal *big_val_1, s21_big_decimal *big_val_2,
                    int sign) {
  int is_less = 0;
  s21_big_decimal xor = {0};
  for (int i = 7; i >= 0; i--) {
    xor.bits[i] = big_val_1->bits[i] ^ big_val_2->bits[i];
  }
  int j = 256, bit = 0;
  while (bit != 1 && j != 0) {
    j--;
    bit = s21_big_get_bit(xor, j);
  }
  if (bit && s21_big_get_bit(*big_val_1, j) < s21_big_get_bit(*big_val_2, j) &&
      !sign)
    is_less += 1;
  if (bit && s21_big_get_bit(*big_val_1, j) > s21_big_get_bit(*big_val_2, j) &&
      sign)
    is_less += 1;

  return is_less;
}

/*
Is big decimal val_1 equal to big decimal val_2 ?
*/
int s21_big_is_equal(s21_big_decimal *big_val_1, s21_big_decimal *big_val_2) {
  int is_equal = 0;
  s21_big_decimal xor = {0};
  for (int i = 7; i >= 0; i--) {
    xor.bits[i] = big_val_1->bits[i] ^ big_val_2->bits[i];
  }
  int j = 0, bit = 0;
  while (bit != 1 && j != 256) {
    bit = s21_big_get_bit(xor, j);
    j++;
  }
  if (!bit) is_equal++;
  return is_equal;
}

/*
Is big decimal val_1 greater of equal than val_2
sign default = 0
*/
int s21_big_is_greater_or_equal(s21_big_decimal *val_1, s21_big_decimal *val_2,
                                int sign) {
  return !s21_big_is_less(val_1, val_2, sign);
}

/*Checks if big decimal can be written to decimal. func CHANGES src!
Scale should be passed in dst decimal
Returns 1 if cannot be written, else 0*/
int s21_big_overflow(s21_big_decimal *src, s21_decimal *dst) {
  int overflow = 0, scale = s21_get_scale(*dst);
  int decimal_scale = scale, zero_counter = 0;
  s21_big_decimal tmp = *src, res = *src, remainder = {0};
  for (int i = 0; i < scale; i++) {
    if (!s21_big_decimal_not_empty(&tmp)) zero_counter++;
    s21_big_div_ten(tmp, &res);
    tmp = res;
  }
  if (big_simple_overflow(&res)) overflow = 1;
  if (zero_counter > 28 && s21_big_decimal_not_empty(src)) overflow = 2;
  int invisible_remainder = 0, round_check = 0;
  if (zero_counter && !overflow && scale > 28) {
    tmp = *src;
    for (int i = 0; i < scale - 28; i++) {
      s21_big_get_remainder(&tmp, &res, &remainder);
      if (remainder.bits[0] && i < scale - 29) invisible_remainder = 1;
      if (i == scale - 29) round_check = (int)remainder.bits[0];
      tmp = res;
    }
    if ((round_check < 5 || (round_check == 5 && !invisible_remainder)) &&
        !s21_big_decimal_not_empty(&res))
      overflow = 2;
    decimal_scale = 28;
    set_big_dec_to_zero(src);
    *src = res;
  } else if (!overflow && (big_simple_overflow(src) || decimal_scale > 28)) {
    tmp = *src;
    while (decimal_scale > 28 || big_simple_overflow(&tmp)) {
      s21_big_get_remainder(&tmp, &res, &remainder);
      if (remainder.bits[0]) invisible_remainder++;
      round_check = (int)remainder.bits[0];
      tmp = res;
      decimal_scale--;
    }
    if (round_check && invisible_remainder) invisible_remainder--;
    set_big_dec_to_zero(src);
    *src = res;
  }
  if (!overflow &&
      (round_check > 5 || (round_check == 5 && invisible_remainder))) {
    s21_big_add_one(src, &decimal_scale);
  } else if (!overflow && round_check == 5 && !invisible_remainder) {
    tmp = *src;
    s21_big_get_remainder(&tmp, &res, &remainder);
    if (remainder.bits[0] % 2 != 0) s21_big_add_one(src, &decimal_scale);
  }
  if (big_simple_overflow(src)) overflow = 1;
  if (!overflow) s21_set_scale(dst, decimal_scale);
  return overflow;
}

/*Division big decimal by 10*/
int s21_big_div_ten(s21_big_decimal value_1, s21_big_decimal *result) {
  s21_big_decimal big_1 = value_1, big_2 = {{10, 0, 0, 0, 0, 0, 0, 0}},
                  big_3 = {0};
  set_big_dec_to_zero(result);
  while (s21_big_is_greater_or_equal(&big_1, &big_2, 0)) {
    s21_big_decimal big_4 = big_2;
    int tmp = 0;
    s21_big_decimal num_3 = {{1, 0, 0, 0, 0, 0, 0, 0}};
    while (s21_big_is_greater_or_equal(&big_1, &big_4, 0)) {
      s21_big_left_shift(&big_4, 1);
      tmp++;
    }
    big_4 = big_2;
    for (int i = 0; i < tmp - 1; i++) {
      s21_big_left_shift(&big_4, 1);
      s21_big_left_shift(&num_3, 1);
    }
    s21_big_sub(big_1, big_4, &big_1);
    s21_big_sum(big_3, num_3, &big_3);
  }
  *result = big_3;
  return 0;
}

/*Set big decimal to zero*/
void set_big_dec_to_zero(s21_big_decimal *dst) {
  for (int i = 0; i < 8; i++) {
    dst->bits[i] = 0;
  }
}

/*Checks if big decimal may fit decimal
returns 1 in case of overflow*/
int big_simple_overflow(const s21_big_decimal *val) {
  int overflow = 0;
  for (int i = 3; i < 8; i++) {
    if (val->bits[i]) overflow = 1;
  }
  return overflow;
}

/*Adds 1 to big decimal value*/
void s21_big_add_one(s21_big_decimal *src, int *decimal_scale) {
  s21_big_decimal add = {{1, 0, 0, 0, 0, 0, 0, 0}}, tmp = *src;
  s21_big_sum(tmp, add, &tmp);
  if (big_simple_overflow(&tmp) && *decimal_scale >= 1) {
    s21_big_div_ten(*src, &tmp);
    s21_big_sum(tmp, add, &tmp);
    *decimal_scale -= 1;
  }
  *src = tmp;
}

/*Gets remainder after dividing by 10*/
void s21_big_get_remainder(const s21_big_decimal *tmp, s21_big_decimal *res,
                           s21_big_decimal *remainder) {
  s21_big_div_ten(*tmp, res);
  s21_big_decimal tmp2 = *res;
  s21_big_multi_ten(&tmp2);
  s21_big_sub(*tmp, tmp2, remainder);
}