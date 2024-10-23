#include "s21_decimal.h"

int check_mantis(s21_decimal decl) {
  int res = 0;
  for (int i = 0; i <= 3; ++i) {
    if (decl.bits[i] != 0) {
      res = 1;
    }
  }
  return res;
}

void decl_nul(s21_decimal *decl, int code) {
  for (int i = 3 - code; i >= 0; --i) {
    decl->bits[i] = 0;
  }
}

int check_error(s21_decimal decl_1, s21_decimal decl_2, s21_decimal *decl_res,
                int *res) {
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
  } else if (!check_mantis(decl_1) || !check_mantis(decl_2)) {
    if (pw1 == 0 && !check_mantis(decl_1)) {
      *decl_res = decl_2;
    } else if (pw2 == 0 && !check_mantis(decl_2)) {
      *decl_res = decl_1;
    }
    *res = -1;
  }
  return *res;
}

void power_switch(s21_decimal *value_1, s21_decimal *value_2) {
  s21_decimal temp = *value_1;
  *value_1 = *value_2;
  *value_2 = temp;
}

int check_unused_bit(s21_decimal decl) {
  int flag = 0;
  for (int i = 96; i <= 126 && flag == 0; ++i) {
    if (i == 112) i = 120;

    if (s21_get_bit(decl, i) == 1) flag = 1;
  }
  return flag;
}

int decl_error(s21_decimal decl) {
  int flag = 0;
  flag = check_unused_bit(decl);
  if (s21_get_power(decl) < 0 || s21_get_power(decl) > 28) {
    flag = 1;
  }
  return flag;
}

int search_one_bit(s21_decimal decl) {
  int res = 0;
  for (int i = 0; i <= 95 && res != -1; ++i) {
    if (s21_get_bit(decl, i) && res == 0) {
      res = 1;
    } else if (res != 0 && s21_get_bit(decl, i)) {
      res = -1;
    }
  }
  return res;
}
