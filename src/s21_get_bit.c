#include "s21_decimal.h"

int s21_get_bit(s21_decimal decl, int index) {
  int row = index / 32;
  int col = index % 32;
  return abs((decl.bits[row] & (1 << col)) >> col);
}
