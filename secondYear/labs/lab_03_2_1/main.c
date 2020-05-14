#include<stdio.h>

#define ZERO 0
#define RIGHT_INT 1
#define SUCCESS 0
#define VALUE_ERROR -1

int max_number_index(FILE* f, int *max_ind)
{
    int value, max_value, ind = 1;
    
    if (fscanf(f, "%d", &value) == RIGHT_INT)
    {
        max_value = value;
        *max_ind = ind;
    
        while (fscanf(f, "%d", &value) == RIGHT_INT)
        {
            ind++;

            if (value > max_value)
            {
                max_value = value;
                *max_ind = ind;
            }
        }
    }
    else
        return VALUE_ERROR;
    
    return SUCCESS;
}

int main()
{
    int max_ind;
    int err_code = max_number_index(stdin, &max_ind);
    if (err_code == SUCCESS)
    {
        printf("%d", max_ind);
        return SUCCESS;
    }
    return err_code;
}




