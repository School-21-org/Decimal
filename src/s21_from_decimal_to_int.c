#include "s21_decimal.h"

/* Transforms decimal to int*/
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error_code = 0;
  if (dst == NULL || s21_get_scale(src) > 28 || !is_last_bits_clear(&src)) {
    error_code = 1;
  } else {
    s21_decimal temp_value = {0};
    error_code = s21_truncate(src, &temp_value);
    int sign = s21_get_sign(src);
    if (temp_value.bits[1] || temp_value.bits[2] ||
        (temp_value.bits[0] > __INT_MAX__ && !sign) ||
        (temp_value.bits[0] > 2147483648 && sign)) {
      error_code = 1;
    } else {
      *dst = sign ? (temp_value.bits[0] - 1) ^ (-1) : temp_value.bits[0];
    }
  }
  return error_code;
}
