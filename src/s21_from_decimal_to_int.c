#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;
  if (s21_get_power(src) <= 28 && s21_get_power(src) >= 0) {
    s21_decimal temp_decl = {0};
    s21_truncate(src, &temp_decl);
    if (temp_decl.bits[2] == 0 && temp_decl.bits[1] == 0 &&
        (!s21_get_bit(temp_decl, 31) || temp_decl.bits[0] == (1 << 31))) {
      *dst = temp_decl.bits[0];
      if (s21_get_bit(temp_decl, 127)) {
        *dst = *dst * (-1);
      }
    } else {
      res = 1;
    }
  } else {
    res = 1;
  }

  return res;
}
