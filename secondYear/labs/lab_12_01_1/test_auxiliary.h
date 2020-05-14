#ifndef __TEST_AUXILIARY_H__
#define __TEST_AUXILIARY_H__

#include "main.h"

#define EQ 1
#define NOT_EQ -1
#define PASSED 1
#define FAILED -1
#define ALL_TESTS_PASSED 0
#define NOT_ALL_TESTS_PASSED -1

int is_polynom_equal(polynom_t *polynom_a, polynom_t *polynom_b);

void polynom_form(polynom_t *polynom, int *arr, int pol_size);

int val_oper_test(polynom_t *polynom, int arg, int value_true);

int ddx_oper_test(polynom_t *polynom, polynom_t *polynom_true);

int sum_oper_test(polynom_t *polynom_a, polynom_t *polynom_b, polynom_t *polynom_r, polynom_t *polynom_true);

int dvd_oper_test(polynom_t *polynom, polynom_t *polynom_odd, polynom_t *polynom_even, polynom_t *polynom_odd_true, polynom_t *polynom_even_true);

int val_positive_arg(int *const is_failed);

int val_neg_arg(int *const is_failed);

int ddx_non_zero_power(int *const is_failed);

int ddx_zero_power(int *const is_failed);

int sum_diff_sizes(int *const is_failed);

int sum_same_sizes(int *const is_failed);

int dvd_mix(int *const is_failed);

#endif