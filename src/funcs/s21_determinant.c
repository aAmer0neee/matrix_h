#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int ERROR = ERROR_OK, sign = 1;
  if (s21_validate_matrix(A) || result == NULL) {
    ERROR = ERROR_INCORRECT;
  } else if (A->columns != A->rows) {
    ERROR = ERROR_CALCULATION;
  } else if (A->columns == 1 && !ERROR) {
    *result = A->matrix[0][0];
  } else if (A->columns == 2 && !ERROR) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else if (A->columns > 2) {
    double minor_res = 0, det_res = 0;
    for (int i = 0; i < A->columns; i++) {
      matrix_t minor = {0};
      s21_minor(0, i, A, &minor);
      if (!(ERROR = s21_determinant(&minor, &minor_res))) {
        det_res += sign * A->matrix[0][i] * minor_res;
        sign = -sign;
      }
      *result = det_res;
      s21_remove_matrix(&minor);
    }
  }
  return ERROR;
}