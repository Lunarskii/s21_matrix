#include "s21_arithmetic.h"

int s21_switch_func(matrix_t *A, matrix_t *B, matrix_t *result, char sign) {
  int RESULT_CODE = OK;

  if (!A || !B || !A->matrix || !B->matrix || !result) {
    RESULT_CODE = INCORRECT_MATRIX;
  } else if (s21_isIncorrectSize(*A) || s21_isIncorrectSize(*B)) {
    RESULT_CODE = INCORRECT_MATRIX;
  } else if (!s21_isSizeEqual(*A, *B)) {
    RESULT_CODE = INCORRECT_CALCULATION;
  } else if (s21_create_matrix(A->rows, A->columns, result)) {
    RESULT_CODE = INCORRECT_MATRIX;
  }
  for (int i = 0; RESULT_CODE == OK && i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (sign == '+') {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      } else {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return RESULT_CODE;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_switch_func(A, B, result, '+');
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_switch_func(A, B, result, '-');
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int RESULT_CODE = OK;

  if (!A || !A->matrix || !result) {
    RESULT_CODE = INCORRECT_MATRIX;
  } else if (s21_isIncorrectSize(*A)) {
    RESULT_CODE = INCORRECT_MATRIX;
  } else if (s21_create_matrix(A->rows, A->columns, result)) {
    RESULT_CODE = INCORRECT_MATRIX;
  }
  for (int i = 0; RESULT_CODE == OK && i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return RESULT_CODE;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int RESULT_CODE = OK;

  if (!A || !B || !A->matrix || !B->matrix || !result) {
    RESULT_CODE = INCORRECT_MATRIX;
  } else if (s21_isIncorrectSize(*A) || s21_isIncorrectSize(*B)) {
    RESULT_CODE = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    RESULT_CODE = INCORRECT_CALCULATION;
  } else if (s21_create_matrix(A->rows, B->columns, result)) {
    RESULT_CODE = INCORRECT_MATRIX;
  }
  for (int i = 0; RESULT_CODE == OK && i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return RESULT_CODE;
}
