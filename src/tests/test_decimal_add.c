#include "s21_test.h"
START_TEST(decimal_test_add_1) {
  s21_decimal num1 = {{1, 0, 0, 0}};
  s21_decimal num2 = {{1, 0, 0, 0}};
  s21_decimal num3 = {{0}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 2);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_msg(error == 0, "s21_add_1 failed");
}
END_TEST
START_TEST(decimal_test_add_2) {
  s21_decimal num1 = {{0xfffffffe, 0xfffffffe, 0xfffffffe, 0}};
  s21_decimal num2 = {{1, 1, 1, 0}};
  s21_decimal num3 = {{0}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xffffffff);
  ck_assert_uint_eq(num3.bits[1], 0xffffffff);
  ck_assert_uint_eq(num3.bits[2], 0xffffffff);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_msg(error == 0, "s21_add_2 failed");
}
END_TEST
START_TEST(decimal_test_add_3) {
  s21_decimal num1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  s21_decimal num2 = {{1, 0, 0, 0}};
  s21_decimal num3 = {{0}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_msg(error == 1, "s21_add_3 failed");
}
END_TEST
START_TEST(decimal_test_add_4) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{1, 0, 0, 0}};
  s21_decimal num3 = {{0}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 1);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_msg(error == 0, "s21_add_4 failed");
}
END_TEST
START_TEST(decimal_test_add_5) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 1, 0}};
  s21_decimal num3 = {{0}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 1);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_msg(error == 0, "s21_add_5 failed");
}
END_TEST
START_TEST(decimal_test_add_6) {
  s21_decimal num1 = {{0xffffffff, 0xffffffff, 0, 0x00030000}};
  s21_decimal num2 = {{1, 0, 0, 0}};
  s21_decimal num3 = {{0}};

  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 999);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 1);
  ck_assert_uint_eq(num3.bits[3], 196608);
  ck_assert_msg(error == 0, "s21_add_6 failed");
}
END_TEST
START_TEST(decimal_test_add_7) {
  s21_decimal num1 = {{0xfffffffe, 0xffffffff, 0xffffffff, 0x00030000}};
  s21_decimal num2 = {{1, 0, 0, 0x00030000}};
  s21_decimal num3 = {{0}};

  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[1], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[2], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[3], 0x00030000);
  ck_assert_msg(error == 0, "s21_add_7 failed");
}
END_TEST
START_TEST(decimal_test_add_8) {
  s21_decimal num1 = {{1000, 1000, 0, 0x00030000}};
  s21_decimal num2 = {{1, 1, 1, 0x80000000}};
  s21_decimal num3 = {{0}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 1000);
  ck_assert_uint_eq(num3.bits[3], 0x80030000);
  ck_assert_msg(error == 0, "s21_add_8 failed");
}
END_TEST
START_TEST(decimal_test_add_9) {
  s21_decimal num1 = {{1000, 1000, 0, 0x00000000}};
  s21_decimal num2 = {{1000, 1000, 1000, 0x80000000}};
  s21_decimal num3 = {{0}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 1000);
  ck_assert_uint_eq(num3.bits[3], 0x80000000);
  ck_assert_msg(error == 0, "s21_add_9 failed");
}
END_TEST
START_TEST(decimal_test_add_10) {
  s21_decimal num1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x00000000}};
  s21_decimal num2 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x80000000}};
  s21_decimal num3 = {{0}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_msg(error == 0, "s21_add_10 failed");
}
END_TEST
START_TEST(decimal_test_add_11) {
  s21_decimal num1 = {{0xA0FFFFFF, 0x1BCECCED, 0x0f00D3C2, 0x000a0000}};
  s21_decimal num2 = {{0xA0FFFFFF, 0x1BCECCED, 0x0f00D3C2, 0x000a0000}};
  s21_decimal num3 = {{0}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x41FFFFFE);
  ck_assert_uint_eq(num3.bits[1], 0x379D99DB);
  ck_assert_uint_eq(num3.bits[2], 0x1E01A784);
  ck_assert_uint_eq(num3.bits[3], 0x000A0000);
  ck_assert_msg(error == 0, "s21_add_11 failed");
}
END_TEST
START_TEST(decimal_test_add_12) {
  s21_decimal num1 = {{0xf0FFFFFF, 0x1BCECCED, 0xff00D3C2, 0x00140000}};
  s21_decimal num2 = {{0xf0FFFFFF, 0x1BCECCED, 0xff00D3C2, 0x000a0000}};
  s21_decimal num3 = {{0}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xF91233F4);
  ck_assert_uint_eq(num3.bits[1], 0x8954B3C8);
  ck_assert_uint_eq(num3.bits[2], 0xFF00D3C2);
  ck_assert_uint_eq(num3.bits[3], 0x000A0000);
  ck_assert_msg(error == 0, "s21_add_12 failed");
}
END_TEST
START_TEST(decimal_test_add_13) {
  s21_decimal num1 = {{0, 0, 0, 0x00000000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal num3 = {{2, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_msg(error == 0, "s21_add_13 failed");
}
END_TEST
START_TEST(decimal_test_add_14) {
  s21_decimal num1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal num2 = {{5, 0, 0, 0x00010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xFFFFFFFE);
  ck_assert_uint_eq(num3.bits[1], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[2], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_msg(error == 0, "s21_add_14 failed");
}
END_TEST
START_TEST(decimal_test_add_15) {
  s21_decimal num1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal num2 = {{6, 0, 0, 0x00010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[1], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[2], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_msg(error == 0, "s21_add_15 failed");
}
END_TEST
START_TEST(decimal_test_add_16) {
  s21_decimal num1 = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal num2 = {{5, 0, 0, 0x00010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xFFFFFFFE);
  ck_assert_uint_eq(num3.bits[1], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[2], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_msg(error == 0, "s21_add_16 failed");
}
END_TEST
START_TEST(decimal_test_add_17) {
  s21_decimal num1 = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal num2 = {{6, 0, 0, 0x00010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xFFFFFFFE);
  ck_assert_uint_eq(num3.bits[1], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[2], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_msg(error == 0, "s21_add_17 failed");
}
END_TEST
START_TEST(decimal_test_add_18) {
  s21_decimal num1 = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x001c0000}};
  s21_decimal num2 = {{7, 0xFFFFFFFF, 0, 0x00010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x139957D2);
  ck_assert_uint_eq(num3.bits[1], 0xC4653614);
  ck_assert_uint_eq(num3.bits[2], 0x3B9AC9FF);
  ck_assert_uint_eq(num3.bits[3], 0x000A0000);
  ck_assert_msg(error == 0, "s21_add_18 failed");
}
END_TEST

START_TEST(decimal_test_add_19) {
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal num2 = {{1, 0, 0, 0x00000000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  s21_decimal res = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, res), "decimal comparison failed");
  ck_assert_msg(error == 1, "s21_add_19 failed");
}
END_TEST

START_TEST(decimal_test_add_20) {
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal num2 = {{0, 123, 0, 0x00000000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  s21_decimal res = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, res), "decimal comparison failed");
  ck_assert_msg(error == 1, "s21_add_20 failed");
}
END_TEST

START_TEST(decimal_test_add_21) {
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal num2 = {{5, 0, 0, 0x00010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  s21_decimal res = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, res), "decimal comparison failed");
  ck_assert_msg(error == 1, "s21_add_21 failed");
}
END_TEST

START_TEST(decimal_test_add_22) {
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00010000}};
  s21_decimal num2 = {{50, 0, 0, 0x00010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  s21_decimal res = {{0x9999999E, 0x99999999, 0x19999999, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, res), "decimal comparison failed");
  ck_assert_msg(error == 0, "s21_add_22 failed");
}
END_TEST

START_TEST(decimal_test_add_23) {
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00010000}};
  s21_decimal num2 = {{5, 0, 0, 0x00020000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  s21_decimal res = {{0x9999999A, 0x99999999, 0x19999999, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, res), "decimal comparison failed");
  ck_assert_msg(error == 0, "s21_add_23 failed");
}
END_TEST

START_TEST(decimal_test_add_24) {
  s21_decimal num1 = {{0b11111111111111111111111111111011,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x00000000}};
  s21_decimal num2 = {{5, 0, 0, 0x00010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  s21_decimal res = {{0b11111111111111111111111111111100,
                      0b11111111111111111111111111111111,
                      0b11111111111111111111111111111111, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, res), "decimal comparison failed");
  ck_assert_msg(error == 0, "s21_add_24 failed");
}
END_TEST

START_TEST(decimal_test_add_25) {
  s21_decimal num1 = {{1, 0, 0, 0x00000000}};
  s21_decimal num2 = {{5, 0, 0, 0x001D0000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  s21_decimal res = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, res), "decimal comparison failed");
  ck_assert_msg(error == 1, "s21_add_25 failed");
}
END_TEST

START_TEST(decimal_test_add_26) {
  s21_decimal num1 = {{1, 0, 0, 0x10000000}};
  s21_decimal num2 = {{5, 0, 0, 0x00000000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  s21_decimal res = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_msg(s21_is_equal(num3, res), "decimal comparison failed");
  ck_assert_msg(error == 1, "s21_add_26 failed");
}
END_TEST
START_TEST(decimal_test_add_27) {
  s21_decimal num1 = {{1111, 0, 0, 0x00010000}};
  s21_decimal num2 = {{111, 0, 0, 0x80010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 1000);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00010000);
  ck_assert_msg(error == 0, "s21_add_27 failed");
}
END_TEST
START_TEST(decimal_test_add_28) {
  s21_decimal num1 = {{1111, 0, 0, 0x80010000}};
  s21_decimal num2 = {{111, 0, 0, 0x00010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 1000);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x80010000);
  ck_assert_msg(error == 0, "s21_add_28 failed");
}
END_TEST
START_TEST(decimal_test_add_29) {
  s21_decimal num1 = {{111, 0, 0, 0x00010000}};
  s21_decimal num2 = {{1111, 0, 0, 0x80010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 1000);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x80010000);
  ck_assert_msg(error == 0, "s21_add_29 failed");
}
END_TEST
START_TEST(decimal_test_add_30) {
  s21_decimal num1 = {{111, 0, 0, 0x80010000}};
  s21_decimal num2 = {{1111, 0, 0, 0x00010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 1000);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00010000);
  ck_assert_msg(error == 0, "s21_add_30 failed");
}
END_TEST
START_TEST(decimal_test_add_31) {
  s21_decimal num1 = {{111, 0, 0, 0x80010000}};
  s21_decimal num2 = {{111, 0, 0, 0x00010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x80010000);
  ck_assert_msg(error == 0, "s21_add_31 failed");
}
END_TEST
START_TEST(decimal_test_add_32) {
  s21_decimal num1 = {{111, 0, 0, 0x80010000}};
  s21_decimal num2 = {{111, 0, 0, 0x00010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x80010000);
  ck_assert_msg(error == 0, "s21_add_32 failed");
}
END_TEST
START_TEST(decimal_test_add_33) {
  s21_decimal num1 = {{111, 0, 0, 0x00010000}};
  s21_decimal num2 = {{111, 0, 0, 0x80010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00010000);
  ck_assert_msg(error == 0, "s21_add_33 failed");
}
END_TEST
START_TEST(decimal_test_add_34) {
  s21_decimal num1 = {{111, 0, 0, 0x80010000}};
  s21_decimal num2 = {{111, 0, 0, 0x80010000}};
  s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 222);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x80010000);
  ck_assert_msg(error == 0, "s21_add_33 failed");
}
END_TEST
START_TEST(decimal_test_add_35) {
  s21_decimal num1 = {{111, 0, 0, 0x80010000}};
  s21_decimal num2 = {{111, 0, 0, 0x80010000}};
  // s21_decimal num3 = {{0, 0, 0, 0x00000000}};
  int error = s21_add(num1, num2, NULL);
  ck_assert_msg(error == 1, "s21_add_33 failed");
}
END_TEST

Suite *suite_decimal_1() {
  Suite *suite = suite_create("suite_decimal");
  TCase *tcase = tcase_create("tcase_decimal");

  tcase_add_test(tcase, decimal_test_add_1);
  tcase_add_test(tcase, decimal_test_add_2);
  tcase_add_test(tcase, decimal_test_add_3);
  tcase_add_test(tcase, decimal_test_add_4);
  tcase_add_test(tcase, decimal_test_add_5);
  tcase_add_test(tcase, decimal_test_add_6);
  tcase_add_test(tcase, decimal_test_add_7);
  tcase_add_test(tcase, decimal_test_add_8);
  tcase_add_test(tcase, decimal_test_add_9);
  tcase_add_test(tcase, decimal_test_add_10);
  tcase_add_test(tcase, decimal_test_add_11);
  tcase_add_test(tcase, decimal_test_add_12);
  tcase_add_test(tcase, decimal_test_add_13);
  tcase_add_test(tcase, decimal_test_add_14);
  tcase_add_test(tcase, decimal_test_add_15);
  tcase_add_test(tcase, decimal_test_add_16);
  tcase_add_test(tcase, decimal_test_add_17);
  tcase_add_test(tcase, decimal_test_add_18);
  tcase_add_test(tcase, decimal_test_add_19);
  tcase_add_test(tcase, decimal_test_add_20);
  tcase_add_test(tcase, decimal_test_add_21);
  tcase_add_test(tcase, decimal_test_add_22);
  tcase_add_test(tcase, decimal_test_add_23);
  tcase_add_test(tcase, decimal_test_add_24);
  tcase_add_test(tcase, decimal_test_add_25);
  tcase_add_test(tcase, decimal_test_add_26);
  tcase_add_test(tcase, decimal_test_add_27);
  tcase_add_test(tcase, decimal_test_add_28);
  tcase_add_test(tcase, decimal_test_add_29);
  tcase_add_test(tcase, decimal_test_add_30);
  tcase_add_test(tcase, decimal_test_add_31);
  tcase_add_test(tcase, decimal_test_add_32);
  tcase_add_test(tcase, decimal_test_add_33);
  tcase_add_test(tcase, decimal_test_add_34);
  tcase_add_test(tcase, decimal_test_add_35);

  suite_add_tcase(suite, tcase);
  return suite;
}