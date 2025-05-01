#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int ERROR = ERROR_OK;

  if (result == NULL || columns < 1 || rows < 1) {
    ERROR = ERROR_INCORRECT;
  } else if (!ERROR) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
      }
    } else
      ERROR = ERROR_INCORRECT;
  }

  return ERROR;
}