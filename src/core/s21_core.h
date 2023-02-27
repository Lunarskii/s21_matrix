#ifndef SRC_CORE_S21_CORE_H_
#define SRC_CORE_S21_CORE_H_

#include <math.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define INCORRECT_MATRIX 1
#define INCORRECT_CALCULATION 2

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_isSizeEqual(matrix_t A, matrix_t B);
int s21_isIncorrectSize(matrix_t matrix);
int s21_isNotSquare(matrix_t matrix);

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

// void s21_print_matrix(matrix_t *matrix);
void s21_setMatrix(double *values, matrix_t *matrix);

#endif  // SRC_CORE_S21_CORE_H_
