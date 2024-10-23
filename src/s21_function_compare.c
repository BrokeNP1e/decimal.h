#include "s21_decimal.h"

void discarding_zeros(s21_decimal *decl) {
  char last_number = 0;
  int pw1 = s21_get_power(*decl);
  out_decl(*decl, &last_number, 1);
  while (pw1 > 0 && last_number == '0') {
    s21_set_power(decl, 1);
    s21_truncate(*decl, decl);
    pw1 = pw1 - 1;
    s21_set_power(decl, pw1);
    out_decl(*decl, &last_number, 1);
  }
}

void comparison_mantis(s21_decimal decl_1, s21_decimal decl_2, int *res) {
  int flag = 0;
  for (int i = 95; i >= 0 && flag == 0; i--) {
    int bit_1 = s21_get_bit(decl_1, i);
    int bit_2 = s21_get_bit(decl_2, i);
    if (bit_1 != bit_2) {
      if (bit_1 > bit_2)
        *res = 1;
      else if (bit_1 < bit_2) {
        *res = -1;
      }
      flag = 1;
    }
  }
}

void comparison_remains(s21_decimal decl_1, s21_decimal decl_2, int *res) {
  int pw1 = s21_get_power(decl_1), pw2 = s21_get_power(decl_2);
  if (pw1 == 0 && pw2 != 0) {
    *res = -1;
  } else if (pw1 != 0 && pw2 == 0) {
    *res = 1;
  } else {
    int max = 0;
    if (pw1 > pw2) {
      max = pw1;
    } else {
      max = pw2;
    }
    for (int i = 1; i <= max && *res == 0; ++i) {
      char last_number1 = 0;
      char last_number2 = 0;
      if ((pw1 - i) < 0 || (pw2 - i) < 0) {
        if ((pw1 - i) < 0) {
          *res = -1;
        } else {
          *res = 1;
        }
      } else {
        s21_decimal temp_1 = decl_1, temp_2 = decl_2;
        s21_set_power(&temp_1, pw1 - i);
        s21_set_power(&temp_2, pw2 - i);
        s21_truncate(temp_1, &temp_1);
        s21_truncate(temp_2, &temp_2);
        out_decl(temp_1, &last_number1, 1);
        out_decl(temp_2, &last_number2, 1);
        if (last_number1 > last_number2) {
          *res = 1;
        } else if (last_number1 < last_number2) {
          *res = -1;
        }
      }
    }
  }
}

int s21_function_compare(s21_decimal decl_1, s21_decimal decl_2) {
  int res = 0;

  int sign_decl_1 = s21_get_bit(decl_1, 127);
  int sign_decl_2 = s21_get_bit(decl_2, 127);

  if (sign_decl_1 == 1 && sign_decl_2 == 0) {
    res = -1;  //<
  } else if (!sign_decl_1 && sign_decl_2) {
    res = 1;  // >
  } else {
    discarding_zeros(&decl_1);
    discarding_zeros(&decl_2);
    s21_decimal temp_1 = decl_1, temp_2 = decl_2;
    s21_truncate(decl_1, &temp_1);
    s21_truncate(decl_2, &temp_2);
    comparison_mantis(temp_1, temp_2, &res);
    if (res == 0) {
      comparison_remains(decl_1, decl_2, &res);
    }
  }

  if (sign_decl_1 && sign_decl_2) {
    res = -res;
  }

  return res;
}
