#include "s21_decimal.h"

/*Returns 1 if decimal val_1 is less or equal than val_2*/
int s21_is_less_or_equal(s21_decimal val_1, s21_decimal val_2) {
  return s21_is_equal(val_1, val_2) || s21_is_less(val_1, val_2);
}