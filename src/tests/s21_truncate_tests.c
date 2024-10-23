#include "test.h"

//  1.1 / 1
START_TEST(test_truncate_1) {
  s21_decimal decimal = {{11, 0, 0, 0}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_truncate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 25.6 / 25
START_TEST(test_truncate_2) {
  s21_decimal decimal = {{256, 0, 0, 0}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{25, 0, 0, 0}};

  ck_assert_int_eq(s21_truncate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// -25.6 / -25
START_TEST(test_truncate_3) {
  s21_decimal decimal = {{256, 0, 0, 0x80000000}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{25, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_truncate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// -1.1 / -1
START_TEST(test_truncate_4) {
  s21_decimal decimal = {{11, 0, 0, 0x80000000}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_truncate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  0.1 / 0
START_TEST(test_truncate_5) {
  s21_decimal decimal = {{1, 0, 0, 0}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_truncate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  -0.1 / 0
START_TEST(test_truncate_6) {
  s21_decimal decimal = {{1, 0, 0, 0x80000000}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_truncate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// -25,000 / -25
START_TEST(test_truncate_7) {
  s21_decimal decimal = {{25000, 0, 0, 0x80000000}};
  s21_set_power(&decimal, 3);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{25, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_truncate(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(test_truncate_8) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_power(&decimal, 255);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_truncate(decimal, &decimal_res), 1);
}
END_TEST

Suite *init_suite_truncate() {
  Suite *suite = suite_create("truncate:");

  TCase *tcase_truncate = tcase_create("truncate");
  tcase_add_test(tcase_truncate, test_truncate_1);
  tcase_add_test(tcase_truncate, test_truncate_2);
  tcase_add_test(tcase_truncate, test_truncate_3);
  tcase_add_test(tcase_truncate, test_truncate_4);
  tcase_add_test(tcase_truncate, test_truncate_5);
  tcase_add_test(tcase_truncate, test_truncate_6);
  tcase_add_test(tcase_truncate, test_truncate_7);
  tcase_add_test(tcase_truncate, test_truncate_8);
  suite_add_tcase(suite, tcase_truncate);

  return suite;
}

int s21_test_truncate() {
  Suite *s = init_suite_truncate();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
