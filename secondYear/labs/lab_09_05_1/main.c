#include "main.h"

int main()
{
    int x = 0, y = 0;
    
    matrix_t matrixa;
    matrix_t matrixb;

    if (matrix_size_input(&matrixa) == W_I)
        return SIZE_ERR;

    if (matrix_allocate(&matrixa) != NO_ERR)
        return INV_MEM_ERR;
    
    if (matrix_filling(matrixa) == W_I)
    {
        matrix_free(matrixa);
        return FILL_ERR;
    }

    if (matrix_size_input(&matrixb) == W_I)
    {
        matrix_free(matrixa);
        return SIZE_ERR;
    }

    if (matrix_allocate(&matrixb) != NO_ERR)
    {
        matrix_free(matrixa);
        return INV_MEM_ERR;
    }

    if (matrix_filling(matrixb) == W_I)
    {
        matrix_free(matrixa);
        matrix_free(matrixb);
        return FILL_ERR;
    }

    if (matrix_power_input(&x) == W_I || matrix_power_input(&y) == W_I)
    {
        matrix_free(matrixa);
        matrix_free(matrixb);
        return POW_ERR;
    }

    //printf("Input was done\n");

    if (matrix_row_or_col_del(&matrixa) != NO_ERR)
    {
        matrix_free(matrixb);
        return INV_MEM_ERR;
    }

    if (matrix_row_or_col_del(&matrixb) != NO_ERR)
    {
        matrix_free(matrixa);
        return INV_MEM_ERR;
    }

    /*printf("Matriсes after matrix_row_or_col_del:\n");
    matrix_output(matrixa);
    matrix_output(matrixb);*/

    if (matrix_row_or_col_add(&matrixa, matrixb.rows, matrixb.columns) != NO_ERR)
    {
        matrix_free(matrixb);
        return INV_MEM_ERR;
    }

    if (matrix_row_or_col_add(&matrixb, matrixa.rows, matrixa.columns) != NO_ERR)
    {
        matrix_free(matrixa);
        return INV_MEM_ERR;
    }

    /*printf("Matriсes after matrix_row_or_col_add:\n");
    matrix_output(matrixa);
    matrix_output(matrixb);*/

    matrixa = matrix_raise_to_power(matrixa, x);
    matrixb = matrix_raise_to_power(matrixb, y);

    /*printf("Matriсes after matrix_raise_to_power:\n");
    matrix_output(matrixa);
    matrix_output(matrixb);*/

    matrix_t matrixr;
    matrixr.rows = matrixa.rows;
    matrixr.columns = matrixa.columns;

    if (matrix_allocate(&matrixr) != NO_ERR)
    {
        matrix_free(matrixa);
        matrix_free(matrixb);
        return INV_MEM_ERR;
    }

    matrix_multip(matrixa, matrixb, &matrixr);

    matrix_output(matrixr);

    matrix_free(matrixa);
    matrix_free(matrixb);
    matrix_free(matrixr);

    return NO_ERR;
}
