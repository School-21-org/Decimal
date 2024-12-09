#include "s21_test.h"

START_TEST(test_1) {
  s21_decimal num1 = {{0b11000000111001, 0, 0, 0x00030000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{0b1100, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_2) {
  s21_decimal num1 = {{54321, 0, 0, 0x80040000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{5, 0, 0, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_3) {
  s21_decimal num1 = {{1, 0, 0, 0x001c0000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_4) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_5) {
  s21_decimal num1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x801c0000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{8, 0, 0, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_6) {
  s21_decimal num1 = {{0xfffffffe, 0xfffffffe, 0xfffffffe, 0x001c0000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{8, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_7) {
  s21_decimal num1 = {{1, 1, 1, 0x80020000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{4166118277, 42949672, 0, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_8) {
  s21_decimal num1 = {{123456789, 0, 0, 0x80050000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{1235, 0, 0, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_9) {
  s21_decimal num1 = {{1, 1, 0, 0x80020000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{42949673, 0, 0, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_10) {
  s21_decimal num1 = {{19999, 0, 0, 0x00020000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{200, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_11) {
  s21_decimal num1 = {{123, 123, 123, 0x00030000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{2280627634, 528280977, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_12) {
  s21_decimal num1 = {{123456789, 0, 0, 0x80060000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{123, 0, 0, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_13) {
  s21_decimal num1 = {{0xFFFFFFFF, 0, 0, 0x00070000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{429, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_14) {
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0x800f0000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{18447, 0, 0, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_15) {
  s21_decimal num1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x00100000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{2896557602, 1844, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_16) {
  s21_decimal num1 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x001c0000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{8, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_17) {
  s21_decimal num1 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x801c0000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{8, 0, 0, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_18) {
  s21_decimal num1 = {{21, 31, 41, 0x80090000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{402263059, 176, 0, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_19) {
  s21_decimal num1 = {{9999999, 0, 0, 0x00070000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{1, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_20) {
  s21_decimal num1 = {{0, 1, 0, 0x00020000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{42949673, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_21) {
  s21_decimal num1 = {{9876500, 0, 0, 0x00060000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{10, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_22) {
  s21_decimal num1 = {{1234565, 0, 0, 0x80040000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{123, 0, 0, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_23) {
  s21_decimal num1 = {{999999, 0, 0, 0x001c0000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_24) {
  s21_decimal num1 = {{100, 100, 1000, 0x000f0000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{18446744, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_25) {
  s21_decimal num1 = {{0xffffffff, 0, 0xffffffff, 0x801a0000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{792, 0, 0, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_26) {
  s21_decimal num1 = {{0xfffffffe, 0xfffffffe, 0xfffffffe, 0x00140000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{792281625, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_27) {
  s21_decimal num1 = {{1, 1, 0xfffffffe, 0x80020000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{1073741824, 4037269258, 42949672, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_28) {
  s21_decimal num1 = {{123456789, 0, 0, 0x80090000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{0, 0, 0, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_29) {
  s21_decimal num1 = {{1, 0, 1, 0x80040000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{3133608139, 429496, 0, 0x80000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_30) {
  s21_decimal num1 = {{12983476, 0, 0, 0x00070000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{1, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_31) {
  s21_decimal num1 = {{1, 0, 1, 0x801E0000}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_32) {
  s21_decimal num1 = {{12983476, 0, 0, 0x11100001}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_33) {
  s21_decimal num1 = {{100000, 0, 0, 0x00050000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{1, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_34) {
  s21_decimal num1 = {{100000, 0, 0, 0x00050000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, NULL);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_35) {
  s21_decimal num1 = {{123351, 0, 0, 0x00020000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{1234, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_36) {
  s21_decimal num1 = {{123350, 0, 0, 0x00020000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{1234, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_37) {
  s21_decimal num1 = {{123450, 0, 0, 0x00020000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{1234, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_38) {
  s21_decimal num1 = {{12345123, 0, 0, 0x00040000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{1235, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_39) {
  s21_decimal num1 = {{12345, 0, 0, 0x00010000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{1234, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_40) {
  s21_decimal num1 = {{12341, 0, 0, 0x00010000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{1234, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_41) {
  s21_decimal num1 = {{1234123, 0, 0, 0x00030000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};
  s21_decimal test_num = {{1234, 0, 0, 0x00000000}};
  int error_code = s21_round(num1, &num2);
  ck_assert_msg(s21_is_equal(num2, test_num) == 1, "s21_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST

Suite *suite_round() {
  Suite *suite = suite_create("suite_round");
  TCase *tcase = tcase_create("tcase_round");

  tcase_add_test(tcase, test_1);
  tcase_add_test(tcase, test_2);
  tcase_add_test(tcase, test_3);
  tcase_add_test(tcase, test_4);
  tcase_add_test(tcase, test_5);
  tcase_add_test(tcase, test_6);
  tcase_add_test(tcase, test_7);
  tcase_add_test(tcase, test_8);
  tcase_add_test(tcase, test_9);
  tcase_add_test(tcase, test_10);
  tcase_add_test(tcase, test_11);
  tcase_add_test(tcase, test_12);
  tcase_add_test(tcase, test_13);
  tcase_add_test(tcase, test_14);
  tcase_add_test(tcase, test_15);
  tcase_add_test(tcase, test_16);
  tcase_add_test(tcase, test_17);
  tcase_add_test(tcase, test_18);
  tcase_add_test(tcase, test_19);
  tcase_add_test(tcase, test_20);
  tcase_add_test(tcase, test_21);
  tcase_add_test(tcase, test_22);
  tcase_add_test(tcase, test_23);
  tcase_add_test(tcase, test_24);
  tcase_add_test(tcase, test_25);
  tcase_add_test(tcase, test_26);
  tcase_add_test(tcase, test_27);
  tcase_add_test(tcase, test_28);
  tcase_add_test(tcase, test_29);
  tcase_add_test(tcase, test_30);
  tcase_add_test(tcase, test_31);
  tcase_add_test(tcase, test_32);
  tcase_add_test(tcase, test_33);
  tcase_add_test(tcase, test_34);
  tcase_add_test(tcase, test_35);
  tcase_add_test(tcase, test_36);
  tcase_add_test(tcase, test_37);
  tcase_add_test(tcase, test_38);
  tcase_add_test(tcase, test_39);
  tcase_add_test(tcase, test_40);
  tcase_add_test(tcase, test_41);

  suite_add_tcase(suite, tcase);
  return suite;
}