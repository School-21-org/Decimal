#include "s21_decimal.h"

/*Multiply of two decimal numbers*/
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  if (result == NULL || s21_get_scale(value_1) > 28 ||
      s21_get_scale(value_2) > 28 || !is_last_bits_clear(&value_1) ||
      !is_last_bits_clear(&value_2)) {
    error = 1;
  } else if (s21_decimal_not_empty(&value_1) &&
             s21_decimal_not_empty(&value_2)) {
    s21_big_decimal big_1 = {0}, big_2 = {0}, big_3 = {0};
    s21_decimal tmp = {0};
    num_to_big_decimal(&big_1, value_1);
    num_to_big_decimal(&big_2, value_2);
    for (int i = 0; i < 223; i++) {
      if (s21_big_get_bit(big_2, i)) {
        s21_big_sum(big_1, big_3, &big_3);
      }
      s21_big_left_shift(&big_1, 1);
    }
    s21_set_scale(&tmp, s21_get_scale(value_1) + s21_get_scale(value_2));
    error = s21_big_overflow(&big_3, &tmp);
    if (error == 1 && (s21_get_sign(value_1) ^ s21_get_sign(value_2))) error++;
    if (!error) {
      s21_set_sign(&tmp, s21_get_sign(value_1) ^ s21_get_sign(value_2));
      *result = tmp;
      big_decimal_to_num(big_3, result);
    }
  } else {
    set_dec_to_zero(result);
  }
  return error;
}