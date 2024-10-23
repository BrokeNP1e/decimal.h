#ifndef C5_S21_DECIMAL_1_S21_DECIMAL_H
#define C5_S21_DECIMAL_1_S21_DECIMAL_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int bits[4];
} s21_decimal;

void reverse_str(char *str);
void sum_str(char *str1, char *str2, char *res);
void out_decl(s21_decimal decl, char *last_number, int flag);
void out_bit_decl(s21_decimal decl);
void input_bit_decl(s21_decimal *decl, char *bits);

int s21_get_bit(s21_decimal decl, int index);
void s21_set_bit(s21_decimal *decl, int index, int bit);
int s21_get_power(s21_decimal decl);
void s21_set_power(s21_decimal *decl, int power);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);

int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_add(s21_decimal decl_1, s21_decimal decl_2, s21_decimal *decl_res);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int check_mantis(s21_decimal decl);
void decl_nul(s21_decimal *decl, int code);
int check_error(s21_decimal decl_1, s21_decimal decl_2, s21_decimal *decl_res,
                int *res);
void power_switch(s21_decimal *value_1, s21_decimal *value_2);
void power_work(int pw1, int pw2, int *check, s21_decimal value_1,
                s21_decimal *result, s21_decimal *temp_decl);
int decl_error(s21_decimal decl);

int s21_dec_sum(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int search_one_bit(s21_decimal decl);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);

int s21_is_less(s21_decimal decl_1, s21_decimal decl_2);
int s21_is_less_or_equal(s21_decimal decl_1, s21_decimal decl_2);
int s21_is_greater(s21_decimal decl_1, s21_decimal decl_2);
int s21_is_greater_or_equal(s21_decimal decl_1, s21_decimal decl_2);
int s21_is_equal(s21_decimal decl_1, s21_decimal decl_2);
int s21_is_not_equal(s21_decimal decl_1, s21_decimal decl_2);

int s21_function_compare(s21_decimal decl_1, s21_decimal decl_2);
void discarding_zeros(s21_decimal *decl);

#endif  // C5_S21_DECIMAL_1_S21_DECIMAL_H
