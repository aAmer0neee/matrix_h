#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int ERROR = ERROR_OK;
  if (s21_validate_matrix(A) || result == NULL) {
    ERROR = ERROR_INCORRECT;
  } else if (A->columns != A->rows) {
    ERROR = ERROR_CALCULATION;
  } else if (!(ERROR = s21_create_matrix(A->rows, A->columns, result))) {
    double complement = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor = {0};
        s21_minor(i, j, A, &minor);

        s21_determinant(&minor, &complement);
        complement *= pow(-1, i + j);
        result->matrix[i][j] = complement;

        s21_remove_matrix(&minor);
      }
    }
  }
  return ERROR;
}