#include "s21_decimal.h"

void alg_sum(s21_decimal *decl_res, int *temp, int sum, int i) {
  *temp = 0;
  if (sum == 0) {
    s21_set_bit(decl_res, i, 0);
  } else if (sum == 1) {
    s21_set_bit(decl_res, i, 1);
  } else if (sum == 2) {
    s21_set_bit(decl_res, i, 0);
    *temp = 1;
  } else {
    s21_set_bit(decl_res, i, 1);
    *temp = 1;
  }
}

int s21_dec_sum(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0, temp = 0;
  for (int i = 0; i <= 95 && res == 0; ++i) {
    int sum = s21_get_bit(value_1, i) + s21_get_bit(value_2, i) + temp;
    alg_sum(result, &temp, sum, i);
    if (i == 95 && temp != 0) {
      if (s21_get_bit(*result, 127)) {
        res = 2;
      } else {
        res = 1;
      }
    }
  }
  return res;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  if (check_error(value_1, value_2, result, &res) == 0 && result != NULL &&
      !decl_error(value_1) && !decl_error(value_2)) {
    decl_nul(result, 0);
    if (s21_get_bit(value_1, 127) != s21_get_bit(value_2, 127)) {
      s21_set_bit(&value_2, 127, !s21_get_bit(value_2, 127));
      res = s21_sub(value_1, value_2, result);
    } else {
      int temp = 0, check = 0;
      int pw1 = s21_get_power(value_1), pw2 = s21_get_power(value_2);
      if (pw1 > pw2) {
        power_switch(&value_1, &value_2);
      }
      pw1 = s21_get_power(value_1), pw2 = s21_get_power(value_2);
      *result = value_1;
      s21_decimal temp_decl = *result;
      power_work(pw1, pw2, &check, value_1, result, &temp_decl);
      if (check != 0) {
        s21_set_power(&value_2, (pw2 - (check / 10)));
        s21_truncate(value_2, &temp_decl);
      } else {
        temp_decl = value_2;
      }
      for (int i = 0; i <= 95 && res == 0; ++i) {
        int sum = s21_get_bit(*result, i) + s21_get_bit(temp_decl, i) + temp;
        alg_sum(result, &temp, sum, i);
        if (i == 95 && temp != 0) {
          if (s21_get_bit(*result, 127)) {
            res = 2;
          } else {
            res = 1;
          }
        }
      }
    }
    if (result->bits[0] == 0 && result->bits[1] == 0 && result->bits[2] == 0) {
      s21_set_bit(result, 127, 0);
    }
  } else {
    if (res == 0) res = 1;
  }
  if (res == -1) res = 0;
  return res;
}
