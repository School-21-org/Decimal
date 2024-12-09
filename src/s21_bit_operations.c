#include "s21_decimal.h"

/*Write bit to decimal by specified position*/
void s21_set_bit(s21_decimal *decimal, int position, int bit) {
  int mask = 1 << (position % 32);
  if (bit)
    decimal->bits[position / 32] |= mask;
  else
    decimal->bits[position / 32] &= ~mask;
}

/*Get bit from decimal by specified position*/
int s21_get_bit(s21_decimal decimal, int position) {
  int mask = 1 << (position % 32);
  return !!(decimal.bits[position / 32] & mask);
}

/*Get decimal scale*/
int s21_get_scale(s21_decimal decimal) {
  return (decimal.bits[3] & 0x00FF0000) >> 16;
}

/*Set decimal scale*/
void s21_set_scale(s21_decimal *decimal, int scale) {
  decimal->bits[3] = ((decimal->bits[3] & 0x80000000) | (scale << 16));
}

/*Get decimal sign*/
int s21_get_sign(s21_decimal decimal) { return s21_get_bit(decimal, 127); }

/*Set decimal scale*/
void s21_set_sign(s21_decimal *decimal, int bit) {
  s21_set_bit(decimal, 127, bit);
}

/*Binary left shift of decimal, shifts from 1 to 30*/
void s21_left_shift(s21_decimal *decimal, int shift) {
  unsigned int tmp = 0;
  for (int i = 0; i < 3; i++) {
    unsigned temp = decimal->bits[i];
    decimal->bits[i] <<= shift;
    decimal->bits[i] |= tmp;
    tmp = temp >> (32 - shift);
  }
}

/*Binary addition of two decimals, not taking sign and scale*/
void s21_sum(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int tmp = 0;
  for (int i = 0; i < 96; i++) {
    int bits = s21_get_bit(value_1, i) + s21_get_bit(value_2, i) + tmp;
    s21_set_bit(result, i, bits % 2);
    tmp = bits / 2;
  }
}

/*Multiplication decimal by 10*/
void s21_multi_ten(s21_decimal *value) {
  s21_decimal num = *value;
  s21_left_shift(&num, 3);
  s21_left_shift(value, 1);
  s21_sum(num, *value, value);
}

/*If decimal is not empty returns 1, else 0*/
int s21_decimal_not_empty(s21_decimal *value) {
  return !!value->bits[0] + !!value->bits[1] + !!value->bits[2];
}

/*Check if the last bit of decimal is clean in 96-111 and 120-126 bits */
int is_last_bits_clear(const s21_decimal *value) {
  int count = 0;
  for (int i = 96; i < 112; i++) count += s21_get_bit(*value, i);
  for (int i = 120; i < 127; i++) count += s21_get_bit(*value, i);
  return count == 0 ? 1 : 0;
}

/*Set decimal to zero*/
void set_dec_to_zero(s21_decimal *dst) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }
}

/*Division decimal by 10*/
int s21_div_ten(s21_decimal value_1, s21_decimal *result) {
  s21_decimal result_res = *result;
  s21_big_decimal big_1 = {0}, big_2 = {{10, 0, 0, 0, 0, 0, 0, 0}}, big_3 = {0};
  num_to_big_decimal(&big_1, value_1);
  set_dec_to_zero(&result_res);
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
  big_decimal_to_num(big_3, result);
  return 0;
}

/*Adds 1 to decimal number*/
void s21_decimal_add_one(s21_decimal *src) {
  s21_decimal one = {{1, 0, 0, 0}};
  s21_add(*src, one, src);
}

/*Gets remainder from decimal res*/
void s21_get_remainder(const s21_decimal *res, s21_decimal *tmp,
                       s21_decimal *dec_remainder) {
  s21_div_ten(*res, tmp);
  s21_decimal tmp2 = *tmp;
  s21_multi_ten(&tmp2);
  s21_sub(*res, tmp2, dec_remainder);
}