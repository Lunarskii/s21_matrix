#ifndef SRC_OPERATIONS_S21_OPERATIONS_H_
#define SRC_OPERATIONS_S21_OPERATIONS_H_

#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  // SRC_OPERATIONS_S21_OPERATIONS_H_