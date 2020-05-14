#include <stdio.h>
#define I_MIN -2147483648
#define I_MAX 2147483647

//20

int is_value(int value)
{
    for (int i = 2; i < value; i++)
        if (value % i == 0)
        {
            return 0;
        }
    return 1;
}

void value(long int num)
{
    if (num >= I_MIN && num <= I_MAX)
    {
        if (num < 0)
            num *= -1;
    
        int value;
    
        while (num > 9)
        {
            value = num % 100;
            if (is_value(value))
                printf("%d ", value);
            num = num / 10;
        }
    }
    else if (num > I_MAX)
        printf("Number is too large.\n");
    else if (num < I_MIN)
        printf("Number is too small.\n");
}

int main (void)
{
    long int num;
    scanf("%ld", &num);
    
    value(num);
    
    return 0;
}

