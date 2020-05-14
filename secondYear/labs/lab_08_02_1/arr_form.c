#include <stdio.h>
#include <stdlib.h>

#define R_I 1  // Right input.
#define W_I -1  // Wrong input.

#define NO_ERR 0  // No error.
#define ERR -1  // Error.
#define INV_MEM_ERR -2  // Invalid memory error.
#define SIZE_ERR -3  // Size error.
#define FILL_ERR -4  // Filling error.
#define POS_ERR -5  // Position error.

#include"arr_form.h"

int num_input(int *const n)
{
    if (scanf("%d", n) == R_I)
        if (*n > 0)
            return R_I;

    return W_I;
}

double *arr_allocate(const int n)
{
    double *arr = calloc(n, sizeof(double));

    return arr;
}

int arr_filling(double *const arr, const int n)
{
    for (double *curr_el = arr; curr_el < arr + n; curr_el++)
        if (scanf("%lf", curr_el) != 1)
            return W_I;

    return R_I;
}

int pos_input(int *const pos, const int n)
{
    if (scanf("%d", pos) == R_I)
        if (*pos >= 0 && *pos < n)
            return R_I;

    return W_I;
}
