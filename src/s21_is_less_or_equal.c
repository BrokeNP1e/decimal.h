#include "s21_decimal.h"

int s21_is_less_or_equal(s21_decimal decl_1, s21_decimal decl_2) {
  int flag = 0;
  int res = s21_function_compare(decl_1, decl_2);
  if (res != 1) {
    flag = 1;
  }
  return flag;
}
