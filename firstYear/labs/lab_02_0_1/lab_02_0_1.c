#include <stdio.h>
#define R_RT 0
#define R_WG 1

long double power(int x, int y)
{
    long double p = 1;

    if (y > 0)
        for (int i = 0; i < y; i++)
            p = p * x;

    if (y < 0)
        for (int i = 0; i > y; i--)
            p = p / x;

    return p;
}

int main(void)
{
    int a, n, num;
    long double result;

    num = scanf("%d%d", &a, &n);
    if (num == 2 && n > 0)
    {
        result = power(a, n);
        printf("%.0Lf\n", result);

        return R_RT;
    }

    return R_WG;
}
