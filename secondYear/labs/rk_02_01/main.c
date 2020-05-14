#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STR_NUM 6
#define MAX_COL_NUM 6
#define MAX_EL_NUM 36
#define PARAM 3
#define RIGHT_SCAN 1
#define ZERO 0
#define FALSE 0
#define TRUE 1

void matrix_output(int matrix[][PARAM])
{
    for (int i = ZERO; i < MAX_EL_NUM; i++)
    {
        for (int j = ZERO; j < PARAM; j++)
            printf("%d ", matrix[i][j]);
        printf("%c", '\n');
    }
}

int is_zero_matrix(int matrix[][MAX_COL_NUM], int x_top, int y_top, int x_btn, int y_btn)
{
    for (int i = y_top; i <= y_btn; i++)
	    for (int j = x_top; j <= x_btn; j++)
	        if (matrix[i][j] != 0)
		        return FALSE;

    return TRUE;
}

int square_to_matrix(int matrix[][MAX_COL_NUM], int param_out_matrix[][PARAM], int x_top, int y_top, int x_btn, int y_btn, int number)
{
    static int out_num = ZERO;

    for (int i = y_top; i <= y_btn; i++)
        for (int j = x_top; j <= x_btn; j++)
        {
            param_out_matrix[out_num][0] = i;
            param_out_matrix[out_num][1] = j;
            param_out_matrix[out_num][2] = number;
            //printf("%d %d %d\n", i, j, matrix[i][j]);
            out_num++;
        }

    return out_num;
}

int max_size_def(int matrix[][MAX_COL_NUM], int number) 
{
    int max_size = ZERO;

    for (int i = ZERO; i < MAX_STR_NUM; i++)
        for (int j = ZERO; j < MAX_COL_NUM; j++)
	        for (int k = i; k < MAX_STR_NUM; k++)
		        for(int l = j; l < MAX_COL_NUM; l++)
	    	        if (is_zero_matrix(matrix, i, j, k, l) && (i - k) == (j - l))
	 	                if (abs(i - k) * abs(j - l) >= max_size)
			            {
                            max_size = abs(i - k) * abs(j - l);
			            }
    
    return max_size;
}

int out_param_matrix_formation(int matrix[][MAX_COL_NUM], int out_param_matrix[][PARAM], int number)
{
    int x_top, y_top, x_btn, y_btn;
    int max_size = max_size_def(matrix, number);
    int out_num;

    for (int i = ZERO; i < MAX_STR_NUM; i++)
        for (int j = ZERO; j < MAX_COL_NUM; j++)
            for (int k = i; k < MAX_STR_NUM; k++)
                for(int l = j; l < MAX_COL_NUM; l++)
                    if (is_zero_matrix(matrix, i, j, k, l) && (i - k) == (j - l))
                        if (abs(i - k) * abs(j - l) == max_size)
                        {
                            x_top = i;
                            y_top = j;
                            x_btn = k;
                            y_btn = l;
                            out_num = square_to_matrix(matrix, out_param_matrix, x_top, y_top, x_btn, y_btn, number); 
                        }
    
    return out_num;
}

void file_formation(FILE *file, int matrix[][MAX_COL_NUM])
{
    for (int i = ZERO; i < MAX_STR_NUM; i++)
    {
	    for (int j = ZERO; j < MAX_COL_NUM; j++)
	        fprintf(file, "%d ", matrix[i][j]);
    	fprintf(file, "%c", '\n');
    }
}

int matrix_input(FILE *file_in, int matrix[][PARAM])
{
    int str_num = ZERO;
    
    while (fscanf(file_in, "%d", &matrix[str_num][0]) == RIGHT_SCAN)
    {
        fscanf(file_in, "%d", &matrix[str_num][1]);
        fscanf(file_in, "%d", &matrix[str_num][2]);
        str_num++;
    }
    
    return str_num;
}

void matrix_formation(int param_matrix[][PARAM], int matrix[][MAX_COL_NUM], int num)
{
    for (int i = ZERO; i < MAX_STR_NUM; i++)
        for (int j = ZERO; j < MAX_COL_NUM; j++)
            matrix[i][j] = 0;

    for (int k = ZERO; k < num; k++)
       matrix[param_matrix[k][0]][param_matrix[k][1]] = param_matrix[k][2];
}

void out_matrix_formation(int out_param_matrix[][PARAM], int matrix[][MAX_COL_NUM], int out_num)
{
    for (int k = ZERO; k < out_num; k++)
       matrix[out_param_matrix[k][0]][out_param_matrix[k][1]] = out_param_matrix[k][2];
}

int main()
{
    int num, out_num;

    FILE *file_in;
    FILE *file_out;
    file_in = fopen("in.txt", "r");
    file_out = fopen("out.txt", "w");
    if (file_in && file_out)
    {
        int param_matrix[MAX_EL_NUM][PARAM];
        int matrix[MAX_STR_NUM][MAX_COL_NUM];
        int out_param_matrix[MAX_EL_NUM][PARAM];

        num = matrix_input(file_in, param_matrix);

        matrix_formation(param_matrix, matrix, num);
        out_num = out_param_matrix_formation(matrix, out_param_matrix, num);
        out_matrix_formation(out_param_matrix, matrix, out_num);
        file_formation(file_out, matrix);
    
        fclose(file_in);
        fclose(file_out);
    }
}
