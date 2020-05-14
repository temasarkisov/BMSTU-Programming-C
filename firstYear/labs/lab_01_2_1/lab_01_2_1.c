#include <stdio.h>
#include <math.h>
#define R_RT 0

int main(void)
{
    float x1, y1, x2, y2, x3, y3; //Координаты вершин треугольника.
    float len_1, len_2, len_3, p; //Длины сторон треугольника.

    printf("Input x1, y1: ");
    scanf("%f %f", &x1, &y1);
    printf("Input x2, y2: ");
    scanf("%f %f", &x2, &y2);
    printf("Input x3, y3: ");
    scanf("%f %f", &x3, &y3);

    len_1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    len_2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    len_3 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    p = len_1 + len_2 + len_3;

    printf("P = %.5f \n", p);
    return R_RT;
}
