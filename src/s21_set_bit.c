#include "s21_decimal.h"
void s21_set_bit(s21_decimal *decl, int index, int bit) {
  int row = index / 32;
  int col = index % 32;
  if (bit == 1) {
    decl->bits[row] |= (1 << col);
  } else {
    decl->bits[row] &= ~(1 << col);
  }
}
