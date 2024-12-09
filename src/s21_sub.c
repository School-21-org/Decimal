#include "s21_decimal.h"

/*Subtraction of two decimal numbers*/
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  if (result == NULL || s21_get_scale(value_1) > 28 ||
      s21_get_scale(value_2) > 28 || !is_last_bits_clear(&value_1) ||
      !is_last_bits_clear(&value_2)) {
    error = 1;
  } else {
    s21_big_decimal big_1 = {0}, big_2 = {0}, big_3 = {0};
    s21_decimal num_1 = value_1, num_2 = value_2, tmp = {0};
    s21_set_sign(&num_1, 0), s21_set_sign(&num_2, 0);

    num_to_big_decimal(&big_1, value_1);
    num_to_big_decimal(&big_2, value_2);
    int scale_1 = s21_get_scale(value_1), scale_2 = s21_get_scale(value_2);
    int sign_1 = s21_get_sign(value_1), sign_2 = s21_get_sign(value_2);
    int diff = s21_is_less(num_1, num_2);

    s21_big_normalization(&big_1, &big_2, scale_1, scale_2);
    if (sign_1 ^ sign_2) {
      s21_big_sum(big_1, big_2, &big_3);
      s21_set_sign(&tmp, (!diff && sign_1) || (diff && !sign_2) ? 1 : 0);
    } else {
      s21_big_sub(diff ? big_2 : big_1, diff ? big_1 : big_2, &big_3);
      s21_set_sign(&tmp, (diff && !sign_1) || (!diff && sign_1) ? 1 : 0);
    }
    s21_set_scale(&tmp, scale_1 > scale_2 ? scale_1 : scale_2);
    error = s21_big_overflow(&big_3, &tmp);
    if (error == 1 && s21_get_sign(tmp)) error++;
    if (!error) {
      *result = tmp;
      big_decimal_to_num(big_3, result);
    }
  }

  return error;
}