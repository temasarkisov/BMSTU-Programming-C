#ifndef __MATRIX_OPER_H__
#define __MATRIX_OPER_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "matrix_math.h"
#include "matrix_cdio.h"
#include "struct_matrix_t.h"
#include "errno.h"

int row_with_min_el_def(const matrix_t matrix);

int col_with_min_el_def(const matrix_t matrix);

void matrix_row_del(matrix_t *const matrix);

int matrix_col_del(matrix_t *const matrix);

int matrix_row_or_col_del(matrix_t *const matrix);

int matrix_row_add(matrix_t *const matrix, const int rows_res);

int matrix_col_add(matrix_t *const matrix, const int columns_res);

int matrix_row_or_col_add(matrix_t *const matrix, const int rows_res, const int columns_res);

void matrix_multip(const matrix_t matrix1, const matrix_t matrix2, matrix_t *const matrix_res);

matrix_t matrix_raise_to_power(matrix_t matrix, const int power);

#endif
