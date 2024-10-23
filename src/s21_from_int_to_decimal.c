#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 0;
  s21_set_power(dst, 0);
  decl_nul(dst, 0);
  if (src < 0) {
    src = abs(src);
    s21_set_bit(dst, 127, 1);
  }
  dst->bits[0] = src;
  return res;
}
