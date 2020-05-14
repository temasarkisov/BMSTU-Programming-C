#ifndef __ARR_OPER_H__
#define __ARR_OPER_H__

#include <stdio.h>
#include <stdlib.h>

void el_del(double *const arr, double *const el, const int n);

void arr_del_el(double *const arr, int *const n, const double arr_average);

double *arr_add_form(double *arr, int *const n, const int pos, const double el_max);

#endif
