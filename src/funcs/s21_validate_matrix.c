#include "../s21_matrix.h"

int s21_validate_matrix(matrix_t *A) {
  int ERROR = ERROR_OK;

  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1) {
    ERROR = ERROR_INCORRECT;
  }
  return ERROR;
}