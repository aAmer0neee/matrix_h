#include "../s21_matrix.h"

void initialize_random_matrix_int(matrix_t *A) {
  srand(time(NULL));
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      A->matrix[i][j] = (rand() % 10);
    }
  }
}

void initialize_random_matrix_double(matrix_t *A) {
  srand(time(NULL));
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      A->matrix[i][j] =
          (rand() % 100) + ((double)(rand() % 1000000) / 1000000.0);
    }
  }
}