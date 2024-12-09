#include "s21_decimal.h"

/*Converts decimal to float*/
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error_code = 0;
  if (dst == NULL || s21_get_scale(src) > 28 || !is_last_bits_clear(&src)) {
    error_code = 1;
  } else {
    double temp_dest = 0;
    for (int i = 0; i < 96; i++) {
      temp_dest += s21_get_bit(src, i) * pow(2, i);
    }
    temp_dest *= pow(10, (s21_get_scale(src) * (-1)));
    if (s21_get_sign(src)) {
      temp_dest *= -1;
    }
    char str[100] = {0};
    sprintf(str, "%.*lf", s21_get_scale(src), temp_dest);
    sscanf(str, "%f", dst);
  }
  return error_code;
}