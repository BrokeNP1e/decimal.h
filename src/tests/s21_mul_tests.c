#include "test.h"

// 0 0
START_TEST(test_mul_1) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 3 0
START_TEST(test_mul_2) {
  s21_decimal decimal_1 = {{3, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 0 5
START_TEST(test_mul_3) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{5, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 4 5
START_TEST(test_mul_4) {
  s21_decimal decimal_1 = {{4, 0, 0, 0}};

  s21_decimal decimal_2 = {{5, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{20, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 12 0.3
START_TEST(test_mul_5) {
  s21_decimal decimal_1 = {{12, 0, 0, 0}};

  s21_decimal decimal_2 = {{3, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{36, 0, 0, 0}};
  s21_set_power(&result, 1);

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 1);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 1.2 0.2
START_TEST(test_mul_6) {
  s21_decimal decimal_1 = {{12, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{2, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{24, 0, 0, 0}};
  s21_set_power(&result, 2);

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 2);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// max 2
START_TEST(test_mul_7) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal decimal_2 = {{2, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 1);
}
END_TEST

// min 2
START_TEST(test_mul_8) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal decimal_2 = {{2, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

//-2 -6
START_TEST(test_mul_9) {
  s21_decimal decimal_1 = {{2, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{6, 0, 0, 0x80000000}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{12, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 3 -9
START_TEST(test_mul_10) {
  s21_decimal decimal_1 = {{3, 0, 0, 0}};

  s21_decimal decimal_2 = {{9, 0, 0, 0x80000000}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{27, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//-8 4
START_TEST(test_mul_11) {
  s21_decimal decimal_1 = {{8, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{4, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{32, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//-0.9 0.2
START_TEST(test_mul_12) {
  s21_decimal decimal_1 = {{9, 0, 0, 0x80000000}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{2, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{18, 0, 0, 0x80000000}};
  s21_set_power(&result, 2);

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 2);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//-0.6 -0.2
START_TEST(test_mul_13) {
  s21_decimal decimal_1 = {{6, 0, 0, 0x80000000}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{2, 0, 0, 0x80000000}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{12, 0, 0, 0}};
  s21_set_power(&result, 2);

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 2);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(test_mul_14) {
  s21_decimal decimal_1 = {{654, 0, 0, 0}};

  s21_decimal decimal_2 = {{23, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{15042, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// оч маленькие
START_TEST(test_mul_15) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};
  s21_set_power(&decimal_1, 28);

  s21_decimal decimal_2 = {{1, 0, 0, 0}};
  s21_set_power(&decimal_2, 28);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

START_TEST(test_mul_16) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

START_TEST(test_mul_17) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 1);
}
END_TEST

START_TEST(test_mul_18) {
  s21_decimal decimal_1 = {{654, 0, 0, 0}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_power(&decimal_2, 255);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 1);
}
END_TEST

START_TEST(test_mul_19) {
  s21_decimal decimal_1 = {{654, 0, 0, 0}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_power(&decimal_2, 255);
  s21_set_bit(&decimal_2, 127, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

START_TEST(test_mul_20) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};
  s21_set_power(&decimal_1, 29);

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_mul(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST
Suite *init_suite_mul() {
  Suite *suite = suite_create("mul:");

  TCase *tcase_mul = tcase_create("mul");
  tcase_add_test(tcase_mul, test_mul_1);
  tcase_add_test(tcase_mul, test_mul_2);
  tcase_add_test(tcase_mul, test_mul_3);
  tcase_add_test(tcase_mul, test_mul_4);
  tcase_add_test(tcase_mul, test_mul_5);
  tcase_add_test(tcase_mul, test_mul_6);
  tcase_add_test(tcase_mul, test_mul_7);
  tcase_add_test(tcase_mul, test_mul_8);
  tcase_add_test(tcase_mul, test_mul_9);
  tcase_add_test(tcase_mul, test_mul_10);
  tcase_add_test(tcase_mul, test_mul_11);
  tcase_add_test(tcase_mul, test_mul_12);
  tcase_add_test(tcase_mul, test_mul_13);
  tcase_add_test(tcase_mul, test_mul_14);
  tcase_add_test(tcase_mul, test_mul_15);
  tcase_add_test(tcase_mul, test_mul_16);
  tcase_add_test(tcase_mul, test_mul_17);
  tcase_add_test(tcase_mul, test_mul_18);
  tcase_add_test(tcase_mul, test_mul_19);
  tcase_add_test(tcase_mul, test_mul_20);
  suite_add_tcase(suite, tcase_mul);

  return suite;
}

int s21_test_mul() {
  Suite *s = init_suite_mul();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
