#include "test.h"

START_TEST(int_and_decimal_test_1) {
  int x = 256;
  s21_decimal decimal = {{0, 0, 0, 0}};
  int y = 0;
  int res_1 = s21_from_int_to_decimal(x, &decimal);
  int res_2 = s21_from_decimal_to_int(decimal, &y);
  ck_assert_int_eq(x, y);
  ck_assert_int_eq(res_1, 0);
  ck_assert_int_eq(res_2, 0);
}
END_TEST

START_TEST(int_and_decimal_test_2) {
  int x = 0;
  s21_decimal decimal = {{0, 0, 0, 0}};
  int y = 456383874;
  int res_1 = s21_from_int_to_decimal(x, &decimal);
  int res_2 = s21_from_decimal_to_int(decimal, &y);
  ck_assert_int_eq(x, y);
  ck_assert_int_eq(res_1, 0);
  ck_assert_int_eq(res_2, 0);
}
END_TEST

START_TEST(int_and_decimal_test_3) {
  int x = 7866759;
  s21_decimal decimal = {{0, 0, 0, 0}};
  int y = -5657;
  int res_1 = s21_from_int_to_decimal(x, &decimal);
  int res_2 = s21_from_decimal_to_int(decimal, &y);
  ck_assert_int_eq(x, y);
  ck_assert_int_eq(res_1, 0);
  ck_assert_int_eq(res_2, 0);
}
END_TEST

START_TEST(int_and_decimal_test_4) {
  int x = -9011;
  s21_decimal decimal = {{0, 0, 0, 0}};
  int y = 678;
  int res_1 = s21_from_int_to_decimal(x, &decimal);
  int res_2 = s21_from_decimal_to_int(decimal, &y);
  ck_assert_int_eq(x, y);
  ck_assert_int_eq(res_1, 0);
  ck_assert_int_eq(res_2, 0);
}
END_TEST

START_TEST(int_and_decimal_test_5) {
  int x = 3591;
  s21_decimal decimal = {{256, 375, 291, 0x80000000}};
  int y = 390;
  int res_1 = s21_from_int_to_decimal(x, &decimal);
  int res_2 = s21_from_decimal_to_int(decimal, &y);
  ck_assert_int_eq(x, y);
  ck_assert_int_eq(res_1, 0);
  ck_assert_int_eq(res_2, 0);
}
END_TEST

START_TEST(float_and_decimal_test_6) {
  float x = 345.0;
  s21_decimal decimal = {{0, 0, 0, 0}};
  float y = -45.9865336;
  int res_1 = s21_from_float_to_decimal(x, &decimal);
  int res_2 = s21_from_decimal_to_float(decimal, &y);
  ck_assert_float_eq(x, y);
  ck_assert_int_eq(res_1, 0);
  ck_assert_int_eq(res_2, 0);
}
END_TEST

START_TEST(float_and_decimal_test_7) {
  float x = 12.5;
  s21_decimal decimal = {{0, 0, 0, 0}};
  float y = 256.0;
  int res_1 = s21_from_float_to_decimal(x, &decimal);
  int res_2 = s21_from_decimal_to_float(decimal, &y);
  ck_assert_float_eq(x, y);
  ck_assert_int_eq(res_1, 0);
  ck_assert_int_eq(res_2, 0);
}
END_TEST

START_TEST(float_and_decimal_test_8) {
  float x = 0.0000000000001;
  s21_decimal decimal = {{0, 0, 0, 0}};
  float y = -9876.1;
  int res_1 = s21_from_float_to_decimal(x, &decimal);
  int res_2 = s21_from_decimal_to_float(decimal, &y);
  ck_assert_float_eq(x, y);
  ck_assert_int_eq(res_1, 0);
  ck_assert_int_eq(res_2, 0);
}
END_TEST

START_TEST(float_and_decimal_test_9) {
  float x = -56749.65;
  s21_decimal decimal = {{0, 0, 0, 0}};
  float y = -132324.677483901;
  int res_1 = s21_from_float_to_decimal(x, &decimal);
  int res_2 = s21_from_decimal_to_float(decimal, &y);
  ck_assert_float_eq(x, y);
  ck_assert_int_eq(res_1, 0);
  ck_assert_int_eq(res_2, 0);
}
END_TEST

START_TEST(float_and_decimal_test_10) {
  float x = 93.957454;
  s21_decimal decimal = {{5673, 0, 0, 0}};
  s21_set_power(&decimal, 12);
  float y = 12.5;
  int res_1 = s21_from_float_to_decimal(x, &decimal);
  int res_2 = s21_from_decimal_to_float(decimal, &y);
  ck_assert_float_eq(x, y);
  ck_assert_int_eq(res_1, 0);
  ck_assert_int_eq(res_2, 0);
}
END_TEST

START_TEST(int_and_decimal_test_11) {
  s21_decimal decimal = {{873242374, 327648764, 2337287, 0}};
  int y = 0;
  int res = s21_from_decimal_to_int(decimal, &y);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(int_and_decimal_test_12) {
  s21_decimal decimal = {{87242374, 0, 0, 0}};
  s21_set_power(&decimal, 2);
  int y = 0;
  int res = s21_from_decimal_to_int(decimal, &y);
  ck_assert_int_eq(872423, y);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(float_and_decimal_test_13) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  float y = 0;
  float x = 0;
  int res = s21_from_decimal_to_float(decimal, &y);
  ck_assert_float_eq(x, y);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(int_and_decimal_test_14) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int y = 0;
  int res = s21_from_decimal_to_int(decimal, &y);
  ck_assert_int_eq(0, y);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(float_and_decimal_test_15) {
  float y = 0.0000000000123;
  s21_decimal decimal = {{0, 0, 0, 0}};
  int res = s21_from_float_to_decimal(y, &decimal);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(float_and_decimal_test_16) {
  float y = -979228162514264337593543950335.0f;
  s21_decimal decimal = {{0, 0, 0, 0}};
  int res = s21_from_float_to_decimal(y, &decimal);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(float_and_decimal_test_17) {
  float y = 7593543950335.00000000000000000456;
  s21_decimal decimal = {{0, 0, 0, 0}};
  float x = 7593543950335.00000000000000000456;
  int res = s21_from_float_to_decimal(y, &decimal);
  s21_from_decimal_to_float(decimal, &x);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(x, y);
}
END_TEST

Suite *init_suite_convertes() {
  Suite *suite = suite_create("convertes:");

  TCase *tcase_convertes = tcase_create("convertes");
  tcase_add_test(tcase_convertes, int_and_decimal_test_1);
  tcase_add_test(tcase_convertes, int_and_decimal_test_2);
  tcase_add_test(tcase_convertes, int_and_decimal_test_3);
  tcase_add_test(tcase_convertes, int_and_decimal_test_4);
  tcase_add_test(tcase_convertes, int_and_decimal_test_5);
  tcase_add_test(tcase_convertes, float_and_decimal_test_6);
  tcase_add_test(tcase_convertes, float_and_decimal_test_7);
  tcase_add_test(tcase_convertes, float_and_decimal_test_8);
  tcase_add_test(tcase_convertes, float_and_decimal_test_9);
  tcase_add_test(tcase_convertes, float_and_decimal_test_10);
  tcase_add_test(tcase_convertes, int_and_decimal_test_11);
  tcase_add_test(tcase_convertes, int_and_decimal_test_12);
  tcase_add_test(tcase_convertes, float_and_decimal_test_13);
  tcase_add_test(tcase_convertes, int_and_decimal_test_14);
  tcase_add_test(tcase_convertes, float_and_decimal_test_15);
  tcase_add_test(tcase_convertes, float_and_decimal_test_16);
  tcase_add_test(tcase_convertes, float_and_decimal_test_17);
  suite_add_tcase(suite, tcase_convertes);

  return suite;
}

int s21_test_convertes() {
  Suite *s = init_suite_convertes();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}

// не понятно в каких случаях ошибки могут быть