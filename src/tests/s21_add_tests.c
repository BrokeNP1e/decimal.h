#include "test.h"

// 0 и 0
START_TEST(test_add_1) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 15 и 0
START_TEST(test_add_2) {
  s21_decimal decimal_1 = {{15, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{15, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 0 и 76
START_TEST(test_add_3) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{76, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{76, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 12 и 80
START_TEST(test_add_4) {
  s21_decimal decimal_1 = {{12, 0, 0, 0}};

  s21_decimal decimal_2 = {{80, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{92, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 12 и -6
START_TEST(test_add_5) {
  s21_decimal decimal_1 = {{12, 0, 0, 0}};

  s21_decimal decimal_2 = {{6, 0, 0, 0x80000000}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{6, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//-20 и 15
START_TEST(test_add_6) {
  s21_decimal decimal_1 = {{20, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{15, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{5, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//-56 и -300
START_TEST(test_add_7) {
  s21_decimal decimal_1 = {{56, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{300, 0, 0, 0x80000000}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{356, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// мин и мин
START_TEST(test_add_8) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

// макс и макс
START_TEST(test_add_9) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 1);
}
END_TEST

// сум до макс впритык
START_TEST(test_add_10) {
  s21_decimal decimal_1 = {{0XFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// слишком больной рез
START_TEST(test_add_11) {
  s21_decimal decimal_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};

  s21_decimal decimal_2 = {{20, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 1);
}
END_TEST

// мак и мин
START_TEST(test_add_12) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// макс и 0,1
START_TEST(test_add_13) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  s21_decimal decimal_2 = {{1, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 0.3 0.4
START_TEST(test_add_14) {
  s21_decimal decimal_1 = {{3, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{4, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{7, 0, 0, 0}};
  s21_set_power(&result, 1);

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 1);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 1.2 0.8
START_TEST(test_add_15) {
  s21_decimal decimal_1 = {{12, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{8, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{20, 0, 0, 0}};
  s21_set_power(&result, 1);

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 1);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 6 0.9
START_TEST(test_add_16) {
  s21_decimal decimal_1 = {{6, 0, 0, 0}};

  s21_decimal decimal_2 = {{9, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{69, 0, 0, 0}};
  s21_set_power(&result, 1);

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 1);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 0.3 1.456
START_TEST(test_add_17) {
  s21_decimal decimal_1 = {{3, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{1456, 0, 0, 0}};
  s21_set_power(&decimal_2, 3);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1756, 0, 0, 0}};
  s21_set_power(&result, 3);

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 3);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// все инты
START_TEST(test_add_18) {
  s21_decimal decimal_1 = {{4536738, 66354, 764670, 0}};

  s21_decimal decimal_2 = {{1456, 2423, 3793542, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{4538194, 68777, 4558212, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 0.345 1
START_TEST(test_add_19) {
  s21_decimal decimal_1 = {{345, 0, 0, 0}};
  s21_set_power(&decimal_1, 3);

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1345, 0, 0, 0}};
  s21_set_power(&result, 3);

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 3);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST
// min min
START_TEST(test_add_20) {
  s21_decimal decimal_1 = {{23, 0, 0, 0x80000000}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

START_TEST(test_add_21) {
  s21_decimal decimal_1 = {{123, 0, 0, 0}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_power(&decimal_2, 255);
  s21_set_bit(&decimal_2, 127, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

START_TEST(test_add_22) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_power(&decimal_1, 255);
  s21_set_bit(&decimal_1, 127, 1);

  s21_decimal decimal_2 = {{123, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

START_TEST(test_add_23) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_power(&decimal_1, 255);

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 1);
}
END_TEST

START_TEST(test_add_24) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_power(&decimal_2, 255);
  s21_set_bit(&decimal_2, 127, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

START_TEST(test_add_25) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};
  s21_set_power(&decimal_1, 29);

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_add(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

Suite *init_suite_add() {
  Suite *suite = suite_create("add:");

  TCase *tcase_add = tcase_create("add");
  tcase_add_test(tcase_add, test_add_1);
  tcase_add_test(tcase_add, test_add_2);
  tcase_add_test(tcase_add, test_add_3);
  tcase_add_test(tcase_add, test_add_4);
  tcase_add_test(tcase_add, test_add_5);
  tcase_add_test(tcase_add, test_add_6);
  tcase_add_test(tcase_add, test_add_7);
  tcase_add_test(tcase_add, test_add_8);
  tcase_add_test(tcase_add, test_add_9);
  tcase_add_test(tcase_add, test_add_10);
  tcase_add_test(tcase_add, test_add_11);
  tcase_add_test(tcase_add, test_add_12);
  tcase_add_test(tcase_add, test_add_13);
  tcase_add_test(tcase_add, test_add_14);
  tcase_add_test(tcase_add, test_add_15);
  tcase_add_test(tcase_add, test_add_16);
  tcase_add_test(tcase_add, test_add_17);
  tcase_add_test(tcase_add, test_add_18);
  tcase_add_test(tcase_add, test_add_19);
  tcase_add_test(tcase_add, test_add_20);
  tcase_add_test(tcase_add, test_add_21);
  tcase_add_test(tcase_add, test_add_22);
  tcase_add_test(tcase_add, test_add_23);
  tcase_add_test(tcase_add, test_add_24);
  tcase_add_test(tcase_add, test_add_25);
  suite_add_tcase(suite, tcase_add);

  return suite;
}

int s21_test_add() {
  Suite *s = init_suite_add();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
