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

void array_output(const int n, const int *const a)
{
    for (int i = ZERO; i < n; i++)
    {
        if (i == n - 1)
            printf("%d", a[i]);
        else
            printf("%d ", a[i]);
    }
    printf("\n");
}

void bubble_sort(const int n, int *const a)
{
    int save;
    
    for (int i = ZERO; i < n - 1; i++)
        for (int j = ZERO; j < n - 1; j++)
            if (a[j] > a[j + 1])
            {
                save = a[j];
                a[j] = a[j + 1];
                a[j + 1] = save;
            }
}

int main(void)
{
    int num;
    int array[10];
    
    if (array_input(&num, array))
    {
        bubble_sort(num, array);
        array_output(num, array);
        
        return R_RT;
    }
    else
    {
        printf("Error.\n");
        return R_WG;
    }
}
