#include "test.h"

//  1.1 / 1
START_TEST(test_round_1) {
  s21_decimal decimal = {{11, 0, 0, 0}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_round(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 25.6 / 26
START_TEST(test_round_2) {
  s21_decimal decimal = {{256, 0, 0, 0}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{26, 0, 0, 0}};

  ck_assert_int_eq(s21_round(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// -25.6 / -26
START_TEST(test_round_3) {
  s21_decimal decimal = {{256, 0, 0, 0x80000000}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{26, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_round(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// -1.1 / -1
START_TEST(test_round_4) {
  s21_decimal decimal = {{11, 0, 0, 0x80000000}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_round(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  0.1 / 0
START_TEST(test_round_5) {
  s21_decimal decimal = {{1, 0, 0, 0}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_round(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  -0.1 / 0
START_TEST(test_round_6) {
  s21_decimal decimal = {{1, 0, 0, 0x80000000}};
  s21_set_power(&decimal, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_round(decimal, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(test_round_7) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_power(&decimal, 255);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_round(decimal, &decimal_res), 1);
}
END_TEST

Suite *init_suite_round() {
  Suite *suite = suite_create("round:");

  TCase *tcase_round = tcase_create("round");
  tcase_add_test(tcase_round, test_round_1);
  tcase_add_test(tcase_round, test_round_2);
  tcase_add_test(tcase_round, test_round_3);
  tcase_add_test(tcase_round, test_round_4);
  tcase_add_test(tcase_round, test_round_5);
  tcase_add_test(tcase_round, test_round_6);
  tcase_add_test(tcase_round, test_round_7);
  suite_add_tcase(suite, tcase_round);

  return suite;
}

int s21_test_round() {
  Suite *s = init_suite_round();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
