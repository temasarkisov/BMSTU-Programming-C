#include<stdio.h>
#define R_RT 0
#define R_WG 1
#define ERROR 0
#define NO_ERROR 1
#define YES 1
#define NO 0
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

float average(const int n, const int *const a)
{
    int sum = ZERO;
    float ave;
    
    for (int i = ZERO; i < n; i++)
        sum = sum + a[i];
    
    ave = (float)sum / n;
    return ave;
}

int el_under_average(const int n, const int *const a)
{
    float ave = average(n, a);
    
    for (int i = ZERO; i < n; i++)
        if (a[i] > ave)
            return NO_ERROR;
    
    return ERROR;
}
int new_num_array_under_average(int const n, const int *const a)
{
    int new_n = ZERO;
    float ave = average(n, a);
    
    for (int i = ZERO; i < n; i++)
    {
        if (a[i] > ave)
            new_n = new_n + 1;
    }
    
    return new_n;
}

void new_array_under_average(const int n, const int *const a, int *const new_a)
{
    float ave = average(n, a);
    int index = ZERO;
    
    for (int i = ZERO; i < n; i++)
        if (a[i] > ave)
        {
            new_a[index] = a[i];
            index += 1;
        }
}

int main(void)
{
    int num;
    int array[10];
    int new_num;
    
    if (array_input(&num, array))
    {
        if (el_under_average(num, array))
        {
            new_num = new_num_array_under_average(num, array);
            int new_array[new_num];
            new_array_under_average(num, array, new_array);
            array_output(new_num, new_array);
            
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


