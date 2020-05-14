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

int power(const int x, const int y)
{
    int p = 1;
    
    for (int i = ZERO; i < y; i++)
        p = p * x;
    
    return p;
}

int digits_number(int el)
{
    int count = ZERO;
    
    while (el != 0)
    {
        el = el / 10;
        count = count + 1;
    }
    
    return count;
}

int palindrome(int el)
{
    int num = digits_number(el);
    int half = num / 2;
    int sum_half_left;
    int sum_half_right = ZERO;
    
    if (el < 0)
        el = el * (-1);
    if (num % 2 == 0)
        sum_half_left = el / power(10, half);
    else
        sum_half_left = el / power(10, half + 1);
    
    for (int i = ZERO; i < half; i++)
    {
        sum_half_right += (((el % power(10, i + 1)) / power(10, i)) * power(10, half - 1 - i));
    }
    
    if (sum_half_left == sum_half_right)
        return YES;
    
    return NO;
}

int all_el_palindromes(const int n, const int *const a)
{
    int count = ZERO;
    
    for (int i = ZERO; i < n; i++)
        if (palindrome(a[i]))
            count += 1;
    
    if (count == n)
        return ERROR;
    
    return NO_ERROR;
}

int array_with_out_palindromes(int n, int *const a)
{
    for (int i = ZERO; i < n; i++)
        if (palindrome(a[i]))
        {
            for (int j = i; j < n; j++)
                a[j] = a[j + 1];
            i -= 1;
            n -= 1;
        }
    
    return n;
}

int main(void)
{
    int num;
    int array[10];
    int new_num;
    
    if (array_input(&num, array))
    {
        if (all_el_palindromes(num, array))
        {
            new_num = array_with_out_palindromes(num, array);
            array_output(new_num, array);
            
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
