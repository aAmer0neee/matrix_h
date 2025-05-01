#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int ERROR = ERROR_OK;

  if (s21_validate_matrix(A) || result == NULL) {
    ERROR = ERROR_INCORRECT;
  } else if (!ERROR) {
    if (!(ERROR = s21_create_matrix(A->rows, A->columns, result))) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return ERROR;
}
