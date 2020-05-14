#include <stdio.h>
#include <stdlib.h>

#define EPS 0.0000001

void el_del(double *const arr, double *const el, const int n)
{
    for (double *curr_el = el; curr_el < arr + (n - 1); curr_el++)
        *curr_el = *(curr_el + 1);
}

void arr_del_el(double *const arr, int *const n, const double arr_average)
{
    for (double *curr_el = arr; curr_el < arr + *n; curr_el++)
        if (*curr_el - arr_average > EPS)
        {
            el_del(arr, curr_el, *n);
            (*n)--;
            curr_el--;
        }
}

double *arr_add_form(double *arr, int *const n, const int pos, const double el_max)
{
    arr = (double*) realloc(arr, (*n + 3) * sizeof(double));
    
    for (double *curr_el = arr + *n; curr_el >= arr + pos; curr_el--)
        *(curr_el + 1) = *curr_el;

    *(arr + pos) = el_max;
    *n += 1;

    for (double *curr_el = arr + *n - 1; curr_el >= arr; curr_el--)
        *(curr_el + 1) = *curr_el;
    
    *n += 2;
    
    *arr = el_max;
    *(arr + (*n - 1)) = el_max;
    
    return arr;
}
