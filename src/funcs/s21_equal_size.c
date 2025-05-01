#include "../s21_matrix.h"

int s21_equal_size(matrix_t* A, matrix_t* B) {
  int ERROR = SUCCESS;

  if (B->columns != A->columns || B->rows != A->rows) {
    ERROR = FAILURE;
  }
  return ERROR;
}