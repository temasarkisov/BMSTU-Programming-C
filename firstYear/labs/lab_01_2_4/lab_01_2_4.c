#include <stdio.h>
#define K 60  
#define R_RT 0

int main(void)
{
    int sec, h, min; //Секунды, часы, минуты.

    printf("Input seconds: ");
    scanf("%d", &sec);

    min = sec / K;
    h = min / K;
    min = min % K;
    sec = sec % K;

    printf("h = %d\nmin = %d\nsec = %d\n", h, min, sec);

    return R_RT;
}
