#include "s21_test.h"

START_TEST(comparators_1) {
  s21_decimal num1 = {{0, 0, 0, 0x00000000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_2) {
  s21_decimal num1 = {{0, 0, 0, 0x00020000}};
  s21_decimal num2 = {{0, 0, 0, 0x00020000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_3) {
  s21_decimal num1 = {{0, 0, 0, 0x80070000}};
  s21_decimal num2 = {{0, 0, 0, 0x00050000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_4) {
  s21_decimal num1 = {{0, 0, 0, 0x00000000}};
  s21_decimal num2 = {{0, 0, 0, 0x80000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_5) {
  s21_decimal num1 = {{1, 0, 0, 0x00000000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 0, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 1, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 0,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 1, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_6) {
  s21_decimal num1 = {{1, 0, 0, 0x001C0000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 0, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 1, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 0,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 1, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_7) {
  s21_decimal num1 = {{1, 0, 0, 0x80000000}};
  s21_decimal num2 = {{0, 0, 0, 0x00000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 0, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 1, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 1, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 0,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_8) {
  s21_decimal num1 = {{1, 1, 1, 0x00000000}};
  s21_decimal num2 = {{1, 1, 0, 0x00000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 0, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 1, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 0,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 1, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_9) {
  s21_decimal num1 = {{1, 1, 1, 0x00000000}};
  s21_decimal num2 = {{1, 1, 1, 0x00000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_10) {
  s21_decimal num1 = {{1234, 0, 0, 0x00000000}};
  s21_decimal num2 = {{1234, 0, 0, 0x00000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_11) {
  s21_decimal num1 = {{1234, 1234, 1234, 0x00000000}};
  s21_decimal num2 = {{1234, 1234, 1234, 0x00000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_12) {
  s21_decimal num1 = {{1234, 1234, 1234, 0x80000000}};
  s21_decimal num2 = {{1234, 1234, 1234, 0x80000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_13) {
  s21_decimal num1 = {{1234, 1234, 1234, 0x00090000}};
  s21_decimal num2 = {{1234, 1234, 1234, 0x00090000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_14) {
  s21_decimal num1 = {{1234, 1234, 1234, 0x80080000}};
  s21_decimal num2 = {{1234, 1234, 1234, 0x80080000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_15) {
  s21_decimal num1 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x00000000}};
  s21_decimal num2 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x00000000}};
  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_16) {
  s21_decimal num1 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x80000000}};
  s21_decimal num2 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x80000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_17) {
  s21_decimal num1 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x001C0000}};
  s21_decimal num2 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x001C0000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_18) {
  s21_decimal num1 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x00010000}};
  s21_decimal num2 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x00010000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_19) {
  s21_decimal num1 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x00010000}};
  s21_decimal num2 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x00020000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 0, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 1, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 0,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 1, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_20) {
  s21_decimal num1 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x00020000}};
  s21_decimal num2 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x80010000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 0, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 1, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 0,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 1, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_21) {
  s21_decimal num1 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x80080000}};
  s21_decimal num2 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x80090000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 0, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 1, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 1, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 0,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_22) {
  s21_decimal num1 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x00000000}};
  s21_decimal num2 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111110, 0x00000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 0, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 1, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 0,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 1, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_23) {
  s21_decimal num1 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x00000000}};
  s21_decimal num2 = {{0b01111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x00000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 0, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 1, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 0,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 1, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

START_TEST(comparators_24) {
  s21_decimal num1 = {{0b01111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111, 0x00000000}};
  s21_decimal num2 = {{0b11111111111111111111111111111111,
                       0b11111111111111111111111111111111,
                       0b11111111111111111111111111111110, 0x00000000}};

  ck_assert_msg(s21_is_equal(num1, num2) == 0, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 1, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 0,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 1, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST
START_TEST(comparators_25) {
  s21_decimal num1 = {{1, 0, 0, 0x00000001}};
  s21_decimal num2 = {{1, 0, 0, 0x00000001}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST
START_TEST(comparators_26) {
  s21_decimal num1 = {{1, 0, 0, 0x00000000}};
  s21_decimal num2 = {{1, 0, 0, 0x00000001}};

  ck_assert_msg(s21_is_equal(num1, num2) == 1, "s21_is_equal failed");
  ck_assert_msg(s21_is_not_equal(num1, num2) == 0, "s21_is_not_equal failed");
  ck_assert_msg(s21_is_less(num1, num2) == 0, "s21_is_less failed");
  ck_assert_msg(s21_is_less_or_equal(num1, num2) == 1,
                "s21_is_less_or_equal failed");
  ck_assert_msg(s21_is_greater(num1, num2) == 0, "s21_is_greater failed");
  ck_assert_msg(s21_is_greater_or_equal(num1, num2) == 1,
                "s21_is_greater_or_equal failed");
}
END_TEST

Suite *suite_comparators() {
  Suite *suite = suite_create("suite_comparators");
  TCase *tcase = tcase_create("tcase_comparators");

  tcase_add_test(tcase, comparators_1);
  tcase_add_test(tcase, comparators_2);
  tcase_add_test(tcase, comparators_3);
  tcase_add_test(tcase, comparators_4);
  tcase_add_test(tcase, comparators_5);
  tcase_add_test(tcase, comparators_6);
  tcase_add_test(tcase, comparators_7);
  tcase_add_test(tcase, comparators_8);
  tcase_add_test(tcase, comparators_9);
  tcase_add_test(tcase, comparators_10);
  tcase_add_test(tcase, comparators_11);
  tcase_add_test(tcase, comparators_12);
  tcase_add_test(tcase, comparators_13);
  tcase_add_test(tcase, comparators_14);
  tcase_add_test(tcase, comparators_15);
  tcase_add_test(tcase, comparators_16);
  tcase_add_test(tcase, comparators_17);
  tcase_add_test(tcase, comparators_18);
  tcase_add_test(tcase, comparators_19);
  tcase_add_test(tcase, comparators_20);
  tcase_add_test(tcase, comparators_21);
  tcase_add_test(tcase, comparators_22);
  tcase_add_test(tcase, comparators_23);
  tcase_add_test(tcase, comparators_24);
  tcase_add_test(tcase, comparators_25);
  tcase_add_test(tcase, comparators_26);

  suite_add_tcase(suite, tcase);

  return suite;
}