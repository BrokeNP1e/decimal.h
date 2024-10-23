#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (decl_error(value) == 0 && result != NULL) {
    decl_nul(result, 0);
    int pow = s21_get_power(value);
    unsigned long long int remains = 0;
    unsigned long long int mantissa[4] = {
        (unsigned int)value.bits[0], (unsigned int)value.bits[1],
        (unsigned int)value.bits[2], (unsigned int)value.bits[3]};
    for (; pow > 0; pow--) {
      for (int i = 2; i >= 0; i--) {
        if (i != 0) {
          mantissa[i - 1] += (mantissa[i] % 10) << 32;
        } else if (pow == 1) {
          remains = mantissa[i] % 10;
          if (remains >= 5) {
            mantissa[i] += 10;
          }
        }
        mantissa[i] = mantissa[i] / 10;
      }
    }
    s21_set_bit(result, 127, s21_get_bit(value, 127));
    for (int i = 2; i >= 0; i--) {
      result->bits[i] = mantissa[i];
    }
    if (result->bits[0] == 0 && result->bits[1] == 0 && result->bits[2] == 0) {
      s21_set_bit(result, 127, 0);
    }
  } else {
    res = 1;
  }
  return res;
}
