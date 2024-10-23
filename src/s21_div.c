#include "s21_decimal.h"

int check_error_for_div(s21_decimal decl_1, s21_decimal decl_2,
                        s21_decimal *decl_res, int *res) {
  int pw1 = s21_get_power(decl_1);
  int pw2 = s21_get_power(decl_2);
  if (pw1 == 255 || pw2 == 255) {
    if (pw1 == 255) {
      if (s21_get_bit(decl_1, 127)) {
        *res = 2;
      } else {
        *res = 1;
      }
    } else {
      if (s21_get_bit(decl_2, 127)) {
        *res = 2;
      } else {
        *res = 1;
      }
    }
  } else if (pw1 > 28 || pw2 > 28) {
    *res = 2;
  } else if (!check_mantis(decl_2)) {
    decl_nul(decl_res, 0);
    *res = 3;
  } else if (!check_mantis(decl_1)) {
    decl_nul(decl_res, 0);
    *res = -1;
  }
  return *res;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // char aboba = 0;
  int res = 0;
  if (check_error_for_div(value_1, value_2, result, &res) == 0) {
    s21_decimal val_1 = value_1, val_2 = value_2;
    s21_set_bit(&val_1, 127, 0);
    s21_set_bit(&val_2, 127, 0);
    discarding_zeros(&val_1);
    discarding_zeros(&val_2);
    s21_decimal count = {0}, one = {{1, 0, 0, 0}};
    while (s21_is_greater_or_equal(val_1, val_2) == 1) {
      res = s21_sub(val_1, val_2, &val_1);
      s21_add(count, one, &count);
    }
    *result = count;
    s21_decimal temp_res = *result;
    while ((val_1.bits[0] != 0 || val_1.bits[1] != 0 || val_1.bits[2] != 0) &&
           res == 0) {
      decl_nul(&count, 0);
      int pw1 = s21_get_power(val_1);
      s21_decimal ten = {{10, 0, 0, 0}};
      if (pw1 > 0) {
        s21_set_power(&val_1, pw1 - 1);
        for (int i = 2; s21_is_less(val_1, val_2) == 1; ++i) {
          int pwr = s21_get_power(temp_res);
          res += s21_mul(temp_res, ten, &temp_res);
          s21_set_power(&temp_res, pwr + 1);
          s21_set_power(&val_1, pw1 - i);
        }
      } else {
        res += s21_mul(val_1, ten, &val_1);
        for (int i = 2; s21_is_less(val_1, val_2) == 1; ++i) {
          int pwr = s21_get_power(temp_res);
          res += s21_mul(val_1, ten, &val_1);
          res += s21_mul(temp_res, ten, &temp_res);
          s21_set_power(&temp_res, pwr + 1);
        }
      }
      while (s21_is_greater_or_equal(val_1, val_2) == 1) {
        res += s21_sub(val_1, val_2, &val_1);
        s21_add(count, one, &count);
      }
      int pwr = s21_get_power(temp_res);
      res += s21_mul(temp_res, ten, &temp_res);
      s21_set_power(&temp_res, 0);
      res += s21_add(temp_res, count, &temp_res);
      s21_set_power(&temp_res, pwr + 1);
      if (res != 0) {
        res = -1;
      } else {
        *result = temp_res;
      }
    }

    s21_set_bit(result, 127,
                s21_get_bit(value_1, 127) ^ s21_get_bit(value_2, 127));
  }
  if (res == -1) res = 0;
  return res;
}
