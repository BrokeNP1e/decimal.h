
#include "test.h"

// 0 — FALSE;
// 1 — TRUE.

// 0 == 0 - true

// 0 ≥ 0 - true
START_TEST(s21_is_greater_or_equal_test0) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1 ≥ 0 - true
START_TEST(s21_is_greater_or_equal_test1) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 0 ≥ 1 - false
START_TEST(s21_is_greater_or_equal_test2) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 1 ≥ 1 - true
START_TEST(s21_is_greater_or_equal_test3) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// -1 ≥ 1 - false
START_TEST(s21_is_greater_or_equal_test4) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 1 ≥ -1 - true
START_TEST(s21_is_greater_or_equal_test5) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// -1 ≥ -1 - true
START_TEST(s21_is_greater_or_equal_test6) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// -1 ≥ 0 - false
START_TEST(s21_is_greater_or_equal_test7) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 0 ≥ -1 - true
START_TEST(s21_is_greater_or_equal_test8) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1.1 ≥ 1 - true
START_TEST(s21_is_greater_or_equal_test9) {
  s21_decimal decimal_1 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1 ≥ 1.1 - false
START_TEST(s21_is_greater_or_equal_test10) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 1.1 ≥ 1.3 - false
START_TEST(s21_is_greater_or_equal_test11) {
  s21_decimal decimal_1 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{13, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 1.3 ≥ 1.1 - true
START_TEST(s21_is_greater_or_equal_test12) {
  s21_decimal decimal_1 = {{40000, 0, 0, 0}};
  s21_set_power(&decimal_1, 0);

  s21_decimal decimal_2 = {{2, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test13) {
  s21_decimal decimal_1 = {{20, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{2, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_greater_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 0 == 0 - true
START_TEST(s21_is_equal_test0) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1 == 0 - false
START_TEST(s21_is_equal_test1) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 0 == 1 - false
START_TEST(s21_is_equal_test2) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 1 == 1 - true
START_TEST(s21_is_equal_test3) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 1);
}
END_TEST

// -1 == 1 - false
START_TEST(s21_is_equal_test4) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 1 == -1 - false
START_TEST(s21_is_equal_test5) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

// -1 == -1 - true
START_TEST(s21_is_equal_test6) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 1);
}
END_TEST

// -1 == 0 - false
START_TEST(s21_is_equal_test7) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 0 == -1 - false
START_TEST(s21_is_equal_test8) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 1.1 == 1 - false
START_TEST(s21_is_equal_test9) {
  s21_decimal decimal_1 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 1 == 1.1 - false
START_TEST(s21_is_equal_test10) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 1.1 == 1.3 - false
START_TEST(s21_is_equal_test11) {
  s21_decimal decimal_1 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{13, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 1.3 == 1.1 - false
START_TEST(s21_is_equal_test12) {
  s21_decimal decimal_1 = {{13, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_equal(decimal_1, decimal_2), 0);
}
END_TEST

// IS NOT EQUAL !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

START_TEST(s21_is_no_equal_test13) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 1 != 0 - true
START_TEST(s21_is_no_equal_test14) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 0 != 1 - true
START_TEST(s21_is_no_equal_test15) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1 != 1 - false
START_TEST(s21_is_no_equal_test16) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 0);
}
END_TEST

// -1 != 1 - true
START_TEST(s21_is_no_equal_test17) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1 != -1 - true
START_TEST(s21_is_no_equal_test18) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST

// -1 != -1 - false
START_TEST(s21_is_no_equal_test19) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 0);
}
END_TEST

// -1 != 0 - true
START_TEST(s21_is_no_equal_test20) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 0 != -1 - true
START_TEST(s21_is_no_equal_test21) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1.1 != 1 - true
START_TEST(s21_is_no_equal_test22) {
  s21_decimal decimal_1 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1 != 1.1 - true
START_TEST(s21_is_no_equal_test23) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1.1 != 1.3 - true
START_TEST(s21_is_no_equal_test24) {
  s21_decimal decimal_1 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{13, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1.3 != 1.1 - true
START_TEST(s21_is_no_equal_test25) {
  s21_decimal decimal_1 = {{13, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_not_equal(decimal_1, decimal_2), 1);
}
END_TEST
// 0 > 0 - false
START_TEST(s21_is_greater_test0) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

// 1 > 0 - true
START_TEST(s21_is_greater_test1) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 1);
}
END_TEST

// 0 > 1 - false
START_TEST(s21_is_greater_test2) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

// 1 > 1 - false
START_TEST(s21_is_greater_test3) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

// -1 > 1 - false
START_TEST(s21_is_greater_test4) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

// 1 > -1 - true
START_TEST(s21_is_greater_test5) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 1);
}
END_TEST

// -1 > -1 - false
START_TEST(s21_is_greater_test6) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

// -1 > 0 - false
START_TEST(s21_is_greater_test7) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

// 0 > -1 - true
START_TEST(s21_is_greater_test8) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 1);
}
END_TEST

// 1.1 > 1 - true
START_TEST(s21_is_greater_test9) {
  s21_decimal decimal_1 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 1);
}
END_TEST

// 1 > 1.1 - false
START_TEST(s21_is_greater_test10) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

// 1.1 > 1.3 - false
START_TEST(s21_is_greater_test11) {
  s21_decimal decimal_1 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{13, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 0);
}
END_TEST

// 1.3 > 1.1 - true
START_TEST(s21_is_greater_test12) {
  s21_decimal decimal_1 = {{13, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_greater(decimal_1, decimal_2), 1);
}
END_TEST

// 0 < 0 - false
START_TEST(s21_is_less_test0) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

// 1 < 0 - false
START_TEST(s21_is_less_test1) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

// 0 < 1 - true
START_TEST(s21_is_less_test2) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 1);
}
END_TEST

// 1 < 1 - false
START_TEST(s21_is_less_test3) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

// -1 < 1 - true
START_TEST(s21_is_less_test4) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 1);
}
END_TEST

// 1 < -1 - false
START_TEST(s21_is_less_test5) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

// -1 < -1 - false
START_TEST(s21_is_less_test6) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

// -1 < 0 - true
START_TEST(s21_is_less_test7) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 1);
}
END_TEST

// 0 < -1 - false
START_TEST(s21_is_less_test8) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

// 1.1 < 1 - false
START_TEST(s21_is_less_test9) {
  s21_decimal decimal_1 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 0);
}
END_TEST

// 1 < 1.1 - true
START_TEST(s21_is_less_test10) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 1);
}
END_TEST

// 1.1 < 1.3 - true
START_TEST(s21_is_less_test11) {
  s21_decimal decimal_1 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{13, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_less(decimal_1, decimal_2), 1);
}
END_TEST

// 0 ≤ 0 - true
START_TEST(s21_is_less_or_equal_test0) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1 ≤ 0 - false
START_TEST(s21_is_less_or_equal_test1) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 0 ≤ 1 - true
START_TEST(s21_is_less_or_equal_test2) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1 ≤ 1 - true
START_TEST(s21_is_less_or_equal_test3) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// -1 ≤ 1 - true
START_TEST(s21_is_less_or_equal_test4) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1 ≤ -1 - false
START_TEST(s21_is_less_or_equal_test5) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

// -1 ≤ -1 - true
START_TEST(s21_is_less_or_equal_test6) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// -1 ≤ 0 - true
START_TEST(s21_is_less_or_equal_test7) {
  s21_decimal decimal_1 = {{1, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 0 ≤ -1 - false
START_TEST(s21_is_less_or_equal_test8) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 1.1 ≤ 1 - false
START_TEST(s21_is_less_or_equal_test9) {
  s21_decimal decimal_1 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

// 1 ≤ 1.1 - true
START_TEST(s21_is_less_or_equal_test10) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};

  s21_decimal decimal_2 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1.1 ≤ 1.3 - true
START_TEST(s21_is_less_or_equal_test11) {
  s21_decimal decimal_1 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{13, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 1);
}
END_TEST

// 1.3 ≤ 1.1 - false
START_TEST(s21_is_less_or_equal_test12) {
  s21_decimal decimal_1 = {{13, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{11, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  ck_assert_int_eq(s21_is_less_or_equal(decimal_1, decimal_2), 0);
}
END_TEST

Suite *init_suite_comparison() {
  Suite *suite = suite_create("comparison:");

  TCase *tcase_comparison = tcase_create("comparison");
  tcase_add_test(tcase_comparison, s21_is_equal_test0);
  tcase_add_test(tcase_comparison, s21_is_equal_test1);
  tcase_add_test(tcase_comparison, s21_is_equal_test2);
  tcase_add_test(tcase_comparison, s21_is_equal_test3);
  tcase_add_test(tcase_comparison, s21_is_equal_test4);
  tcase_add_test(tcase_comparison, s21_is_equal_test5);
  tcase_add_test(tcase_comparison, s21_is_equal_test6);
  tcase_add_test(tcase_comparison, s21_is_equal_test7);
  tcase_add_test(tcase_comparison, s21_is_equal_test8);
  tcase_add_test(tcase_comparison, s21_is_equal_test9);
  tcase_add_test(tcase_comparison, s21_is_equal_test10);
  tcase_add_test(tcase_comparison, s21_is_equal_test11);
  tcase_add_test(tcase_comparison, s21_is_equal_test12);

  tcase_add_test(tcase_comparison, s21_is_no_equal_test13);
  tcase_add_test(tcase_comparison, s21_is_no_equal_test14);
  tcase_add_test(tcase_comparison, s21_is_no_equal_test15);
  tcase_add_test(tcase_comparison, s21_is_no_equal_test16);
  tcase_add_test(tcase_comparison, s21_is_no_equal_test17);
  tcase_add_test(tcase_comparison, s21_is_no_equal_test18);
  tcase_add_test(tcase_comparison, s21_is_no_equal_test19);
  tcase_add_test(tcase_comparison, s21_is_no_equal_test20);
  tcase_add_test(tcase_comparison, s21_is_no_equal_test21);
  tcase_add_test(tcase_comparison, s21_is_no_equal_test22);
  tcase_add_test(tcase_comparison, s21_is_no_equal_test23);
  tcase_add_test(tcase_comparison, s21_is_no_equal_test24);
  tcase_add_test(tcase_comparison, s21_is_no_equal_test25);

  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test0);
  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test1);
  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test2);
  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test3);
  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test4);
  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test5);
  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test6);
  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test7);
  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test8);
  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test9);
  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test10);
  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test11);
  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test12);
  tcase_add_test(tcase_comparison, s21_is_greater_or_equal_test13);

  tcase_add_test(tcase_comparison, s21_is_greater_test0);
  tcase_add_test(tcase_comparison, s21_is_greater_test1);
  tcase_add_test(tcase_comparison, s21_is_greater_test2);
  tcase_add_test(tcase_comparison, s21_is_greater_test3);
  tcase_add_test(tcase_comparison, s21_is_greater_test4);
  tcase_add_test(tcase_comparison, s21_is_greater_test5);
  tcase_add_test(tcase_comparison, s21_is_greater_test6);
  tcase_add_test(tcase_comparison, s21_is_greater_test7);
  tcase_add_test(tcase_comparison, s21_is_greater_test8);
  tcase_add_test(tcase_comparison, s21_is_greater_test9);
  tcase_add_test(tcase_comparison, s21_is_greater_test10);
  tcase_add_test(tcase_comparison, s21_is_greater_test11);
  tcase_add_test(tcase_comparison, s21_is_greater_test12);

  tcase_add_test(tcase_comparison, s21_is_less_test0);
  tcase_add_test(tcase_comparison, s21_is_less_test1);
  tcase_add_test(tcase_comparison, s21_is_less_test2);
  tcase_add_test(tcase_comparison, s21_is_less_test3);
  tcase_add_test(tcase_comparison, s21_is_less_test4);
  tcase_add_test(tcase_comparison, s21_is_less_test5);
  tcase_add_test(tcase_comparison, s21_is_less_test6);
  tcase_add_test(tcase_comparison, s21_is_less_test7);
  tcase_add_test(tcase_comparison, s21_is_less_test8);
  tcase_add_test(tcase_comparison, s21_is_less_test9);
  tcase_add_test(tcase_comparison, s21_is_less_test10);
  tcase_add_test(tcase_comparison, s21_is_less_test11);

  tcase_add_test(tcase_comparison, s21_is_less_or_equal_test0);
  tcase_add_test(tcase_comparison, s21_is_less_or_equal_test1);
  tcase_add_test(tcase_comparison, s21_is_less_or_equal_test2);
  tcase_add_test(tcase_comparison, s21_is_less_or_equal_test3);
  tcase_add_test(tcase_comparison, s21_is_less_or_equal_test4);
  tcase_add_test(tcase_comparison, s21_is_less_or_equal_test5);
  tcase_add_test(tcase_comparison, s21_is_less_or_equal_test6);
  tcase_add_test(tcase_comparison, s21_is_less_or_equal_test7);
  tcase_add_test(tcase_comparison, s21_is_less_or_equal_test8);
  tcase_add_test(tcase_comparison, s21_is_less_or_equal_test9);
  tcase_add_test(tcase_comparison, s21_is_less_or_equal_test10);
  tcase_add_test(tcase_comparison, s21_is_less_or_equal_test11);
  tcase_add_test(tcase_comparison, s21_is_less_or_equal_test12);

  suite_add_tcase(suite, tcase_comparison);

  return suite;
}

int s21_test_comparison() {
  Suite *s = init_suite_comparison();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
