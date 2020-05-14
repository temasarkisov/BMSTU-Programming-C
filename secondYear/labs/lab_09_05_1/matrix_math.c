#include "matrix_math.h"

int64_t max_el_def(const matrix_t matrix, const int row_ind)
{
    int64_t max_el = matrix.matrix[row_ind][0];
    
    for (int i = 0; i < matrix.columns; i++)
        if (matrix.matrix[row_ind][i] > max_el)
            max_el = matrix.matrix[row_ind][i];
    
    return max_el;
}

int64_t raise_to_power(int64_t number, const int power)
{
    int64_t number_in_power = number;

    for (int i = 1; i < power; i++)
        number_in_power *= number;

    return number_in_power;
}

int64_t geom_mean_def(const matrix_t matrix, const int col_ind)
{
    int64_t multip = 1;
    int64_t geom_mean = 0;
    
    for (int i = 0; i < matrix.rows; i++)
        multip = multip * matrix.matrix[i][col_ind];
    
    if (multip < 0)
        multip *= -1;

    while (raise_to_power(geom_mean, matrix.rows) <= multip)
        geom_mean++;
    geom_mean--;
    
    return geom_mean;
}
