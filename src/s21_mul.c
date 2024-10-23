#include "s21_decimal.h"

int check_error_for_mul(s21_decimal decl_1, s21_decimal decl_2,
                        s21_decimal *decl_res, int *res) {
  s21_decimal minus_zero = {{0, 0, 0, 0x80000000}};
  int pw1 = s21_get_power(decl_1);
  int pw2 = s21_get_power(decl_2);
  if (pw1 == 255 || pw2 == 255) {
    if (pw1 == 255) {
      if (s21_get_bit(decl_1, 127)) {
        *res = 2;
      } else {
        *res = 1;
      }
    } else {
      if (s21_get_bit(decl_2, 127)) {
        *res = 2;
      } else {
        *res = 1;
      }
    }
  } else if (decl_error(decl_1) == 1 || decl_error(decl_2) == 1 ||
             decl_error(*decl_res) == 1 || decl_res == NULL) {
    if (pw1 > 28) {
      *res = 2;
    } else {
      *res = 1;
    }
  } else if ((!check_mantis(decl_1) || s21_is_equal(decl_1, minus_zero)) ||
             (!check_mantis(decl_2) || s21_is_equal(decl_2, minus_zero) == 1)) {
    decl_nul(decl_res, 0);
    *res = -1;
  }
  return *res;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  if (check_error_for_mul(value_1, value_2, result, &res) == 0) {
    if (s21_get_power(value_1) + s21_get_power(value_2) > 28) {
      res = 2;
    } else {
      s21_decimal val_1 = {0}, val_2 = {0}, temp_res = {0};
      val_1 = value_1, val_2 = value_2, temp_res = value_1;
      s21_decimal count = {{1, 0, 0, val_2.bits[3]}};
      s21_decimal one = {{1, 0, 0, val_2.bits[3]}};
      /*if(search_one_bit(val_2) != -1 && search_one_bit(val_2) != 0){
          temp_res = temp_res << search_one_bit(val_2);
      } else{*/
      while (s21_is_equal(count, val_2) == 0 && res == 0) {
        res = s21_add(temp_res, val_1, &temp_res);
        s21_add(count, one, &count);
      }
      //}
      *result = temp_res;
      s21_set_bit(result, 127,
                  s21_get_bit(value_1, 127) ^ s21_get_bit(value_2, 127));
      if (result->bits[0] == 0 && result->bits[1] == 0 &&
          result->bits[2] == 0) {
        s21_set_bit(result, 127, 0);
      }
      s21_set_power(result, s21_get_power(value_1) + s21_get_power(value_2));
    }
  }
  if (res == -1) res = 0;
  return res;
}
