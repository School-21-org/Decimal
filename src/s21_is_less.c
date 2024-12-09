#include "s21_decimal.h"

/*Returns 1 if decimal val_1 is less than val_2*/
int s21_is_less(s21_decimal val_1, s21_decimal val_2) {
  int is_less = 0;
  int sign_1 = s21_get_sign(val_1);
  int sign_2 = s21_get_sign(val_2);

  if ((!s21_decimal_not_empty(&val_1) && !s21_decimal_not_empty(&val_2)) ||
      !is_last_bits_clear(&val_1) || !is_last_bits_clear(&val_2)) {
    ;
  } else if (sign_1 > sign_2) {
    is_less++;
  } else if (sign_2 > sign_1) {
    ;
  } else {
    int scale_1 = s21_get_scale(val_1);
    int scale_2 = s21_get_scale(val_2);
    s21_big_decimal big_val_1 = {0}, big_val_2 = {0};
    num_to_big_decimal(&big_val_1, val_1);
    num_to_big_decimal(&big_val_2, val_2);
    s21_big_normalization(&big_val_1, &big_val_2, scale_1, scale_2);

    is_less += s21_big_is_less(&big_val_1, &big_val_2, sign_1);
  }

  return is_less;
}
