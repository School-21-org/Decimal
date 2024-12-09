#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H
#include <math.h>
#include <stdio.h>

#define S21_MAX_FLOAT 79228162514264337593543950335.0f

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

typedef union {
  float fl;
  unsigned int integ;
} s21_float_bits;

void s21_set_bit(s21_decimal *, int, int);
int s21_get_bit(s21_decimal, int);
int s21_get_scale(s21_decimal);
void s21_set_scale(s21_decimal *, int);
int s21_get_sign(s21_decimal);
void s21_set_sign(s21_decimal *, int);
void s21_left_shift(s21_decimal *, int);
void s21_right_shift(s21_decimal *, int);
void s21_sum(s21_decimal, s21_decimal, s21_decimal *);
void s21_normalization(s21_decimal *, s21_decimal *);
void s21_multi_ten(s21_decimal *);
void s21_decimal_add_one(s21_decimal *);
void s21_get_remainder(const s21_decimal *, s21_decimal *, s21_decimal *);

void s21_big_set_bit(s21_big_decimal *, int, int);
int s21_big_get_bit(s21_big_decimal, int);
void s21_big_left_shift(s21_big_decimal *, int);
void num_to_big_decimal(s21_big_decimal *, s21_decimal);
void big_decimal_to_num(s21_big_decimal, s21_decimal *);
void s21_big_sum(s21_big_decimal, s21_big_decimal, s21_big_decimal *);
void s21_big_sub(s21_big_decimal, s21_big_decimal, s21_big_decimal *);
void s21_big_multi_ten(s21_big_decimal *);
void s21_big_normalization(s21_big_decimal *, s21_big_decimal *, int, int);
int s21_abs(int);

int s21_add(s21_decimal, s21_decimal, s21_decimal *);
int s21_sub(s21_decimal, s21_decimal, s21_decimal *);
int s21_mul(s21_decimal, s21_decimal, s21_decimal *);
int s21_div(s21_decimal, s21_decimal, s21_decimal *);
int s21_div_ten(s21_decimal, s21_decimal *);

int s21_from_int_to_decimal(int, s21_decimal *);
int s21_from_decimal_to_int(s21_decimal, int *);
int s21_from_float_to_decimal(float, s21_decimal *);
int s21_from_decimal_to_float(s21_decimal, float *);
void write_decimal(char *, const char *, int *, s21_decimal *);
void align_float(const int *, float *, int *);
void set_dec_to_zero(s21_decimal *);
void check_sign(float *, s21_decimal *);

int s21_floor(s21_decimal, s21_decimal *);
int s21_round(s21_decimal, s21_decimal *);
int s21_truncate(s21_decimal, s21_decimal *);
int s21_negate(s21_decimal, s21_decimal *);

int s21_is_less(s21_decimal, s21_decimal);
int s21_big_is_less(s21_big_decimal *, s21_big_decimal *, int);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_big_is_less_or_equal(s21_big_decimal *, s21_big_decimal *, int);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_big_is_equal(s21_big_decimal *, s21_big_decimal *);
int s21_is_not_equal(s21_decimal, s21_decimal);
int s21_big_is_not_equal(s21_big_decimal *, s21_big_decimal *);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_big_is_greater(s21_big_decimal *, s21_big_decimal *, int);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_big_is_greater_or_equal(s21_big_decimal *, s21_big_decimal *, int);
int s21_big_overflow(s21_big_decimal *, s21_decimal *);
int s21_big_div_ten(s21_big_decimal, s21_big_decimal *);
void set_big_dec_to_zero(s21_big_decimal *);
int big_simple_overflow(const s21_big_decimal *);
void s21_big_add_one(s21_big_decimal *, int *);
void s21_big_get_remainder(const s21_big_decimal *, s21_big_decimal *,
                           s21_big_decimal *);

int s21_decimal_not_empty(s21_decimal *);
int s21_big_decimal_not_empty(s21_big_decimal *);
int is_last_bits_clear(const s21_decimal *);

#endif