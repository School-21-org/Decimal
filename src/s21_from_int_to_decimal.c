#include "s21_decimal.h"

/* Transform int value to decimal*/
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error_code = 0;
  if (dst == NULL) {
    error_code++;
  } else {
    set_dec_to_zero(dst);
    if (src < 0) {
      s21_set_sign(dst, 1);
      src *= (-1);
    }
    dst->bits[0] = src;
  }
  return error_code;
}