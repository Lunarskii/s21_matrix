#ifndef SRC_ARITHMETIC_S21_ARITHMETIC_H_
#define SRC_ARITHMETIC_S21_ARITHMETIC_H_

#include "../s21_matrix.h"

int s21_switch_func(matrix_t *A, matrix_t *B, matrix_t *result, char sign);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

#endif  // SRC_ARITHMETIC_S21_ARITHMETIC_H_
