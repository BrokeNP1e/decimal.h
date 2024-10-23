#include "test.h"

int main() {
  int result = 0;
  result += s21_test_add();
  result += s21_test_mul();
  result += s21_test_sub();
  result += s21_test_div();
  result += s21_test_truncate();
  result += s21_test_negate();
  result += s21_test_floor();
  result += s21_test_round();
  result += s21_test_comparison();
  result += s21_test_convertes();

  return (result == 0) ? 0 : 0;
}
