#include "s21_decimal.h"

int s21_get_power(s21_decimal decl) {
  int power = 0;
  for (int i = 112; i <= 119; ++i) {
    if (s21_get_bit(decl, i)) {
      power |= (1 << (i - 112));
    }
  }
  return power;
}
