#include "test_auxiliary.h"

int is_polynom_equal(polynom_t *polynom_a, polynom_t *polynom_b)
{
    polynom_node_t *curr_node_a = polynom_a->head;
    polynom_node_t *curr_node_b = polynom_b->head;

    while (curr_node_a && curr_node_b)
    {
        if (curr_node_a->factor != curr_node_b->factor || curr_node_a->power != curr_node_b->power)
        {
            return NOT_EQ;
        }

        curr_node_a = curr_node_a->next_node;
        curr_node_b = curr_node_b->next_node;
    }

    if (curr_node_b || curr_node_a)
    {
        return NOT_EQ;
    }

    return EQ;
}

void polynom_form(polynom_t *polynom, int *arr, int pol_size)
{
    for (int i = 0; i < pol_size; i += 2)
    {
        polynom_node_add(polynom, arr[i], arr[i + 1]);
    }
}

int val_oper_test(polynom_t *polynom, int arg, int value_true)
{
    int value = polynom_val_oper(polynom, arg);

    if (value == value_true)
    {
        return PASSED;
    }

    return FAILED;
}

int ddx_oper_test(polynom_t *polynom, polynom_t *polynom_true)
{
    polynom_ddx_oper(polynom);

    if (is_polynom_equal(polynom, polynom_true) == EQ)
    {
        return PASSED;
    }

    return FAILED;
}

int sum_oper_test(polynom_t *polynom_a, polynom_t *polynom_b, polynom_t *polynom_r, polynom_t *polynom_true)
{
    polynom_sum_oper(polynom_a, polynom_b, polynom_r);

    if (is_polynom_equal(polynom_r, polynom_true) == EQ)
    {
        return PASSED;
    }

    return FAILED;
} 

int dvd_oper_test(polynom_t *polynom, polynom_t *polynom_odd, polynom_t *polynom_even, polynom_t *polynom_odd_true, polynom_t *polynom_even_true)
{
    polynom_dvd_oper(polynom, polynom_odd, polynom_even);

    if (is_polynom_equal(polynom_odd, polynom_odd_true) != EQ)
    {
        return FAILED;
    }

    if (is_polynom_equal(polynom_even, polynom_even_true) != EQ)
    {
        return FAILED;
    }

    return PASSED;
}

int val_positive_arg(int *const is_failed)
{
    int arr[] = { 4, 3, 2, 1 };
    int pol_size = 4;
    int arg = 3;
    int value_true = 114;

    polynom_t *polynom = NULL;
    polynom = polynom_init(polynom);
    if (!polynom)
    {
        return INV_MEM;
    }
    polynom_form(polynom, arr, pol_size);

    if (val_oper_test(polynom, arg, value_true) != PASSED)
    {
        printf("Test: positive argument value is failed.\n");
        *is_failed = FAILED;
        polynom_free(polynom);
        return FAILED;
    }

    polynom_free(polynom);
    return PASSED;
}

int val_neg_arg(int *const is_failed)
{
    int arr[] = { 7, 1, 3, 0 };
    int pol_size = 4;
    int arg = -5;
    int value_true = -32;

    polynom_t *polynom = NULL;
    polynom = polynom_init(polynom);
    if (!polynom)
    {
        return INV_MEM;
    }
    polynom_form(polynom, arr, pol_size);

    if (val_oper_test(polynom, arg, value_true) != PASSED)
    {
        printf("Test: negative argument value is failed.\n");
        *is_failed = FAILED;
        polynom_free(polynom);
        return FAILED;
    }

    polynom_free(polynom);
    return PASSED;
}

int ddx_non_zero_power(int *const is_failed)
{
    int arr[] = { 7, 1, 3, 2 };
    int pol_size = 4;
    int arr_true[] = { 7, 0, 6, 1 };
    int pol_true_size = 4;

    polynom_t *polynom = NULL;
    polynom = polynom_init(polynom);
    if (!polynom)
    {
        return INV_MEM;
    }

    polynom_t *polynom_true = NULL;
    polynom_true = polynom_init(polynom_true);
    if (!polynom_true)
    {
        polynom_free(polynom);
        return INV_MEM;
    }

    polynom_form(polynom, arr, pol_size);
    polynom_form(polynom_true, arr_true, pol_true_size);

    if (ddx_oper_test(polynom, polynom_true) != PASSED)
    {
        printf("Test: polynom without zero power ddx is failed.\n");
        *is_failed = FAILED;
        polynom_free(polynom);
        polynom_free(polynom_true);
        return FAILED;
    }

    polynom_free(polynom);
    polynom_free(polynom_true);
    return PASSED;
}

int ddx_zero_power(int *const is_failed)
{
    int arr[] = { 7, 1, 3, 0 };
    int pol_size = 4;
    int arr_true[] = { 7, 0 };
    int pol_true_size = 2;

    polynom_t *polynom = NULL;
    polynom = polynom_init(polynom);
    if (!polynom)
    {
        return INV_MEM;
    }

    polynom_t *polynom_true = NULL;
    polynom_true = polynom_init(polynom_true);
    if (!polynom_true)
    {
        polynom_free(polynom);
        return INV_MEM;
    }

    polynom_form(polynom, arr, pol_size);
    polynom_form(polynom_true, arr_true, pol_true_size);

    if (ddx_oper_test(polynom, polynom_true) != PASSED)
    {
        printf("Test: polynom with zero power ddx is failed.\n");
        *is_failed = FAILED;
        polynom_free(polynom);
        polynom_free(polynom_true);
        return FAILED;
    }

    polynom_free(polynom);
    polynom_free(polynom_true);
    return PASSED;
}

int sum_same_sizes(int *const is_failed)
{
    int arr_a[] = { 7, 1, 3, 0 };
    int pol_a_size = 4;
    int arr_b[] = { 6, 2, 5, 1 };
    int pol_b_size = 4;
    int arr_true[] = { 3, 0, 12, 1, 6, 2 };
    int pol_true_size = 6;

    polynom_t *polynom_a = NULL;
    polynom_a = polynom_init(polynom_a);
    if (!polynom_a)
    {
        return INV_MEM;
    }

    polynom_t *polynom_b = NULL;
    polynom_b = polynom_init(polynom_b);
    if (!polynom_b)
    {
        polynom_free(polynom_a);
        return INV_MEM;
    }

    polynom_t *polynom_r = NULL;
    polynom_r = polynom_init(polynom_r);
    if (!polynom_r)
    {
        polynom_free(polynom_a);
        polynom_free(polynom_b);
        return INV_MEM;
    }

    polynom_t *polynom_true = NULL;
    polynom_true = polynom_init(polynom_true);
    if (!polynom_true)
    {
        polynom_free(polynom_a);
        polynom_free(polynom_b);
        polynom_free(polynom_r);
        return INV_MEM;
    }

    polynom_form(polynom_a, arr_a, pol_a_size);
    polynom_form(polynom_b, arr_b, pol_b_size);
    polynom_form(polynom_true, arr_true, pol_true_size);

    if (sum_oper_test(polynom_a, polynom_b, polynom_r, polynom_true) != PASSED)
    {
        polynom_output(polynom_r);
        polynom_output(polynom_true);
        printf("Test: polynoms with same sizes sum is failed.\n");
        *is_failed = FAILED;
        polynom_free(polynom_a);
        polynom_free(polynom_b);
        polynom_free(polynom_r);
        polynom_free(polynom_true);
        return FAILED;
    }

    polynom_free(polynom_a);
    polynom_free(polynom_b);
    polynom_free(polynom_r);
    polynom_free(polynom_true);
    return PASSED;
}

int sum_diff_sizes(int *const is_failed)
{
    int arr_a[] = { 7, 2, 6, 1, 3, 0 };
    int pol_a_size = 6;
    int arr_b[] = { 6, 2, 5, 1 };
    int pol_b_size = 4;
    int arr_true[] = { 3, 0, 11, 1, 13, 2 };
    int pol_true_size = 6;

    polynom_t *polynom_a = NULL;
    polynom_a = polynom_init(polynom_a);
    if (!polynom_a)
    {
        return INV_MEM;
    }

    polynom_t *polynom_b = NULL;
    polynom_b = polynom_init(polynom_b);
    if (!polynom_b)
    {
        polynom_free(polynom_a);
        return INV_MEM;
    }

    polynom_t *polynom_r = NULL;
    polynom_r = polynom_init(polynom_r);
    if (!polynom_r)
    {
        polynom_free(polynom_a);
        polynom_free(polynom_b);
        return INV_MEM;
    }

    polynom_t *polynom_true = NULL;
    polynom_true = polynom_init(polynom_true);
    if (!polynom_true)
    {
        polynom_free(polynom_a);
        polynom_free(polynom_b);
        polynom_free(polynom_r);
        return INV_MEM;
    }

    polynom_form(polynom_a, arr_a, pol_a_size);
    polynom_form(polynom_b, arr_b, pol_b_size);
    polynom_form(polynom_true, arr_true, pol_true_size);

    if (sum_oper_test(polynom_a, polynom_b, polynom_r, polynom_true) != PASSED)
    {
        printf("Test: polynoms with different sizes is failed.\n");
        *is_failed = FAILED;
        polynom_free(polynom_a);
        polynom_free(polynom_b);
        polynom_free(polynom_r);
        polynom_free(polynom_true);
        return FAILED;
    }

    polynom_free(polynom_a);
    polynom_free(polynom_b);
    polynom_free(polynom_r);
    polynom_free(polynom_true);
    return PASSED;
}

int dvd_mix(int *const is_failed)
{
    int arr[] = { 7, 2, 6, 1, 3, 0 };
    int pol_size = 6;
    int arr_odd_true[] = { 6, 1 };
    int pol_odd_size = 2;
    int arr_even_true[] = { 3, 0, 7, 2 };
    int pol_even_size = 4;

    polynom_t *polynom = NULL;
    polynom = polynom_init(polynom);
    if (!polynom)
    {
        return INV_MEM;
    }

    polynom_t *polynom_odd = NULL;
    polynom_odd = polynom_init(polynom_odd);
    if (!polynom_odd)
    {
        polynom_free(polynom);
        return INV_MEM;
    }

    polynom_t *polynom_even = NULL;
    polynom_even = polynom_init(polynom_even);
    if (!polynom_even)
    {
        polynom_free(polynom);
        polynom_free(polynom_odd);
        return INV_MEM;
    }

    polynom_t *polynom_odd_true = NULL;
    polynom_odd_true = polynom_init(polynom_odd_true);
    if (!polynom_odd_true)
    {
        polynom_free(polynom);
        polynom_free(polynom_odd);
        polynom_free(polynom_even);
        return INV_MEM;
    }

    polynom_t *polynom_even_true = NULL;
    polynom_even_true = polynom_init(polynom_even_true);
    if (!polynom_even_true)
    {
        polynom_free(polynom);
        polynom_free(polynom_odd);
        polynom_free(polynom_even);
        polynom_free(polynom_odd_true);
        return INV_MEM;
    }

    polynom_form(polynom, arr, pol_size);
    polynom_form(polynom_odd_true, arr_odd_true, pol_odd_size);
    polynom_form(polynom_even_true, arr_even_true, pol_even_size);

    if (dvd_oper_test(polynom, polynom_odd, polynom_even, polynom_odd_true, polynom_even_true) != PASSED)
    {
        polynom_output(polynom_even);
        polynom_output(polynom_even_true);
        printf("Test: polynom mix part is failed.\n");
        *is_failed = FAILED;
        polynom_free(polynom);
        polynom_free(polynom_odd);
        polynom_free(polynom_even);
        polynom_free(polynom_odd_true);
        polynom_free(polynom_even_true);
        return FAILED;
    }

    polynom_free(polynom);
    polynom_free(polynom_odd);
    polynom_free(polynom_even);
    polynom_free(polynom_odd_true);
    polynom_free(polynom_even_true);
    return PASSED;
}
