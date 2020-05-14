#include "matrix_cdio.h"

int matrix_size_input(matrix_t *const matrix)
{
    if (scanf("%d", &matrix->rows) && scanf("%d", &matrix->columns) && matrix->rows > 0 && matrix->columns > 0)
        return R_I;
    
    return W_I;
}

int matrix_allocate(matrix_t *matrix)
{
    matrix->matrix = (int64_t **) malloc(matrix->rows * sizeof(int64_t *));
    
    if (matrix->matrix == NULL)
        return INV_MEM_ERR;
    
    for (int i = 0; i < matrix->rows; i++)
    {
        matrix->matrix[i] = (int64_t *) malloc(matrix->columns * sizeof(int64_t));
        if (matrix->matrix[i] == NULL)
        {
            //printf("matrix.matrix[i] = NULL\n");
            for (int j = 0; j < i; j++)
                free(matrix->matrix[j]);
            free(matrix->matrix);
            return INV_MEM_ERR;
        }
    }

    return NO_ERR;
}

int matrix_filling(matrix_t matrix)
{
    int64_t tmp_value = 0;
    
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
        {
            if (scanf("%" SCNd64, &tmp_value))
                matrix.matrix[i][j] = tmp_value;
            else
                return FILL_ERR;
        }
    
    return R_I;
}

int matrix_power_input(int *const power)
{
    if (scanf("%d", power) && *power >= 0)
        return R_I;
    
    return W_I;
}

void matrix_free(matrix_t matrix)
{
    for (int i = 0; i < matrix.rows; i++)
        free(matrix.matrix[i]);
    
    free(matrix.matrix);
}

void matrix_output(const matrix_t matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.columns; j++)
        {
            printf("%" SCNd64, matrix.matrix[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
