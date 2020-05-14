#include<stdio.h>
#define R_RT 0
#define R_WG 1
#define ERROR 0
#define NO_ERROR 1
#define ZERO 0
#define DIME 10
#define DIME_MAX 11

typedef int m_t[DIME][DIME];
typedef int a_t[DIME];
typedef const int ci_t;
typedef int *const cia_t;
typedef int i_t;

i_t matrix_input(cia_t n, cia_t m, m_t mtx)
{
    char s;
    
    if (scanf("%d", n) == 1 && *n > ZERO && *n < DIME_MAX && scanf("%d", m) == 1 && *m > ZERO && *m < DIME_MAX)
    {
        for (i_t i = ZERO; i < *n; i++)
            for (i_t j = ZERO; j < *m; j++)
            {
                if (scanf("%d", &mtx[i][j]) != 1)
                    return ERROR;
                else if (j < *m - 1 && scanf("%c", &s) == 1 && s == '\n')
                    return ERROR;
                else if (j == *m - 1 && i == *n - 1 && scanf("%c", &s) == 1 && s != '\n')
                {
                    while (s == ' ')
                        scanf("%c", &s);
                    if (s != '\n')
                        return ERROR;
                }
            }
    }
    else
        return ERROR;
    
    return NO_ERROR;
}

void matrix_output(ci_t n, ci_t m, m_t mtx)
{
    for (i_t i = ZERO; i < n; i++)
        for (i_t j = ZERO; j < m; j++)
        {
            if (j == m - 1)
            {
                printf("%d", mtx[i][j]);
                printf("\n");
            }
            else
                printf("%d ", mtx[i][j]);
        }
}

i_t columncheck(ci_t col_num, ci_t n, m_t mtx)
{
    if (n == 1)
        return ERROR;
    
    for (i_t i = ZERO; i < n - 1; i++)
    {
        if (mtx[i][col_num] <= mtx[i + 1][col_num])
            return ERROR;
    }
    
    return NO_ERROR;
}

void matrix_formation(ci_t n, ci_t m, m_t mtx)
{
    for (i_t col_num = ZERO; col_num < m; col_num++)
    {
        if (columncheck(col_num, n, mtx))
            mtx[ZERO][col_num] = 1;
        else
            mtx[ZERO][col_num] = 0;
    }
}

void array_formation(ci_t n, ci_t m, m_t mtx, a_t arr)
{
    i_t ind = ZERO;
    
    for (i_t j = ZERO; j < m; j++)
    {
        arr[ind] = mtx[ZERO][j];
        ind++;
    }
}

void array_output(ci_t m, a_t arr)
{
    i_t len = m;
    
    for (i_t i = ZERO; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

i_t main(void)
{
    i_t n, m;
    m_t matrix;
    a_t array;
    
    if (matrix_input(&n, &m, matrix))
    {
        matrix_formation(n, m, matrix);
        array_formation(n, m, matrix, array);
        array_output(m, array);
        return R_RT;
    }
    else
        return R_WG;
}

