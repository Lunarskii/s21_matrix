#include "s21_operations.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int RESULT_CODE = SUCCESS;

  if (!A || !B || !A->matrix || !B->matrix) {
    RESULT_CODE = FAILURE;
  } else if (s21_isIncorrectSize(*A) || s21_isIncorrectSize(*B) ||
             !s21_isSizeEqual(*A, *B)) {
    RESULT_CODE = FAILURE;
  }
  for (int i = 0; RESULT_CODE == SUCCESS && i < A->rows; i++) {
    for (int j = 0; RESULT_CODE == SUCCESS && j < A->columns; j++) {
      if (fabs((A->matrix)[i][j] - (B->matrix)[i][j]) >= 1e-7) {
        RESULT_CODE = FAILURE;
      }
    }
  }

  return RESULT_CODE;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int RESULT_CODE = OK;

  if (!A || !A->matrix || !result || s21_isIncorrectSize(*A)) {
    RESULT_CODE = INCORRECT_MATRIX;
  } else if (s21_create_matrix(A->columns, A->rows, result)) {
    RESULT_CODE = INCORRECT_MATRIX;
  }
  for (int i = 0; RESULT_CODE == OK && i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }

  return RESULT_CODE;
}

int s21_calc_minor(matrix_t A, matrix_t *minor, int row, int column) {
  int RESULT_CODE = OK;

  if (s21_create_matrix(A.rows - 1, A.columns - 1, minor)) {
    RESULT_CODE = INCORRECT_MATRIX;
  } else {
    for (int i = 0, minor_i = 0; i < A.rows; i++) {
      if (i == row) continue;
      for (int j = 0, minor_j = 0; j < A.columns; j++) {
        if (j == column) continue;
        minor->matrix[minor_i][minor_j] = A.matrix[i][j];
        minor_j++;
      }
      minor_i++;
    }
  }

  return RESULT_CODE;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int RESULT_CODE = OK;

  if (!A || !A->matrix || !result || s21_isIncorrectSize(*A)) {
    RESULT_CODE = INCORRECT_MATRIX;
  } else if (s21_isNotSquare(*A)) {
    RESULT_CODE = INCORRECT_CALCULATION;
  } else if (s21_create_matrix(A->rows, A->columns, result)) {
    RESULT_CODE = INCORRECT_MATRIX;
  } else {
    if (A->rows == 1) {
      result->matrix[0][0] = A->matrix[0][0];
    } else {
      matrix_t minor;

      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          double determinant = 0;

          s21_calc_minor(*A, &minor, i, j);
          s21_determinant(&minor, &determinant);
          result->matrix[i][j] = determinant * pow(-1, i + j);
          s21_remove_matrix(&minor);
        }
      }
    }
  }

  return RESULT_CODE;
}

double s21_calc_determinant(matrix_t A) {
  double determinant = 0;

  if (A.rows == 1) {
    determinant = A.matrix[0][0];
  } else {
    matrix_t minor;
    int sign = 1;

    for (int i = 0; i < A.rows; i++, sign *= -1) {
      s21_calc_minor(A, &minor, i, 0);
      determinant += sign * A.matrix[i][0] * s21_calc_determinant(minor);
      s21_remove_matrix(&minor);
    }
  }

  return determinant;
}

int s21_determinant(matrix_t *A, double *result) {
  int RESULT_CODE = OK;

  if (!A || !A->matrix || !result || s21_isIncorrectSize(*A)) {
    RESULT_CODE = INCORRECT_MATRIX;
  } else if (s21_isNotSquare(*A)) {
    RESULT_CODE = INCORRECT_CALCULATION;
  } else {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else {
      *result = s21_calc_determinant(*A);
    }
  }

  return RESULT_CODE;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int RESULT_CODE = OK;

  if (!A || !A->matrix || !result || s21_isIncorrectSize(*A)) {
    RESULT_CODE = INCORRECT_MATRIX;
  } else if (s21_isNotSquare(*A)) {
    RESULT_CODE = INCORRECT_CALCULATION;
  } else {
    double determinant = 0;

    s21_determinant(A, &determinant);
    if (fabs(determinant) < 1e-6) {
      RESULT_CODE = INCORRECT_CALCULATION;
    } else if (A->rows == 1) {
      s21_create_matrix(1, 1, result);
      result->matrix[0][0] = 1 / determinant;
    } else {
      matrix_t temp;

      s21_calc_complements(A, result);
      s21_transpose(result, &temp);
      s21_remove_matrix(result);
      s21_mult_number(&temp, 1.0 / determinant, result);
      s21_remove_matrix(&temp);
    }
  }

  return RESULT_CODE;
}