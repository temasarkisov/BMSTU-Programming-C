#include <stdio.h>
#include <stdlib.h>

#include "arr_math.h"
#include "arr_oper.h"

#define EQ 0
#define NOT_EQ -1
#define TEST_PASSED 0
#define TEST_FAILED -1

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define ALL_TESTS_PASSED 0
#define NOT_ALL_TESTS_PASSED -1

int test_arr_average_calc(double *const arr, const int n, const double true_res)
{
    double cur_res = arr_average_calc(arr, n);
    if (cur_res == true_res)
        return EQ;
    
    return NOT_EQ;
}

int test_el_max_def(double *const arr, const int n, const double true_res)
{
    double cur_res = el_max_def(arr, n);
    if (cur_res == true_res)
        return EQ;
    
    return NOT_EQ;
}

int int_num_test_arr_average_calc()
{
    double arr[] = { 1, 3, 5, 7, 9 };
    int n = 5;
    int true_res = 5;
    
    if (test_arr_average_calc(arr, n, true_res) == EQ)
        return TEST_PASSED;
    
    return TEST_FAILED;
}

int flt_num_test_arr_average_calc()
{
    double arr[] = { 6.3, 5.7, 7.3, 0.7 } ;
    int n = 4;
    int true_res = 5;
    
    if (test_arr_average_calc(arr, n, true_res) == EQ)
        return TEST_PASSED;
    
    return TEST_FAILED;
}

int float_pos_num_test_el_max_def()
{
    double arr[] = { 6.3, 5.7, 7.3, 0.7 };
    int n = 4;
    double true_res = 7.3;
    
    if (test_el_max_def(arr, n, true_res) == EQ)
        return TEST_PASSED;
    
    return TEST_FAILED;
}

int float_neg_num_test_el_max_def()
{
    double arr[] = { -3, -5.6, -3, -0.7 };
    int n = 4;
    double true_res = -0.7;
    
    if (test_el_max_def(arr, n, true_res) == EQ)
        return TEST_PASSED;
    
    return TEST_FAILED;
}

int is_arrays_equal(double *arr1, double *arr2, int n1, int n2)
{
    if (n1 == n2)
    {
        for (int i = 0; i < n1; i++)
            if (*(arr1 + i) != *(arr2 + i))
                return NOT_EQ;
        return EQ;
    }
    return NOT_EQ;
}

int test_arr_del_el(double *const tmp_arr, int *const tmp_n, const double arr_average, double *const true_arr, const int true_n)
{
    arr_del_el(tmp_arr, tmp_n, arr_average);
    
    if (is_arrays_equal(tmp_arr, true_arr, *tmp_n, true_n) == EQ)
        return EQ;
    
    return NOT_EQ;
}

int test_arr_add_form(double *tmp_arr, int *const tmp_n, const int tmp_pos, double tmp_el_max, double *const true_arr, const int true_n)
{
    tmp_arr = arr_add_form(tmp_arr, tmp_n, tmp_pos, tmp_el_max);
    
    if (is_arrays_equal(tmp_arr, true_arr, *tmp_n, true_n) == EQ)
    {
        free(tmp_arr);
        return EQ;
    }

    free(tmp_arr);
    return NOT_EQ;
}

int float_num_test_arr_del_el()
{
    double tmp_arr[] = { 6.3, 5.7, 7.3, 0.7 };
    int tmp_n = 4;
    double arr_average = 5;
    double true_arr[] = { 0.7 };
    int true_n = 1;
    
    if (test_arr_del_el(tmp_arr, &tmp_n, arr_average, true_arr, true_n) == EQ)
        return TEST_PASSED;
    
    return TEST_FAILED;
}

int int_num_test_arr_del_el()
{
    double tmp_arr[] = { 1, 3, 5, 7, 9 };
    int tmp_n = 5;
    double arr_average = 5;
    double true_arr[] = { 1, 3, 5 };
    int true_n = 3;
    
    if (test_arr_del_el(tmp_arr, &tmp_n, arr_average, true_arr, true_n) == EQ)
        return TEST_PASSED;
    
    return TEST_FAILED;
}

int int_num_test_arr_add_form()
{
    double values_arr[] = { 1, 3, 5 };
    int ind = 0;

    int tmp_n = 3;
    double *tmp_arr = malloc(tmp_n * sizeof(double));
    for (double *tmp_value = tmp_arr; tmp_value < tmp_arr + tmp_n; tmp_value++)
    {
        *tmp_value = values_arr[ind];
        ind++;
    }

    int tmp_pos = 1;
    double tmp_el_max = 5;

    double true_arr[] = { 5, 1, 5, 3, 5, 5 };
    int true_n = 6;
    
    if (test_arr_add_form(tmp_arr, &tmp_n, tmp_pos, tmp_el_max, true_arr, true_n) == EQ)
        return TEST_PASSED;

    return TEST_FAILED;
}
int main()
{
    int is_test_failed = 0;

    if (int_num_test_arr_average_calc() != TEST_PASSED)
    {
        printf(ANSI_COLOR_RED "Test name:   int_num_test_arr_average_calc() was failed." ANSI_COLOR_RESET);
        is_test_failed = 1;
    }
        
    if (flt_num_test_arr_average_calc() != TEST_PASSED)
    {
        printf(ANSI_COLOR_RED "Test name:   flt_num_test_arr_average_calc() was failed." ANSI_COLOR_RESET);
        is_test_failed = 1;
    }

    if (float_pos_num_test_el_max_def() != TEST_PASSED)
    {
        printf(ANSI_COLOR_RED "Test name:   float_pos_num_test_el_max_def() was failed." ANSI_COLOR_RESET);
        is_test_failed = 1;
    }
    
    if (float_neg_num_test_el_max_def() != TEST_PASSED)
    {
        printf(ANSI_COLOR_RED "Test name:   float_neg_num_test_el_max_def() was failed." ANSI_COLOR_RESET);
        is_test_failed = 1;
    }
    
    if (float_num_test_arr_del_el() != TEST_PASSED)
    {
        printf(ANSI_COLOR_RED "Test name:   float_num_test_arr_del_el() was failed." ANSI_COLOR_RESET);
        is_test_failed = 1;
    }
    
    if (int_num_test_arr_del_el() != TEST_PASSED)
    {
        printf(ANSI_COLOR_RED "Test name:   int_num_test_arr_del_el() was failed." ANSI_COLOR_RESET);
        is_test_failed = 1;
    }

    if (int_num_test_arr_add_form() != TEST_PASSED)
    {
        printf(ANSI_COLOR_RED "Test name:   int_num_test_arr_add_form() was failed." ANSI_COLOR_RESET);
        is_test_failed = 1;
    }
    
    if (is_test_failed == 0)
        return ALL_TESTS_PASSED;

    return NOT_ALL_TESTS_PASSED;
}
