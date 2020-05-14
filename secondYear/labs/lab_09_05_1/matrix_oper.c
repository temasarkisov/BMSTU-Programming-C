#include "matrix_oper.h"

int row_with_min_el_def(const matrix_t matrix)
{
    int64_t min = matrix.matrix[0][0];
    int row_with_min_el = 0;
    
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
            if (matrix.matrix[i][j] < min)
            {
                min = matrix.matrix[i][j];
                row_with_min_el = i;
            }
    
    return row_with_min_el;
}

int col_with_min_el_def(const matrix_t matrix)
{
    int64_t min = matrix.matrix[0][0];
    int col_with_min_el = 0;
    
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
            if (matrix.matrix[i][j] < min)
            {
                min = matrix.matrix[i][j];
                col_with_min_el = j;
            }
    
    return col_with_min_el;
}

void matrix_row_del(matrix_t *const matrix)
{
    int row_with_min_el = row_with_min_el_def(*matrix);

    free((matrix->matrix)[row_with_min_el]);

    for (int i = row_with_min_el; i < matrix->rows - 1; i++)
        (matrix->matrix)[i] = (matrix->matrix)[i + 1];
    
    matrix->rows = matrix->rows - 1;
}

int matrix_col_del(matrix_t *const matrix)
{
    int col_with_min_el = col_with_min_el_def(*matrix);
    
    for (int i = 0; i < matrix->rows; i++)
        for (int j = col_with_min_el; j < matrix->columns - 1; j++)
            (matrix->matrix)[i][j] = (matrix->matrix)[i][j + 1];
    
    for (int i = 0; i < matrix->rows; i++)
    {
        (matrix->matrix)[i] = (int64_t*) realloc((matrix->matrix)[i], (matrix->columns - 1) * sizeof(int64_t));
        if ((matrix->matrix)[i] == NULL)
        {
            matrix_free(*matrix);
            matrix->matrix = NULL;
            return INV_MEM_ERR;
        }
    }

    matrix->columns = matrix->columns - 1;

    return NO_ERR;
}

int matrix_row_or_col_del(matrix_t *matrix)
{
    if (matrix->rows > matrix->columns)
        while (matrix->rows != matrix->columns)
        {
            matrix_row_del(matrix);
            matrix->matrix = (int64_t **) realloc(matrix->matrix, matrix->rows * sizeof(int64_t *));
        }
    else if (matrix->rows < matrix->columns)
        while (matrix->rows != matrix->columns)
        {
            if (matrix_col_del(matrix) != NO_ERR)
                return INV_MEM_ERR;
        }

    return NO_ERR;
}

int matrix_row_add(matrix_t *const matrix, const int rows_res)
{
    int64_t geom_mean = 0;
    int64_t **ptr_save = NULL;

    ptr_save = matrix->matrix;
    matrix->matrix = (int64_t **) realloc(matrix->matrix, rows_res * sizeof(int64_t *));
    if (matrix->matrix == NULL)
    {
        matrix->matrix = ptr_save;
        matrix_free(*matrix);
        matrix->matrix = NULL;

        return INV_MEM_ERR;
    }

    for (int i = matrix->rows; i < rows_res; i++)
    {
        matrix->matrix[i] = (int64_t *) malloc(matrix->columns * sizeof(int64_t));
    
        if (matrix->matrix[i] == NULL)
        {
            matrix->rows += 1;
            matrix_free(*matrix);
            matrix->matrix = NULL;
            
            return INV_MEM_ERR;
        }

        for (int j = 0; j < matrix->columns; j++)
        {
            geom_mean = geom_mean_def(*matrix, j);
            matrix->matrix[i][j] = geom_mean;
        }

        matrix->rows += 1;
    }
    
    return NO_ERR;
}

int matrix_col_add(matrix_t *const matrix, const int columns_res)
{
    int64_t max_el = 0;

    for (int i = 0; i < matrix->rows; i++)
    {
        (matrix->matrix)[i] = (int64_t *) realloc((matrix->matrix)[i], columns_res * sizeof(int64_t *));
        if ((matrix->matrix)[i] == NULL)
        {
            matrix_free(*matrix);
            matrix->matrix = NULL;
            return INV_MEM_ERR;
        }
    }

    while (matrix->columns != columns_res)
    {
        for (int i = 0; i < matrix->rows; i++)
        {
            max_el = max_el_def(*matrix, i);
            matrix->matrix[i][matrix->columns] = max_el;
        }

        matrix->columns += 1;
    }

    return NO_ERR;
}

int matrix_row_or_col_add(matrix_t *const matrix, const int rows_res, const int columns_res)
{
    if (rows_res > matrix->rows)
        if (matrix_row_add(matrix, rows_res) != NO_ERR)
            return INV_MEM_ERR;
    
    if (columns_res > matrix->columns)
        if (matrix_col_add(matrix, columns_res) != NO_ERR)
            return INV_MEM_ERR;
    
    return NO_ERR;
}

void matrix_multip(const matrix_t matrix1, const matrix_t matrix2, matrix_t *const matrix_res)
{
    for (int i = 0; i < matrix1.rows; i++)
        for (int j = 0; j < matrix2.columns; j++)
        {
            (matrix_res->matrix)[i][j] = 0;
            for (int k = 0; k < matrix1.rows; k++)
                (matrix_res->matrix)[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j];
        }
    
    matrix_res->rows = matrix1.rows;
    matrix_res->columns = matrix1.columns;
}

matrix_t matrix_raise_to_power(matrix_t matrix, const int power)
{
    matrix_t matrix_in_pow;
    matrix_t matrix_clone;
    
    matrix_in_pow.rows = matrix.rows;
    matrix_in_pow.columns = matrix.columns;
    matrix_clone.rows = matrix.rows;
    matrix_clone.columns = matrix.columns;
    
    matrix_allocate(&matrix_in_pow);
    matrix_allocate(&matrix_clone);

    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
        {
            matrix_in_pow.matrix[i][j] = 0;
            matrix_clone.matrix[i][j] = matrix.matrix[i][j];
        }
    
    if (power == 0)
        for (int i = 0; i < matrix.rows; i++)
            for (int j = 0; j < matrix.columns; j++)
            {
                if (i == j)
                    matrix.matrix[i][j] = 1;
                else
                    matrix.matrix[i][j] = 0;
            }
    else
        for (int i = 0; i < power - 1; i++)
        {
            matrix_multip(matrix, matrix_clone, &matrix_in_pow);
            
            for (int i = 0; i < matrix.rows; i++)
                for (int j = 0; j < matrix.columns; j++)
                    matrix.matrix[i][j] = matrix_in_pow.matrix[i][j];
        }

    matrix_free(matrix_in_pow);
    matrix_free(matrix_clone);
    
    return matrix;
}
