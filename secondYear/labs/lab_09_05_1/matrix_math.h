#ifndef __MATRIX_MATH_H__
#define __MATRIX_MATH_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "struct_matrix_t.h"
#include "errno.h"

int64_t max_el_def(const matrix_t matrix, const int row_ind);

int64_t raise_to_power(const int64_t number, const int power);

int64_t geom_mean_def(const matrix_t matrix, const int col_ind);

#endif
