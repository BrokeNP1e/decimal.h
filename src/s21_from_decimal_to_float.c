#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int res = 0;
  if (decl_error(src) == 0 && dst != NULL) {
    double temp = 0;
    for (int i = 0; i <= 95; ++i) {
      if (s21_get_bit(src, i)) {
        temp = temp + pow(2, i);
      }
    }
    temp =
        (temp / pow(10, s21_get_power(src))) * pow(-1, s21_get_bit(src, 127));
    *dst = (float)temp;
  } else {
    res = 1;
  }
  return res;
}
