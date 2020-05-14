#include<stdio.h>
#include<math.h>

#define ZERO 0
#define ONE 1
#define RIGHT_INPUT 1
#define SUCCESS 0
#define ERROR_SYMBOL -1
#define EXIST_ERROR -2
#define EMPTY_ERROR -3
#define VALUE_ERROR -4
#define NO_FILE_NAME_ERROR -5
#define NO_ERROR 1

double file_average(FILE *input_file)
{
    int num = ZERO;
    double value;
    double sum = ZERO;
    double average;
    
    rewind(input_file);

    int scanf_check = fscanf(input_file, "%lf", &value);   
    while (scanf_check == RIGHT_INPUT)
    {
        sum += value;
        num++;
        scanf_check = fscanf(input_file, "%lf", &value);
    }
    
    if (!scanf_check)
        return ERROR_SYMBOL;
    else
    {
        average = sum / num;
        return average;
    }
}

double file_closest_number(FILE *input_file)
{
    double value, res_value, diff, min_diff;
    double average = file_average(input_file);
    
    if (average != ERROR_SYMBOL)
    {
        rewind(input_file);

        int scanf_check = fscanf(input_file, "%lf", &value);
        res_value = value;
        min_diff = fabs(average - value);
        
        while (scanf_check == RIGHT_INPUT)
        {
            diff = fabs(average - value);
            if (diff < min_diff)
            {
                min_diff = diff;
                res_value = value;
            }
            scanf_check = fscanf(input_file, "%lf", &value);
        }   
    
        return res_value;
    }
    else 
        return ERROR_SYMBOL;
}

int main(int argc, char **argv)
{
    double res_value;
    
    if (argc == 1)
        return NO_FILE_NAME_ERROR;
    
    FILE* input_file = fopen(argv[1], "r");
    
    if (!input_file)
    {
        fclose(input_file);
        return EXIST_ERROR;
    }
    
    char check_empty = fgetc(input_file);
    if (check_empty == EOF)
    {
        fclose(input_file);
        return EMPTY_ERROR;
    }
    
    res_value = file_closest_number(input_file);
    if (res_value != ERROR_SYMBOL)
    {
        printf("%lf\n", res_value);
        fclose(input_file);
        return SUCCESS;
    }
    else
    {
        return ERROR_SYMBOL;
    }
}


