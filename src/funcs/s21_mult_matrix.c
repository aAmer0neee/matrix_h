#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ERROR = ERROR_OK;

  if (s21_validate_matrix(A) || s21_validate_matrix(B) || result == NULL) {
    ERROR = ERROR_INCORRECT;
  } else if (!s21_equal_size(A, B) &&
             !(A->columns == B->rows && A->rows == B->columns)) {
    ERROR = ERROR_CALCULATION;
  } else if (!ERROR) {
    if (!(ERROR = s21_create_matrix(A->rows, B->columns, result))) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          double value = 0;
          for (int k = 0; k < A->columns; k++) {
            value += A->matrix[i][k] * B->matrix[k][j];
          }
          result->matrix[i][j] = value;
        }
      }
    }
  }

  return ERROR;
}