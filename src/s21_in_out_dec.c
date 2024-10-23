#include "s21_decimal.h"

void reverse_str(char *str) {
  int length = (int)strlen(str);
  for (int i = 0; i < length / 2; i++) {
    char temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }
}

void sum_str(char *str1, char *str2, char *res) {
  char temp_str[32];
  int len1 = (int)strlen(str1) - 1, len2 = (int)strlen(str2) - 1;
  int temp = 0, count = 0, sum1 = 0, sum2 = 0;
  for (int i = len1, j = len2; i >= 0 || j >= 0; i--, j--) {
    if (i >= 0) {
      sum1 = (int)str1[i];
    } else {
      sum1 = 48;
    }
    if (j >= 0) {
      sum2 = (int)str2[j];
    } else {
      sum2 = 48;
    }
    temp_str[count] = (char)((((sum1 - 48) + (sum2 - 48) + temp) % 10) + 48);
    count++;
    temp = ((sum1 - 48) + (sum2 - 48) + temp) / 10;
  }
  if (temp != 0) {
    temp_str[count] = temp + 48;
    count++;
  }
  temp_str[count] = '\0';
  reverse_str(temp_str);
  strcpy(res, temp_str);
}

void power_two(char *res, int power) {
  char str[32] = {'1', '\0'};
  for (int i = 0; i < power; ++i) {
    sum_str(str, str, res);
    strcpy(str, res);
  }
  strcpy(res, str);
}
// Поскольку я устал писать, вывод реализован так:
// (знак)(целая часть в десятичной системе счисления).(значение после запятой в
// двоичной системе) пример: при попытке вывести число "-7.25" функция выведет
// "-7.01"
void out_decl(s21_decimal decl, char *last_number, int flag) {
  char sign = '+';
  if (s21_get_bit(decl, 127)) {
    sign = '-';
  }
  char res[32] = {sign, '\0'};
  char temp_str1[32] = {'0', '\0'};
  char temp_str2[32] = {'0', '\0'};
  char temp_str3[32] = {'0', '\0'};
  int last_bit = 96;
  for (int i = 95; i >= 0 && last_bit == 96; --i) {
    if (s21_get_bit(decl, i)) last_bit = i;
  }
  for (int i = 0; i <= 95; i++) {
    if (s21_get_bit(decl, i)) {
      power_two(temp_str2, i);
      sum_str(temp_str1, temp_str2, temp_str3);
      strcpy(temp_str1, temp_str3);
    }
  }
  strcat(res, temp_str3);
  *last_number = res[(int)strlen(res) - 1];
  for (int i = 0; i < (int)strlen(res) && flag == 0; ++i) {
    if (i == (int)(strlen(res) - s21_get_power(decl))) {
      printf(".");
    }
    printf("%c", res[i]);
  }
  if (flag == 0) printf("\n");
  // printf("decl:%s\n", res);
}
// Черточками выделяется часть предназначенная для степени и знака
void out_bit_decl(s21_decimal decl) {
  for (int i = 127; i >= 0; i--) {
    printf("%d", s21_get_bit(decl, i));
    if (i % 32 == 0) printf(" ");
    if (i == 112 || i == 120 || i == 127) printf("|");
  }
  printf("\n");
}
// Эта функция меняет только мантису(первые 96 бита)
// Числа вводятся в формате 0 и 1. Не забываем что мы не пишем первую единицу,
// то есть если хотим ввести 7(в двоичной это будет 111), в функцию передаём 11
void input_bit_decl(s21_decimal *decl, char *bits) {
  int max = strlen(bits);
  for (int i = 95; i >= 0; i--) {
    if (*bits++ == '1' && i >= 95 - max) {
      s21_set_bit(decl, i, 1);
    } else {
      s21_set_bit(decl, i, 0);
    }
  }
}
