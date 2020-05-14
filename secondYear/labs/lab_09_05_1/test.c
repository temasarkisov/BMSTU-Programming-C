#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#include"matrix_math.h"
#include"matrix_oper.h"
#include"matrix_cdio.h"
#include"struct_matrix_t.h"

#define EQ 0
#define NOT_EQ -1
#define TEST_PASSED 0
#define TEST_FAILED -1

#define ALL_TESTS_PASSED 0
#define NOT_ALL_TESTS_PASSED -1

int is_matrices_equal(matrix_t matrix1, matrix_t matrix2)
{
    if (matrix1.rows == matrix2.rows && matrix1.columns == matrix2.columns)
    {
        for (int i = 0; i < matrix1.rows; i++)
            for (int j = 0; j < matrix1.columns; j++)
                if (matrix1.matrix[i][j] != matrix2.matrix[i][j])
                    return NOT_EQ;

        return EQ;
    }

    return NOT_EQ;
}

int test_max_el_def(const matrix_t matrix, const int row_ind, const int64_t true_res)
{
    int64_t curr_res = max_el_def(matrix, row_ind);

    //printf("curr = %lld true = %lld\n", curr_res, true_res);
    if (curr_res == true_res)
        return EQ;

    return NOT_EQ;
}

int test_geom_mean_def(const matrix_t matrix, const int col_ind, const int64_t true_res)
{
    int64_t curr_res = geom_mean_def(matrix, col_ind);

    //printf("curr = %lld true = %lld\n", curr_res, true_res);
    if (curr_res == true_res)
        return EQ;

    return NOT_EQ;
}

int test_row_with_min_el_def(const matrix_t matrix, const int true_res)
{
    int curr_res = row_with_min_el_def(matrix);

    //printf("curr = %d true = %d\n", curr_res, true_res);
    if (curr_res == true_res)
        return EQ;

    return NOT_EQ;
}

int test_col_with_min_el_def(const matrix_t matrix, const int true_res)
{
    int curr_res = col_with_min_el_def(matrix);

    //printf("curr = %d true = %d\n", curr_res, true_res);
    if (curr_res == true_res)
        return EQ;

    return NOT_EQ;
}

int test_matrix_row_or_col_del(matrix_t *const matrix, const matrix_t true_matrix)
{
    matrix_row_or_col_del(matrix);

    //matrix_output(*matrix);
    //matrix_output(true_matrix);

    if (is_matrices_equal(*matrix, true_matrix) == EQ)
        return EQ;

    return NOT_EQ;
}

int test_matrix_row_or_col_add(matrix_t *matrix, const int rows_res, const int columns_res, const matrix_t true_matrix)
{
    matrix_row_or_col_add(matrix, rows_res, columns_res);

    //matrix_output(*matrix);
    //matrix_output(true_matrix);

    if (is_matrices_equal(*matrix, true_matrix) == EQ)
        return EQ;

    return NOT_EQ;
}

int test_matrix_raise_to_power(matrix_t matrix, const int power, const matrix_t true_matrix)
{
    matrix = matrix_raise_to_power(matrix, power);

    if (is_matrices_equal(matrix, true_matrix) == EQ)
        return EQ;

    return NOT_EQ;
}

int pos_num_test_max_el_def()
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.columns = 3;
    matrix_allocate(&matrix);

    int64_t arr_of_values[9] = { 1, 5, 6, 3, 7, 8, 3, 6, 5 };
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
            matrix.matrix[i][j] = arr_of_values[i * matrix.rows + j];
    
    int row_ind = 1;
    int64_t true_res = 8;

    if (test_max_el_def(matrix, row_ind, true_res) == EQ)
    {
        matrix_free(matrix);
        return TEST_PASSED;
    }

    matrix_free(matrix);
    return TEST_FAILED;
}

int neg_num_test_max_el_def()
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.columns = 3;
    matrix_allocate(&matrix);

    int64_t arr_of_values[9] = { -1, -5, -6, -3, -7, -8, -3, -6, -5 };
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
            matrix.matrix[i][j] = arr_of_values[i * matrix.rows + j];

    int row_ind = 0;
    int64_t true_res = -1;

    if (test_max_el_def(matrix, row_ind, true_res) == EQ)
    {
        matrix_free(matrix);
        return TEST_PASSED;
    }

    matrix_free(matrix);
    return TEST_FAILED;
}

int pos_num_test_geom_mean_def()
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.columns = 3;
    matrix_allocate(&matrix);

    int64_t arr_of_values[] = { 1, 5, 6, 3, 7, 8, 3, 6, 5 };
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
            matrix.matrix[i][j] = arr_of_values[i * matrix.rows + j];

    int col_ind = 2;
    int true_res = 6;

    if (test_geom_mean_def(matrix, col_ind, true_res) == EQ)
    {
        matrix_free(matrix);
        return TEST_PASSED;
    }

    matrix_free(matrix);
    return TEST_FAILED;
}

int neg_num_test_geom_mean_def()
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.columns = 3;
    matrix_allocate(&matrix);

    int64_t arr_of_values[] = { -1, -5, -6, -3, -7, -8, -3, -6, -5 };
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
            matrix.matrix[i][j] = arr_of_values[i * matrix.rows + j];

    int col_ind = 0;
    int true_res = 2;

    if (test_geom_mean_def(matrix, col_ind, true_res) == EQ)
    {
        matrix_free(matrix);
        return TEST_PASSED;
    }
        
    matrix_free(matrix);
    return TEST_FAILED;
}

int pos_n_test_row_with_min_el_def()
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.columns = 3;
    matrix_allocate(&matrix);

    int64_t arr_of_values[] = { 1, 5, 6, 3, 7, 8, 3, 6, 5 };
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
            matrix.matrix[i][j] = arr_of_values[i * matrix.rows + j];

    int true_res = 0;

    if (test_row_with_min_el_def(matrix, true_res) == EQ)
    {
        matrix_free(matrix);
        return TEST_PASSED;
    }

    matrix_free(matrix);
    return TEST_FAILED;
}

int neg_n_test_col_with_min_el_def()
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.columns = 3;
    matrix_allocate(&matrix);

    int64_t arr_of_values[] = { -1, 5, -6, -3, 7, 8, -3, 6, -5 };
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
            matrix.matrix[i][j] = arr_of_values[i * matrix.rows + j];

    int true_res = 2;

    if (test_col_with_min_el_def(matrix, true_res) == EQ)
    {
        matrix_free(matrix);
        return TEST_PASSED;
    }

    matrix_free(matrix);
    return TEST_FAILED;
}

int more_cols_test_row_or_col_del()
{
    matrix_t matrix;
    matrix.rows = 2;
    matrix.columns = 3;
    matrix_allocate(&matrix);

    int64_t arr_of_values[] = { 1, 5, 6, 3, 7, 8 };
    int ind = 0;
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
        {
            matrix.matrix[i][j] = arr_of_values[ind];
            ind++;
        }

    matrix_t true_matrix;
    true_matrix.rows = 2;
    true_matrix.columns = 2;
    matrix_allocate(&true_matrix);

    int64_t true_arr_of_values[] = { 5, 6, 7, 8 };
    for (int i = 0; i < true_matrix.rows; i++)
        for (int j = 0; j < true_matrix.columns; j++)
            true_matrix.matrix[i][j] = true_arr_of_values[i * true_matrix.rows + j];

    if (test_matrix_row_or_col_del(&matrix, true_matrix) == EQ)
    {
        matrix_free(matrix);
        matrix_free(true_matrix);
        return TEST_PASSED;
    }

    matrix_free(matrix);
    matrix_free(true_matrix);
    return TEST_FAILED;
}

int more_rows_test_row_or_col_del()
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.columns = 2;
    matrix_allocate(&matrix);

    int64_t arr_of_values[] = { 1, 5, 6, 3, 7, 8 };
    int ind = 0;
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
        {
            matrix.matrix[i][j] = arr_of_values[ind];
            ind++;
        }

    matrix_t true_matrix;
    true_matrix.rows = 2;
    true_matrix.columns = 2;
    matrix_allocate(&true_matrix);

    int64_t true_arr_of_values[] = { 6, 3, 7, 8 };
    for (int i = 0; i < true_matrix.rows; i++)
        for (int j = 0; j < true_matrix.columns; j++)
            true_matrix.matrix[i][j] = true_arr_of_values[i * true_matrix.rows + j];

    if (test_matrix_row_or_col_del(&matrix, true_matrix) == EQ)
    {
        matrix_free(matrix);
        matrix_free(true_matrix);
        return TEST_PASSED;
    }

    matrix_free(matrix);
    matrix_free(true_matrix);
    return TEST_FAILED;
}

int mix_test_matrix_row_or_col_add()
{
    matrix_t matrix;
    matrix.rows = 2;
    matrix.columns = 2;
    matrix_allocate(&matrix);

    int64_t arr_of_values[] = { 1, 5, 6, 3 };
    int ind = 0;
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
        {
            matrix.matrix[i][j] = arr_of_values[ind];
            ind++;
        }

    matrix_t true_matrix;
    true_matrix.rows = 3;
    true_matrix.columns = 3;
    matrix_allocate(&true_matrix);

    //1 5 5
    //6 3 6
    //2 3 3

    int64_t true_arr_of_values[] = { 1, 5, 5, 6, 3, 6, 2, 3, 3 };
    for (int i = 0; i < true_matrix.rows; i++)
        for (int j = 0; j < true_matrix.columns; j++)
            true_matrix.matrix[i][j] = true_arr_of_values[i * true_matrix.rows + j];

    if (test_matrix_row_or_col_add(&matrix, true_matrix.rows, true_matrix.columns, true_matrix) == EQ)
    {
        matrix_free(matrix);
        matrix_free(true_matrix);
        return TEST_PASSED;
    }

    matrix_free(matrix);
    matrix_free(true_matrix);
    return TEST_FAILED;
}

int pow_test_raise_to_power()
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.columns = 3;
    matrix_allocate(&matrix);

    int64_t arr_of_values[] = { 2, 4, 7, -4, 1, 8, 6, 7, 0 };
    int ind = 0;
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
        {
            matrix.matrix[i][j] = arr_of_values[ind];
            ind++;
        }

    matrix_t true_matrix;
    true_matrix.rows = 3;
    true_matrix.columns = 3;
    matrix_allocate(&true_matrix);

    int64_t true_arr_of_values[] = { 30, 61, 46, 36, 41, -20, -16, 31, 98 };
    for (int i = 0; i < true_matrix.rows; i++)
        for (int j = 0; j < true_matrix.columns; j++)
            true_matrix.matrix[i][j] = true_arr_of_values[i * true_matrix.rows + j];

    int power = 2;

    if (test_matrix_raise_to_power(matrix, power, true_matrix) == EQ)
    {
        matrix_free(matrix);
        matrix_free(true_matrix);
        return TEST_PASSED;
    }

    matrix_free(matrix);
    matrix_free(true_matrix);
    return TEST_FAILED;
}

int zero_pow_test_raise_to_power()
{
    matrix_t matrix;
    matrix.rows = 3;
    matrix.columns = 3;
    matrix_allocate(&matrix);
    
    int64_t arr_of_values[] = { 2, 4, 7, -4, 1, 8, 6, 7, 0 };
    int ind = 0; 
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
        {   
            matrix.matrix[i][j] = arr_of_values[ind];
            ind++;
        }
    
    matrix_t true_matrix;
    true_matrix.rows = 3; 
    true_matrix.columns = 3;
    matrix_allocate(&true_matrix);
    
    int64_t true_arr_of_values[] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
    for (int i = 0; i < true_matrix.rows; i++)
        for (int j = 0; j < true_matrix.columns; j++)
            true_matrix.matrix[i][j] = true_arr_of_values[i * true_matrix.rows + j];
    
    int power = 0;
    
    if (test_matrix_raise_to_power(matrix, power, true_matrix) == EQ)
    {   
        matrix_free(matrix);
        matrix_free(true_matrix);
        return TEST_PASSED;
    }

    matrix_free(matrix);
    matrix_free(true_matrix);
    return TEST_FAILED;
}

int main()
{    
    int is_failed = 0;

    if (pos_num_test_max_el_def() != TEST_PASSED)
    {
        printf("Test name:   pos_num_test_max_el_def() was failed.");
        is_failed = 1;
    }
    
    if (neg_num_test_max_el_def() != TEST_PASSED)
    {
        printf("Test name:   neg_num_test_max_el_def() was failed.");
        is_failed = 1;    
    }
    
    if (pos_num_test_geom_mean_def() != TEST_PASSED)
    {
        printf("Test name:   pos_num_test_geom_mean_def() was failed.");
        is_failed = 1;
    }
    
    if (neg_num_test_geom_mean_def() != TEST_PASSED)
    {
        printf("Test name:   neg_num_test_geom_mean_def() was failed.");
        is_failed = 1;
    }
    
    if (pos_n_test_row_with_min_el_def() != TEST_PASSED)
    {
        printf("Test name:   pos_n_test_row_with_min_el_def() was failed.");
        is_failed = 1;
    }
    
    if (neg_n_test_col_with_min_el_def() != TEST_PASSED)
    {
        printf("Test name:   neg_n_test_col_with_min_el_def() was failed.");
        is_failed = 1;
    }
    
    if (more_cols_test_row_or_col_del() != TEST_PASSED)
    {
        printf("Test name:   more_cols_test_row_or_col_del() was failed.");
        is_failed = 1;
    }
    
    if (more_rows_test_row_or_col_del() != TEST_PASSED)
    {
        printf("Test name:   more_rows_test_row_or_col_del() was failed.");
        is_failed = 1;
    }
    
    if (mix_test_matrix_row_or_col_add() != TEST_PASSED)
    {
        printf("Test name:   mix_test_matrix_row_or_col_add() was failed.");
        is_failed = 1;
    }
    
    if (pow_test_raise_to_power() != TEST_PASSED)
    {
        printf("Test name:   pow_test_raise_to_power() was failed.");
        is_failed = 1;
    }
    
    if (zero_pow_test_raise_to_power() != TEST_PASSED)
    {
        printf("Test name:   zero_pow_test_raise_to_power() was failed.");
        is_failed = 1;
    }
    
    if (is_failed == 1)
        return NOT_ALL_TESTS_PASSED;

    return ALL_TESTS_PASSED;
}
