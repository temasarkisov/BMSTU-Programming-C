#include<stdio.h>
#define R_RT 0
#define R_WG 1
#define ERROR 0
#define NO_ERROR 1
#define ZERO 0
#define DIME 10
#define DIME_MAX 11

typedef int m_t[DIME][DIME];
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
                printf("%d\n", mtx[i][j]);
            else
                printf("%d ", mtx[i][j]);
        }
}

void row_changer(i_t row_num1, i_t row_num2, i_t m, m_t mtx)
{
    int tmp;

    for (int j = ZERO; j < m; j++)
    {
        tmp = mtx[row_num2][j];
        mtx[row_num2][j] = mtx[row_num1][j];
        mtx[row_num1][j] = tmp;
    }
}

int sum_of_el(ci_t row_num, ci_t m, m_t mtx)
{
    i_t sum = ZERO;

    for (i_t j = ZERO; j < m; j++)
        sum = sum + mtx[row_num][j];    

    return sum;
}

void matrix_sort(ci_t n, ci_t m, m_t mtx)
{
    for (i_t k = ZERO; k < n; k++)
        for (i_t i = ZERO; i < n ; i++)
            if (sum_of_el(i, m, mtx) > sum_of_el(k, m, mtx) && i != k)
                row_changer(i, k, m, mtx);        
}
                    
i_t main(void)
{
    i_t n, m;
    m_t matrix;
                    
    if (matrix_input(&n, &m, matrix))
    {
        matrix_sort(n, m, matrix);
        matrix_output(n, m, matrix);
        return R_RT;
    }
    else
        return R_WG;
}

