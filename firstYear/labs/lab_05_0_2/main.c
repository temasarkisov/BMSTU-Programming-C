#include<stdio.h>
#include<math.h>
#include<stdlib.h>
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

void row_formation(ci_t row_num, ci_t n, ci_t m, m_t mtx)
{
    for (i_t i = n - 1; i > row_num; i--)
        for (i_t j = 0; j < m; j++)
            mtx[i + 1][j] = mtx[i][j];
    
    for (i_t k = 0; k < m; k++)
        mtx[row_num + 1][k] = 100;
}

i_t num_len(i_t num)
{
    i_t len = 0;

    if (num < 0)
        num = num * -1;

    while (num > 0)
    {
        num = num / 10;
        len++;
    }

    return len;
}

i_t num_divisor(ci_t num)
{
    i_t div = 1;

    for (i_t i = 1; i < num_len(num); i++)
        div = div * 10;

    return div;
}

i_t check_row(ci_t num, ci_t row_num, ci_t m, m_t mtx)
{
    i_t count_start = ZERO;
    i_t count_end = ZERO;
    
    for (i_t j = ZERO; j < m; j++)
    {
        if (abs(mtx[row_num][j]) / num_divisor(mtx[row_num][j]) == num || abs(mtx[row_num][j]) == num)
        {
            count_start++;
        }
        if (abs(mtx[row_num][j]) % 10 == num || abs(mtx[row_num][j]) == num)
            count_end++;
    }
    
    if (count_end != count_start || count_start == ZERO || count_end == ZERO)
        return ERROR;
    
    return NO_ERROR;
}

void matrix_formation(ci_t num, cia_t new_n, ci_t n, ci_t m, m_t mtx)
{
    *new_n = n;
    
    for (i_t row_num = ZERO; row_num < *new_n; row_num++)
        if (check_row(num, row_num, m, mtx))
        {
            row_formation(row_num, *new_n, m, mtx);
            row_num ++;
            *new_n = *new_n + 1;
        }
}

i_t num_input(cia_t num)
{
    if (scanf("%d", num) == 1 && *num >= 0 && *num <= 9)
        return NO_ERROR;
    
    return ERROR;
}

i_t main(void)
{
    i_t n, m;
    m_t matrix;
    i_t num;
    i_t new_n;
    
    if (matrix_input(&n, &m, matrix))
    {
        if (num_input(&num))
        {
            matrix_formation(num, &new_n, n, m, matrix);
            matrix_output(new_n, m, matrix);
            return R_RT;
        }
        else
            return R_WG;
    }
    else
        return R_WG;
}
