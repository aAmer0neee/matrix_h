#include "../s21_matrix.h"

void s21_minor(int delited_row, int delited_column, matrix_t *A,
               matrix_t *result) {
  if (!s21_create_matrix(A->rows - 1, A->columns - 1, result)) {
    for (int i = 0, minor_i = 0; i < A->rows; i++) {
      if (i != delited_row) {
        for (int j = 0, minor_j = 0; j < A->columns; j++) {
          if (j != delited_column) {
            result->matrix[minor_i][minor_j] = A->matrix[i][j];
            minor_j++;
          }
        }
        minor_i++;
      }
    }
  }
}
