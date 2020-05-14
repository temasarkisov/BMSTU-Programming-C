#include <stdio.h>
#include <stdlib.h>

#include "arr_form.h"
#include "arr_print.h"
#include "arr_math.h"
#include "arr_oper.h"

#define R_I 1  // Right input.
#define W_I -1  // Wrong input.

#define NO_ERR 0  // No error.
#define ERR -1  // Error.
#define INV_MEM_ERR -2  // Invalid memory error.
#define SIZE_ERR -3  // Size error.
#define FILL_ERR -4  // Filling error.
#define POS_ERR -5  // Position error.

int main()
{
    int n = 0;
    double *arr = NULL;
    int pos = 0;
    double arr_average = 0;
    double el_max = 0;

    if (num_input(&n) == W_I)
        return SIZE_ERR;

    arr = arr_allocate(n);
    if (arr == NULL)
    {
        free(arr);
        return INV_MEM_ERR; 
    }

    if (arr_filling(arr, n) == W_I)
    {
        free(arr);
        return FILL_ERR;
    }

    if (pos_input(&pos, n) == W_I)
    {
        free(arr);
        return POS_ERR;
    }

    arr_average = arr_average_calc(arr, n);
    arr_del_el(arr, &n, arr_average);
    el_max = el_max_def(arr, n);
    arr = arr_add_form(arr, &n, pos, el_max);
    arr_output(arr, n);

    free(arr);
    return NO_ERR;
} 
