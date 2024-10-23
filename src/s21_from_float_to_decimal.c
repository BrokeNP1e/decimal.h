#include "s21_decimal.h"

void processing_float(char str[], int *number, int *pow_float) {
  int i = 0;
  for (; str[i] != 'e'; ++i) {
    if (str[i] != '-' && str[i] != '.') {
      *number = (*number * 10) + ((int)str[i] - 48);
    }
  }
  int sign = 0;
  i++;
  for (; str[i] != '\0'; ++i) {
    if (str[i] == '+' || str[i] == '-') {
      if (str[i] == '-') sign = 1;
    } else {
      *pow_float = (*pow_float * 10) + ((int)(str[i]) - 48);
    }
  }
  *pow_float = (*pow_float * pow(-1, sign)) - 6;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = 0;
  float max = 79228162514264337593543950335.f;

  if (fabs(src) > max || fabs(src) < 1e-28f || isnan(src) || isinf(src) ||
      dst == NULL) {
    res = 1;
  } else {
    decl_nul(dst, 0);
    char temp_str[15] = {'\0'};
    sprintf(temp_str, "%.6e", src);
    int number = 0;
    int pow_float = 0;
    processing_float(temp_str, &number, &pow_float);
    res = s21_from_int_to_decimal(number, dst);
    if (pow_float < 0) {
      s21_set_power(dst, abs(pow_float));
    } else {
      for (int i = 0; i < pow_float; ++i) {
        s21_decimal ten = {{10, 0, 0, 0}};
        res = s21_mul(*dst, ten, dst);
      }
    }
    if (src < 0) {
      s21_set_bit(dst, 127, 1);
    }
  }
  return res;
}
