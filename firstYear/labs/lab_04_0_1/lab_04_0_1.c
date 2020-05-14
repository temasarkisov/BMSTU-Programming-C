#include<stdio.h>
#define R_RT 0
#define R_WG 1
#define ERROR 0
#define NO_ERROR 1
#define ZERO 0
#define DIME 10
#define DIME_MAX 11

int array_input(int *const num, int *const a)
{
    char tmp;
    
    if (scanf("%d", num) == 1 && *num > ZERO && *num < DIME_MAX)
    {
        for (int i = ZERO; i < *num; i++)
            if ((i == ZERO && scanf("%c", &tmp) == 1 && tmp != ' ') || scanf("%d", &a[i]) != 1)
                return ERROR;
            else if (i < *num - 1 && scanf("%c", &tmp) == 1 && tmp == '\n')
                return ERROR;
            else if (i == *num - 1 && scanf("%c", &tmp) == 1 && tmp != '\n')
            {
                while (tmp == ' ')
                    scanf("%c", &tmp);
                if (tmp != '\n')
                    return ERROR;
            }
    }
    else
        return ERROR;
    
    return NO_ERROR;
}

int even_el(const int num, const int *const a)
{
    for (int i = ZERO; i < num; i++)
        if (a[i] % 2 == ZERO)
            return NO_ERROR;
    
    return ERROR;
}

int sum_even_el(const int num, const int *const a)
{
    int s = ZERO;
    for (int i = ZERO; i < num; i++)
        if (a[i] % 2 == ZERO)
            s = s + a[i];
    
    return s;
}

int main(void)
{
    int num;
    int array[DIME];
    
    if (array_input(&num, array))
    {
        if (even_el(num, array))
        {
            printf("%d", sum_even_el(num, array));
            return R_RT;
        }
        else
        {
            printf("Error.\n");
            return R_WG;
        }
    }
    else
    {
        printf("Error.\n");
        return R_WG;
    }
}


