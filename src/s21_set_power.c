#include "s21_decimal.h"

void s21_set_power(s21_decimal *decl, int power) {
  for (int i = 112; i <= 119; ++i) {
    s21_set_bit(decl, i, 0);
  }
  decl->bits[3] |= (power) << 16;
}
