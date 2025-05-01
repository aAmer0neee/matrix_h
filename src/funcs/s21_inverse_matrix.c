#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int ERROR = ERROR_OK;

  if (s21_validate_matrix(A) || result == NULL) {
    ERROR = ERROR_INCORRECT;
  } else if (A->columns != A->rows) {
    ERROR = ERROR_CALCULATION;
  } else if (!ERROR) {
    double det = 0;
    ERROR = s21_determinant(A, &det);
    if (det == 0) {
      ERROR = ERROR_CALCULATION;
    } else if (!ERROR) {
      if (A->rows == 1) {
        if (!(ERROR = s21_create_matrix(A->rows, A->columns, result)))
          result->matrix[0][0] = 1 / A->matrix[0][0];
      } else {
        matrix_t temp_transpose = {0}, temp_compliments = {0};

        ERROR = s21_calc_complements(A, &temp_compliments);

        if (!ERROR) ERROR = s21_transpose(&temp_compliments, &temp_transpose);

        s21_mult_number(&temp_transpose, det, result);

        s21_remove_matrix(&temp_compliments);
        s21_remove_matrix(&temp_transpose);
      }
    }
  }
  return ERROR;
}
