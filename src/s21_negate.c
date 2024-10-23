#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (decl_error(value) == 0 && result != NULL) {
    decl_nul(result, 0);
    s21_set_bit(&value, 127, !s21_get_bit(value, 127));
    *result = value;
    if (result->bits[0] == 0 && result->bits[1] == 0 && result->bits[2] == 0) {
      s21_set_bit(result, 127, 0);
    }
  } else {
    res = 1;
  }

  return res;
}
