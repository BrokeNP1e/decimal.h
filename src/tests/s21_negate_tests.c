#include "test.h"

//  7 / -7
START_TEST(test_negate_1) {
  s21_decimal decimal = {{7, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{7, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_negate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  -7 / 7
START_TEST(test_negate_2) {
  s21_decimal decimal = {{7, 0, 0, 0x80000000}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{7, 0, 0, 0}};

  ck_assert_int_eq(s21_negate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 25.6 / -25.6
START_TEST(test_negate_3) {
  s21_decimal decimal = {{256, 0, 0, 0}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{256, 0, 0, 0x80000000}};
  s21_set_power(&result, 1);

  ck_assert_int_eq(s21_negate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// -25.6 / 25.6
START_TEST(test_negate_4) {
  s21_decimal decimal = {{256, 0, 0, 0x80000000}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{256, 0, 0, 0}};
  s21_set_power(&result, 1);

  ck_assert_int_eq(s21_negate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 0.1 / -0.1
START_TEST(test_negate_5) {
  s21_decimal decimal = {{1, 0, 0, 0}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1, 0, 0, 0x80000000}};
  s21_set_power(&result, 1);

  ck_assert_int_eq(s21_negate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  -0.1 / 0.1
START_TEST(test_negate_6) {
  s21_decimal decimal = {{1, 0, 0, 0x80000000}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1, 0, 0, 0}};
  s21_set_power(&result, 1);

  ck_assert_int_eq(s21_negate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  min / max
START_TEST(test_negate_7) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  ck_assert_int_eq(s21_negate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  max / min
START_TEST(test_negate_8) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  ck_assert_int_eq(s21_negate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(test_negate_9) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_power(&decimal, 255);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_negate(decimal, &decimal_res), 1);
}
END_TEST

Suite *init_suite_negate() {
  Suite *suite = suite_create("negate:");

  TCase *tcase_negate = tcase_create("negate");
  tcase_add_test(tcase_negate, test_negate_1);
  tcase_add_test(tcase_negate, test_negate_2);
  tcase_add_test(tcase_negate, test_negate_3);
  tcase_add_test(tcase_negate, test_negate_4);
  tcase_add_test(tcase_negate, test_negate_5);
  tcase_add_test(tcase_negate, test_negate_6);
  tcase_add_test(tcase_negate, test_negate_7);
  tcase_add_test(tcase_negate, test_negate_8);
  tcase_add_test(tcase_negate, test_negate_9);
  suite_add_tcase(suite, tcase_negate);

  return suite;
}

int s21_test_negate() {
  Suite *s = init_suite_negate();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
