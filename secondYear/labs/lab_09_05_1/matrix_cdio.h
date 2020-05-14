#ifndef __MATRIX_CDIO_H__
#define __MATRIX_CDIO_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#include "struct_matrix_t.h"
#include "errno.h"

int matrix_size_input(matrix_t *const matrix);

int matrix_allocate(matrix_t *matrix);

int matrix_filling(matrix_t matrix);

int matrix_power_input(int *const power);

void matrix_free(matrix_t matrix);

void matrix_output(const matrix_t matrix);

#endif
