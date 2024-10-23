#include "test.h"

// 0 - 0
START_TEST(test_sub_1) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 7 - 0 = 7
START_TEST(test_sub_2) {
  s21_decimal decimal_1 = {{7, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{7, 0, 0, 0}};

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 0 - 7 = -7
START_TEST(test_sub_3) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{7, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{7, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  256 - 256 = 0
START_TEST(test_sub_4) {
  s21_decimal decimal_1 = {{256, 0, 0, 0}};

  s21_decimal decimal_2 = {{256, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  6 -(-6) = 12
START_TEST(test_sub_5) {
  s21_decimal decimal_1 = {{6, 0, 0, 0}};

  s21_decimal decimal_2 = {{6, 0, 0, 0x80000000}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{12, 0, 0, 0}};

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  -12 -(-6) = -6
START_TEST(test_sub_6) {
  s21_decimal decimal_1 = {{12, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{6, 0, 0, 0x80000000}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{6, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  -6 -(-6) = 0
START_TEST(test_sub_7) {
  s21_decimal decimal_1 = {{6, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{6, 0, 0, 0x80000000}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// min - min = 0
START_TEST(test_sub_8) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);
}
END_TEST

// max - max = 0
START_TEST(test_sub_9) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);
}
END_TEST

// min - max = error (too little)
START_TEST(test_sub_10) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

// max - min = error (too much)
START_TEST(test_sub_11) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 1);
}
END_TEST

// 1.2 - 0.6 = 0.6
START_TEST(test_sub_12) {
  s21_decimal decimal_1 = {{12, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{6, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{6, 0, 0, 0}};
  s21_set_power(&result, 1);

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 1);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  1.2 -(-0.6) = 1.8
START_TEST(test_sub_13) {
  s21_decimal decimal_1 = {{12, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{6, 0, 0, 0x80000000}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{18, 0, 0, 0}};
  s21_set_power(&result, 1);

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 1);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  0.3 - 1.456 = -1.156
START_TEST(test_sub_14) {
  s21_decimal decimal_1 = {{3, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{1456, 0, 0, 0}};
  s21_set_power(&decimal_2, 3);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1156, 0, 0, 0x80000000}};
  s21_set_power(&result, 3);

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 3);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(test_sub_15) {
  s21_decimal decimal_1 = {{3, 0, 0, 0}};
  s21_set_power(&decimal_1, 2);

  s21_decimal decimal_2 = {{1456, 0, 0, 0}};
  s21_set_power(&decimal_2, 3);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1426, 0, 0, 0x80000000}};
  s21_set_power(&result, 3);

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 3);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  -0.03 - (-1.456) = 1.426
START_TEST(test_sub_16) {
  s21_decimal decimal_1 = {{3, 0, 0, 0x80000000}};
  s21_set_power(&decimal_1, 2);

  s21_decimal decimal_2 = {{1456, 0, 0, 0x80000000}};
  s21_set_power(&decimal_2, 3);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1426, 0, 0, 0}};
  s21_set_power(&result, 3);

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 3);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  -0.03 - 1.456 = 1.426
START_TEST(test_sub_17) {
  s21_decimal decimal_1 = {{3, 0, 0, 0x80000000}};
  s21_set_power(&decimal_1, 2);

  s21_decimal decimal_2 = {{1456, 0, 0, 0}};
  s21_set_power(&decimal_2, 3);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1486, 0, 0, 0x80000000}};
  s21_set_power(&result, 3);

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 3);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  -0.03 - 1.456 = 1.426
START_TEST(test_sub_18) {
  s21_decimal decimal_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
  s21_set_power(&decimal_1, 0);

  s21_decimal decimal_2 = {{14, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0xfffffffe, 0xffffffff, 0xffffffff, 0}};
  s21_set_power(&result, 0);

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(test_sub_19) {
  s21_decimal decimal_1 = {{15, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{1, 0, 0, 0}};
  s21_set_power(&decimal_2, 0);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{5, 0, 0, 0}};
  s21_set_power(&result, 1);

  ck_assert_int_eq(s21_sub(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 1);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

Suite *init_suite_sub() {
  Suite *suite = suite_create("sub:");

  TCase *tcase_sub = tcase_create("sub");
  tcase_add_test(tcase_sub, test_sub_1);
  tcase_add_test(tcase_sub, test_sub_2);
  tcase_add_test(tcase_sub, test_sub_3);
  tcase_add_test(tcase_sub, test_sub_4);
  tcase_add_test(tcase_sub, test_sub_5);
  tcase_add_test(tcase_sub, test_sub_6);
  tcase_add_test(tcase_sub, test_sub_7);
  tcase_add_test(tcase_sub, test_sub_8);
  tcase_add_test(tcase_sub, test_sub_9);
  tcase_add_test(tcase_sub, test_sub_10);
  tcase_add_test(tcase_sub, test_sub_11);
  tcase_add_test(tcase_sub, test_sub_12);
  tcase_add_test(tcase_sub, test_sub_13);
  tcase_add_test(tcase_sub, test_sub_14);
  tcase_add_test(tcase_sub, test_sub_15);
  tcase_add_test(tcase_sub, test_sub_16);
  tcase_add_test(tcase_sub, test_sub_17);
  tcase_add_test(tcase_sub, test_sub_18);
  tcase_add_test(tcase_sub, test_sub_19);
  suite_add_tcase(suite, tcase_sub);

  return suite;
}

int s21_test_sub() {
  Suite *s = init_suite_sub();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
