#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int ERROR = SUCCESS;

  if (s21_validate_matrix(A) || s21_validate_matrix(B) ||
      !s21_equal_size(A, B)) {
    ERROR = FAILURE;
  } else if (ERROR) {
    for (int i = 0; i < A->rows && ERROR; i++) {
      for (int j = 0; j < A->columns; j++) {
        if ((fabs(A->matrix[i][j] - B->matrix[i][j])) >= 1e-7) {
          ERROR = FAILURE;
        }
      }
    }
  }

  return ERROR;
}