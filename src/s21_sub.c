#include "s21_decimal.h"

void power_work(int pw1, int pw2, int *check, s21_decimal value_1,
                s21_decimal *result, s21_decimal *temp_decl) {
  for (int j = 0; j < (pw2 - pw1) && *check == 0; ++j) {
    value_1 = *result;
    for (int i = 1; i < 10 && *check == 0; ++i) {
      if (s21_dec_sum(*result, value_1, result) != 0) {
        *check = i + (j * 10);
        *result = *temp_decl;
      }
      if (i == 9) {
        *temp_decl = *result;
        s21_set_power(result, j + 1 + pw1);
      }
    }
  }
}

void alg_sub(s21_decimal *decl_res, int *temp, int sub, int i) {
  if (sub == 0) {
    s21_set_bit(decl_res, i, 0);
    *temp = 0;
  } else if (sub == 1) {
    s21_set_bit(decl_res, i, 1);
    *temp = 0;
  } else if (sub == -1) {
    s21_set_bit(decl_res, i, 1);
    *temp = 1;
  }
}

int s21_dec_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0, temp = 0, sub = 0;
  for (int i = 0; i <= 95 && res == 0; ++i) {
    sub = s21_get_bit(value_1, i) - s21_get_bit(value_2, i) - temp;
    alg_sub(result, &temp, sub, i);

    if (temp == 1) {
      int j = i + 1;
      while (j <= 95 && s21_get_bit(value_1, j) == 0) {
        s21_set_bit(&value_1, j, 1);
        ++j;
      }
      if (j <= 95) {
        s21_set_bit(&value_1, j, 0);
        temp = 0;
      } else {
        temp = 1;
      }
    }
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

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  decl_nul(result, 0);
  int error = check_error(value_1, value_2, result, &res);
  if (s21_get_bit(value_1, 127) != s21_get_bit(value_2, 127)) {
    s21_set_bit(&value_2, 127, !s21_get_bit(value_2, 127));
    res = s21_add(value_1, value_2, result);
  } else {
    int pw1 = s21_get_power(value_1), pw2 = s21_get_power(value_2);
    if (error == -1) {
      if (pw1 == 0 && !check_mantis(value_1)) {
        s21_set_bit(result, 127, !s21_get_bit(value_2, 127));
      }
    }
    if (error == 0) {
      int temp = 0, check = 0;
      if (pw1 > pw2) {
        power_switch(&value_1, &value_2);
        temp = 1;
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
      int flag = -1;
      if (s21_get_bit(*result, 127) == 1) flag = 1;
      if (s21_function_compare(*result, temp_decl) == flag) {
        power_switch(&temp_decl, result);
        temp = temp + 1;
      }
      s21_dec_sub(*result, temp_decl, result);
      if (temp == 1) s21_set_bit(result, 127, !s21_get_bit(*result, 127));
    }
    if (result->bits[0] == 0 && result->bits[1] == 0 && result->bits[2] == 0) {
      s21_set_bit(result, 127, 0);
    }
  }
  if (res == -1) res = 0;
  return res;
}
