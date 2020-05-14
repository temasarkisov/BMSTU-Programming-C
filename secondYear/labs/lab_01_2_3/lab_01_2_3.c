#include <stdio.h>
#define R_RT 0

int main(void)
{
    float r1, r2, r3, r_abs; //Сопротивления.

    printf("Input R1: ");
    scanf("%f", &r1);
    printf("Input R2: ");
    scanf("%f", &r2);
    printf("Input R3: ");
    scanf("%f", &r3);

    r_abs = 1 / r1 + 1 / r2 + 1 / r3;
    r_abs = 1 / r_abs;

    printf("Parallel connection: %.5f \n", r_abs);
    return R_RT;
}
