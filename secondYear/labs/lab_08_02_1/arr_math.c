#include<stdio.h>
#include<stdlib.h>

#include"arr_math.h"

#define EPS 0.0000001

double arr_average_calc(double *const arr, const int n)
{
    double arr_average = 0;
    
    for (double *curr_el = arr; curr_el < arr + n; curr_el++)
        arr_average += *curr_el;
    arr_average = arr_average / n;
    
    return arr_average;
}

double el_max_def(double *const arr, const int n)
{
    double el_max = *arr;
    
    for (double *curr_el = arr; curr_el < arr + n; curr_el++)
        if (*curr_el - el_max > EPS)
            el_max = *curr_el;
    
    return el_max;
}
