#include<stdio.h>
#include<math.h>
#define R_RT 0
#define R_WG 1
#define TR_ZERO 0
#define TR_ONE 1
#define TR_TWO 2
#define NO_ERROR 1
#define ERROR 0

float len_sq(float a1, float b1, float a2, float b2)
{
    float len;
    len = (a2 - a1) * (a2 - a1) + (b2 - b1) * (b2 - b1);
    
    return len;
}

float check_data(float a1, float a2, float a3)
{
    float result = (a3 - a1) / (a2 - a1);
    
    return result;
}

int triangle_definition(float a1, float b1, float a2, float b2, float a3, float b3)
{
    float len_1_sq, len_2_sq, len_3_sq;
    len_1_sq = len_sq(a1, b1, a2, b2);
    len_2_sq = len_sq(a1, b1, a3, b3);
    len_3_sq = len_sq(a2, b2, a3, b3);
    
    if ((len_1_sq + len_2_sq >= len_3_sq) &&
        (len_1_sq + len_3_sq >= len_2_sq) &&
        (len_2_sq + len_3_sq >= len_1_sq))
    {
        if ((len_1_sq + len_2_sq == len_3_sq) ||
            (len_1_sq + len_3_sq == len_2_sq) ||
            (len_2_sq + len_3_sq == len_1_sq))
            return TR_ONE;
        else
            return TR_ZERO;
    }
    else
        return TR_TWO;
}

int main(void)
{
    float x1, y1, x2, y2, x3, y3;
    int num;
    
    num = scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);

    if ((num == 6) && (check_data(y1, y2, y3) != check_data(x1, x2, x3)) && 
        (check_data(y1, y3, y2) != check_data(x1, x3, x2)) && 
        (x1 != x2 || x1 != x3) && (y1 != y2 || y1 != y3))
    {
        int tri_def = triangle_definition(x1, y1, x2, y2, x3, y3);
        printf("%d\n", tri_def);
        
        return R_RT;
    }
    
    return R_WG;
}
