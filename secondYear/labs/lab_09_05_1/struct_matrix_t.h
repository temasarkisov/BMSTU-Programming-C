#ifndef __STRUCT_MATRIX_T_H__
#define __STRUCT_MATRIX_T_H__

typedef struct
{
    int rows;
    int columns;
    int64_t **matrix;    
} matrix_t;

#endif
