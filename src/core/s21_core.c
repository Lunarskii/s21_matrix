#include "s21_core.h"

int s21_isSizeEqual(matrix_t A, matrix_t B) {
  return A.rows == B.rows && A.columns == B.columns;
}

int s21_isIncorrectSize(matrix_t matrix) {
  return matrix.rows < 1 || matrix.columns < 1;
}

int s21_isNotSquare(matrix_t matrix) { return matrix.rows != matrix.columns; }

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int RESULT_CODE = OK;

  if (rows > 0 && columns > 0 && result) {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows && RESULT_CODE == OK; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          RESULT_CODE = INCORRECT_MATRIX;
          s21_remove_matrix(result);
        }
      }
    } else {
      RESULT_CODE = INCORRECT_MATRIX;
    }
  } else {
    RESULT_CODE = INCORRECT_MATRIX;
  }
  if (RESULT_CODE == OK) {
    result->rows = rows;
    result->columns = columns;
  }

  return RESULT_CODE;
}

void s21_remove_matrix(matrix_t *A) {
  if (A && A->matrix) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

// void s21_print_matrix(matrix_t *matrix) {
//     for (int i = 0; i < matrix -> rows; i++) {
//         for (int j = 0; j < matrix -> columns; j++) {
//             printf("%20.7f\t", (matrix -> matrix)[i][j]);
//         }
//         printf("\n");
//     }
// }

void s21_setMatrix(double *values, matrix_t *matrix) {
  for (int i = 0, iv = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++, iv++) {
      matrix->matrix[i][j] = values[iv];
    }
  }
}
