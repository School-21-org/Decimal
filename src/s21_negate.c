#include "s21_decimal.h"

/*Returns the result of multiplying the specified Decimal value by negative
 * one.*/
int s21_negate(s21_decimal value, s21_decimal *result) {
  int error_code = 0;
  if (result == NULL || s21_get_scale(value) > 28 ||
      !is_last_bits_clear(&value)) {
    error_code = 1;
  } else {
    *result = value;
    s21_set_sign(result, !s21_get_sign(value));
  }
  return error_code;
}
