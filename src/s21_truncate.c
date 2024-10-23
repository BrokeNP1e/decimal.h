#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (decl_error(value) == 0 && result != NULL) {
    decl_nul(result, 0);
    for (int i = 0; i < s21_get_power(value); i++) {
      uint64_t div, last;
      div = 0;
      for (int j = 2; j >= 0; j--) {
        last = (uint32_t)value.bits[j] | (div << 32);
        div = last % 10;
        value.bits[j] = (uint32_t)(last / 10);
      }
    }
    s21_set_power(&value, 0);
    *result = value;
    if (result->bits[0] == 0 && result->bits[1] == 0 && result->bits[2] == 0) {
      s21_set_bit(result, 127, 0);
    }
  } else {
    res = 1;
  }
  return res;
}
