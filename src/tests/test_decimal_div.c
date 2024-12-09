#include "s21_test.h"
START_TEST(decimal_test_div_1) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_int_eq(error, 3);
}
END_TEST
START_TEST(decimal_test_div_2) {
  s21_decimal num1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
  s21_decimal num2 = {{0b1010, 0, 0, 0}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xffffffff);
  ck_assert_uint_eq(num3.bits[1], 0xffffffff);
  ck_assert_uint_eq(num3.bits[2], 0xffffffff);
  ck_assert_uint_eq(num3.bits[3], 0x00010000);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_div_3) {
  s21_decimal num1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  s21_decimal num2 = {{1, 0, 0, 0}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], UINT32_MAX);
  ck_assert_uint_eq(num3.bits[1], UINT32_MAX);
  ck_assert_uint_eq(num3.bits[2], UINT32_MAX);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_div_4) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{1, 1, 1, 0}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_div_5) {
  s21_decimal num1 = {{1, 0, 0, 0x00000000}};
  s21_decimal num2 = {{1, 0, 0, 0x00020000}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 100);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_div_6) {
  s21_decimal num1 = {{0xffffffff, 0xffffffff, 0, 0x00030000}};
  s21_decimal num2 = {{1, 0, 0, 0}};
  s21_decimal num3 = {{0}};

  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xffffffff);
  ck_assert_uint_eq(num3.bits[1], 0xffffffff);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00030000);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_div_7) {
  s21_decimal num1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x00030000}};
  s21_decimal num2 = {{1, 0, 0, 0x00030000}};
  s21_decimal num3 = {{0}};

  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xffffffff);
  ck_assert_uint_eq(num3.bits[1], 0xffffffff);
  ck_assert_uint_eq(num3.bits[2], 0xffffffff);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_div_8) {
  s21_decimal num1 = {{1000, 1000, 1000, 0x00030000}};
  s21_decimal num2 = {{1, 1, 1, 0x80000000}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 1);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x80000000);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_div_9) {
  s21_decimal num1 = {{1000, 1000, 1000, 0x00000000}};
  s21_decimal num2 = {{1000, 1000, 1000, 0x80000000}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 1);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x80000000);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_div_10) {
  s21_decimal num1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x80000000}};
  s21_decimal num2 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x80000000}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 1);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_div_11) {
  s21_decimal num1 = {{1000, 1000, 1000, 0x001E0000}};
  s21_decimal num2 = {{1000, 1000, 1000, 0x80010000}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 1);
}
START_TEST(decimal_test_div_12) {
  s21_decimal num1 = {{1000, 1000, 1000, 0x00010000}};
  s21_decimal num2 = {{1000, 1000, 1000, 0x801E0000}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 1);
}
START_TEST(decimal_test_div_13) {
  s21_decimal num1 = {{1000, 1000, 1000, 0x00000001}};
  s21_decimal num2 = {{1000, 1000, 1000, 0x80000000}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 1);
}
START_TEST(decimal_test_div_14) {
  s21_decimal num1 = {{1000, 1000, 1000, 0x00000000}};
  s21_decimal num2 = {{1000, 1000, 1000, 0x80000001}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 1);
}
END_TEST
START_TEST(decimal_test_div_15) {
  s21_decimal num1 = {{1000, 1000, 1000, 0x00000000}};
  s21_decimal num2 = {{1000, 1000, 1000, 0x80000000}};
  // s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST
START_TEST(decimal_test_div_16) {
  s21_decimal num1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x001E0000}};
  s21_decimal num2 = {{1, 1, 1, 0x00000000}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_int_eq(error, 1);
}
END_TEST
START_TEST(decimal_test_div_17) {
  s21_decimal num1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x00000000}};
  s21_decimal num2 = {{1, 0, 0, 0x801c0000}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_int_eq(error, 2);
}
END_TEST
START_TEST(decimal_test_div_18) {
  s21_decimal num1 = {{1000, 1000, 1000, 0x80000000}};
  s21_decimal num2 = {{500, 500, 500, 0x00000000}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_div_19) {
  s21_decimal num1 = {{500, 500, 500, 0x80000000}};
  s21_decimal num2 = {{1000, 1000, 1000, 0x00000000}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(decimal_test_div_20) {
  s21_decimal num1 = {{500, 500, 500, 0x00000000}};
  s21_decimal num2 = {{1000, 1000, 1000, 0x80000000}};
  s21_decimal num3 = {{0}};
  int error = s21_div(num1, num2, &num3);
  ck_assert_int_eq(error, 0);
}
END_TEST

Suite *suite_decimal_div() {
  Suite *suite = suite_create("suite_decimal_div");
  TCase *tcase = tcase_create("tcase_decimal_div");

  tcase_add_test(tcase, decimal_test_div_1);
  tcase_add_test(tcase, decimal_test_div_2);
  tcase_add_test(tcase, decimal_test_div_3);
  tcase_add_test(tcase, decimal_test_div_4);
  tcase_add_test(tcase, decimal_test_div_5);
  tcase_add_test(tcase, decimal_test_div_6);
  tcase_add_test(tcase, decimal_test_div_7);
  tcase_add_test(tcase, decimal_test_div_8);
  tcase_add_test(tcase, decimal_test_div_9);
  tcase_add_test(tcase, decimal_test_div_10);
  tcase_add_test(tcase, decimal_test_div_11);
  tcase_add_test(tcase, decimal_test_div_12);
  tcase_add_test(tcase, decimal_test_div_13);
  tcase_add_test(tcase, decimal_test_div_14);
  tcase_add_test(tcase, decimal_test_div_15);
  tcase_add_test(tcase, decimal_test_div_16);
  tcase_add_test(tcase, decimal_test_div_17);
  tcase_add_test(tcase, decimal_test_div_18);
  tcase_add_test(tcase, decimal_test_div_19);
  tcase_add_test(tcase, decimal_test_div_20);

  suite_add_tcase(suite, tcase);
  return suite;
}