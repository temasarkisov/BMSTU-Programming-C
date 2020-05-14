#include <stdio.h>

#include "printf.h"

void arr_output(const double *const arr, const int n)
{
    for (const double *curr_el = arr; curr_el < arr + n; curr_el++)
        printf("%lf ", *curr_el);
}
