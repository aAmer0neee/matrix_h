#ifndef S21_MATRIX
#define S21_MATRIX

#define ERROR_OK 0
#define ERROR_INCORRECT 1  //Ошибка, некорректная матрица;
#define ERROR_CALCULATION \
  2  //Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
     //нельзя провести вычисления и т. д.).

#define SUCCESS 1
#define FAILURE 0

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

//_______________Создание матриц (create_matrix)
int s21_create_matrix(int rows, int columns, matrix_t *result);

//_______________Очистка матриц (remove_matrix)
void s21_remove_matrix(matrix_t *matrix);

//_______________Сравнение матриц (eq_matrix)
int s21_eq_matrix(matrix_t *A, matrix_t *B);

//_______________Сложение (sum_matrix) и вычитание матриц (sub_matrix)
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

//_______________Умножение матрицы на число (mult_number). Умножение двух матриц
//(mult_matrix)
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

//_______________Транспонирование матрицы (transpose)
int s21_transpose(matrix_t *A, matrix_t *result);

//_______________Минор матрицы и матрица алгебраических дополнений
//(calc_complements)
int s21_calc_complements(matrix_t *A, matrix_t *result);

//_______________Определитель матрицы (determinant)
int s21_determinant(matrix_t *A, double *result);

//_______________Обратная матрица (inverse_matrix)
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

//_______________HELP FUNCS
int s21_validate_matrix(matrix_t *A);
int s21_equal_size(matrix_t *A, matrix_t *B);

void initialize_random_matrix_int(matrix_t *A);

void initialize_random_matrix_double(matrix_t *A);

void s21_minor(int delited_row, int delited_column, matrix_t *A,
               matrix_t *result);
#endif