#include "test.h"

// 4 / 2 = 2
START_TEST(test_div_1) {
  s21_decimal decimal_1 = {{4, 0, 0, 0}};

  s21_decimal decimal_2 = {{2, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{2, 0, 0, 0}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 256 / 2 = 128
START_TEST(test_div_2) {
  s21_decimal decimal_1 = {{256, 0, 0, 0}};

  s21_decimal decimal_2 = {{2, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{128, 0, 0, 0}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 256 / 256 = 1
START_TEST(test_div_3) {
  s21_decimal decimal_1 = {{256, 0, 0, 0}};

  s21_decimal decimal_2 = {{256, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1, 0, 0, 0}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  256 / 0 = error
START_TEST(test_div_4) {
  s21_decimal decimal_1 = {{256, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 3);
}
END_TEST

//  0 / 0 = error
START_TEST(test_div_5) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 3);
}
END_TEST

// min / 0.2 = error (too little)
/*START_TEST(test_div_6) {
     s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
     0x80000000}};

     s21_decimal decimal_2 = {{2, 0, 0, 0}};
     s21_set_power(&decimal_2, 1);

     s21_decimal decimal_res = {{0, 0, 0, 0}};

     ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 2);
 }
 END_TEST

//  max / 0.2 = error (too much)
START_TEST(test_div_7) {
     s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

     s21_decimal decimal_2 = {{2, 0, 0, 0}};
     s21_set_power(&decimal_2, 1);

     s21_decimal decimal_res = {{0, 0, 0, 0}};
     ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 1);
 }
 END_TEST*/

// 0.6 / 0.3 = 2
START_TEST(test_div_8) {
  s21_decimal decimal_1 = {{6, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{3, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{2, 0, 0, 0}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 0.66 / 2 = 0.33
START_TEST(test_div_9) {
  s21_decimal decimal_1 = {{66, 0, 0, 0}};
  s21_set_power(&decimal_1, 2);

  s21_decimal decimal_2 = {{2, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{33, 0, 0, 0}};
  s21_set_power(&result, 2);

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 2);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// -0.6 / 0.3 = -2
START_TEST(test_div_10) {
  s21_decimal decimal_1 = {{6, 0, 0, 0x80000000}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{3, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{2, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 0.6 / (-0.3) = -2
START_TEST(test_div_11) {
  s21_decimal decimal_1 = {{6, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{3, 0, 0, 0x80000000}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{2, 0, 0, 0x80000000}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// -0.6 / (-0.3) = 2
START_TEST(test_div_12) {
  s21_decimal decimal_1 = {{6, 0, 0, 0x80000000}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{3, 0, 0, 0x80000000}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{2, 0, 0, 0}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

//  1.2 / 4 = 0.3
START_TEST(test_div_13) {
  s21_decimal decimal_1 = {{12, 0, 0, 0}};
  s21_set_power(&decimal_1, 1);

  s21_decimal decimal_2 = {{4, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{3, 0, 0, 0}};
  s21_set_power(&result, 1);

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 0);
  ck_assert_int_eq(s21_get_power(decimal_res), 1);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST
// 0 / 2
START_TEST(test_div_14) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{2, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST
// 100 33
START_TEST(test_div_15) {
  s21_decimal decimal_1 = {{100, 0, 0, 0}};

  s21_decimal decimal_2 = {{3, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {0};
  input_bit_decl(&result,
                 "0110101110110100101011111110010011001111001001100000011111101"
                 "11000110101010101010101010101010101");
  s21_set_power(&result, 27);

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

// 16.598 16
START_TEST(test_div_16) {
  s21_decimal decimal_1 = {{16598, 0, 0, 0}};
  s21_set_power(&decimal_1, 3);

  s21_decimal decimal_2 = {{16, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  s21_decimal result = {{1037375, 0, 0, 0}};
  s21_set_power(&result, 6);

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(test_div_18) {
  s21_decimal decimal_1 = {{123, 0, 0, 0}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_power(&decimal_2, 255);
  s21_set_bit(&decimal_2, 127, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

START_TEST(test_div_19) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_power(&decimal_1, 255);
  s21_set_bit(&decimal_1, 127, 1);

  s21_decimal decimal_2 = {{123, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

START_TEST(test_div_20) {
  s21_decimal decimal_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_power(&decimal_1, 255);

  s21_decimal decimal_2 = {{0, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 1);
}
END_TEST

START_TEST(test_div_21) {
  s21_decimal decimal_1 = {{0, 0, 0, 0}};

  s21_decimal decimal_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_power(&decimal_2, 255);
  s21_set_bit(&decimal_2, 127, 1);

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

START_TEST(test_div_22) {
  s21_decimal decimal_1 = {{1, 0, 0, 0}};
  s21_set_power(&decimal_1, 29);

  s21_decimal decimal_2 = {{1, 0, 0, 0}};

  s21_decimal decimal_res = {{0, 0, 0, 0}};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &decimal_res), 2);
}
END_TEST

// 21 0.3
START_TEST(test_div_23) {
  s21_decimal decimal_1 = {{21, 0, 0, 0}};

  s21_decimal decimal_2 = {{3, 0, 0, 0}};
  s21_set_power(&decimal_2, 1);

  s21_decimal decimal_res = {{70, 0, 0, 0}};

  s21_decimal result = {0};

  ck_assert_int_eq(s21_div(decimal_1, decimal_2, &result), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(decimal_res.bits[i], result.bits[i]);
  }
}
END_TEST

Suite *init_suite_div() {
  Suite *suite = suite_create("div:");

  TCase *tcase_div = tcase_create("div");
  tcase_add_test(tcase_div, test_div_1);
  tcase_add_test(tcase_div, test_div_2);
  tcase_add_test(tcase_div, test_div_3);
  tcase_add_test(tcase_div, test_div_4);
  tcase_add_test(tcase_div, test_div_5);
  // tcase_add_test(tcase_div, test_div_6);
  // tcase_add_test(tcase_div, test_div_7);
  tcase_add_test(tcase_div, test_div_8);
  tcase_add_test(tcase_div, test_div_9);
  tcase_add_test(tcase_div, test_div_10);
  tcase_add_test(tcase_div, test_div_11);
  tcase_add_test(tcase_div, test_div_12);
  tcase_add_test(tcase_div, test_div_13);
  tcase_add_test(tcase_div, test_div_14);
  tcase_add_test(tcase_div, test_div_15);
  tcase_add_test(tcase_div, test_div_16);
  // tcase_add_test(tcase_div, test_div_17);
  tcase_add_test(tcase_div, test_div_18);
  tcase_add_test(tcase_div, test_div_19);
  tcase_add_test(tcase_div, test_div_20);
  tcase_add_test(tcase_div, test_div_21);
  tcase_add_test(tcase_div, test_div_22);
  tcase_add_test(tcase_div, test_div_23);
  suite_add_tcase(suite, tcase_div);

  return suite;
}

int s21_test_div() {
  Suite *s = init_suite_div();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
