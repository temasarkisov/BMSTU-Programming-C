#include"experiment_cdio.h"

int date_input(date_t *const date)
{
    char symb_curr = '\0';
    int months_max_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char *date_str = (char*) calloc(MAX_SYMB_NUM, sizeof(char));
    if (date_str == NULL)
    {
        return INV_MEM_ERR;
    }
    
    if (!scanf("%s", date_str))
    {
        free(date_str);
        return W_I;
    }    

    if (strlen(date_str) != REQ_STR_SIZE || date_str[DOT_POS_FRT] != '.' || date_str[DOT_POS_SCD] != '.')
    {
        free(date_str);
        return W_I;
    }

    for (int i = 0; i < REQ_STR_SIZE; i++)
    {
        if (i != DOT_POS_FRT && i != DOT_POS_SCD && (date_str[i] < '0' || date_str[i] > '9'))
        {
            free(date_str);
            return W_I;
        }
    }

    if (strcmp(date_str, "00.00.0000") == 0)
    {
        scanf("%c", &symb_curr);
        free(date_str);
        return LAST_EL;
    }

    if (sscanf(date_str, "%d.%d.%d", &date->day, &date->month, &date->year))
    {
        if (date->month <= MIN_MONTH_NUM || date->month > MAX_MONTH_NUM)
        {
            free(date_str);
            return W_I;
        }

        if (date->year < MIN_YEAR_NUM || date->year > MAX_YEAR_NUM)
        {
            free(date_str);
            return W_I;
        }

        if (date->year % 4 != 0 || (date->year % 100 == 0 && date->year % 400 != 0))
        {
            months_max_days[FEB_NUM] = FEB_NORM_DAYS;
        }
        else
        {
            months_max_days[FEB_NUM] = FEB_LEAP_DAYS;
        }
        
        if (date->day <= MIN_DAY_NUM || date->day > months_max_days[date->month - 1])
        {
            free(date_str);
            return W_I;
        }

        scanf("%c", &symb_curr);
        free(date_str); 
        return R_I;
    }
    
    free(date_str);
    return W_I;
}

char *surname_input()
{
    int ind = 0;
    char symb_curr = '\0';
    char *surname = (char*) calloc(MAX_SYMB_NUM, sizeof(char));
    if (surname == NULL)
    {
        return NULL;
    }
    
    while (symb_curr != '\n')
    {
        if (!scanf("%c", &symb_curr))
        {
            free(surname);
            return NULL; 
        }

        if ((symb_curr >= 'A' && symb_curr <= 'Z') || (symb_curr >= 'a' && symb_curr <= 'z'))
        {
            surname[ind] = symb_curr;
            ind++;
        }
        else if (symb_curr != '\n')
        {
            free(surname);
            return NULL;
        }
    }

    return surname;
}

double *readings_input(int *const readings_number)
{
    char symb_curr = '\0';
    int ind = 0;

    if (!scanf("%d", readings_number))
    {
        return NULL;
    }

    if (*readings_number <= 0)
    {
        return NULL;
    }
    
    double *readings = (double*) calloc(*readings_number, sizeof(double));
    if (readings == NULL)
    {
        return NULL;
    }
        
    for (int i = 0; i < *readings_number; i++)
    {
        if (!scanf("%lf", &readings[ind]))
        {
            free(readings);
            return NULL;
        }
        ind++;
    }

    scanf("%c", &symb_curr);
    if (symb_curr == '\n')
        return readings;

    free(readings);
    return NULL;
}  

int experiment_input(experiment_t *const experiment)
{
    int err_no = date_input(&experiment->date);

    if (err_no == W_I)
        return W_I;

    if (err_no == LAST_EL)
        return LAST_EL;
    
    experiment->surname = surname_input();
    if (experiment->surname == NULL)
    {
        return W_I;
    }

    experiment->readings = readings_input(&experiment->readings_number);
    if (experiment->readings == NULL)
    {
        free(experiment->surname);
        return W_I;
    }

    return R_I;
}

int array_of_e9s_input(array_of_e9s_t *array_of_e9s)
{
    experiment_t experiment_curr;
    array_of_e9s->e9s_number = 0;
    int err_no = R_I;

    array_of_e9s->array_of_e9s = (experiment_t*) malloc(sizeof(experiment_t));
    if (array_of_e9s->array_of_e9s == NULL)
    {
        return INV_MEM_ERR;
    }

    while (err_no == R_I)
    {
        err_no = experiment_input(&experiment_curr);
        if (err_no == R_I)
        {
            array_of_e9s->e9s_number++;
            array_of_e9s->array_of_e9s = (experiment_t*) realloc(array_of_e9s->array_of_e9s, (array_of_e9s->e9s_number) * sizeof(experiment_t));
            if (array_of_e9s->array_of_e9s == NULL)
            {
                return W_I;
            }

            (array_of_e9s->array_of_e9s)[array_of_e9s->e9s_number - 1] = experiment_curr;
        }
    }

    if (array_of_e9s->e9s_number > 0 && err_no == LAST_EL)
    {
        return R_I;
    }

    if (array_of_e9s->e9s_number == 0)
    {
        free(array_of_e9s->array_of_e9s);
    }
    else if (array_of_e9s->e9s_number > 0)
    {
        array_of_e9s_free(*array_of_e9s);
    }

    return W_I;
}   

void date_el_right_output(FILE *p_out, const int el)
{
    if (el < 10)
        fprintf(p_out, "0%d.", el);
    else
        fprintf(p_out, "%d.", el);
}

void experiment_output(FILE *p_out, const experiment_t experiment)
{
    date_el_right_output(p_out, experiment.date.day);
    date_el_right_output(p_out, experiment.date.month);
    fprintf(p_out, "%d\n", experiment.date.year);
    
    fprintf(p_out, "%s\n", experiment.surname);

    fprintf(p_out, "%d ", experiment.readings_number);    
    for (int i = 0; i < experiment.readings_number; i++)
        fprintf(p_out, "%lf ", experiment.readings[i]);

    fprintf(p_out, "\n");
}

void array_of_e9s_output(FILE *p_out, const array_of_e9s_t array_of_e9s)
{
    for (int i = 0; i < array_of_e9s.e9s_number; i++)
        experiment_output(p_out, array_of_e9s.array_of_e9s[i]);
}

int check_rule(const date_t date)
{
    if ((date.year < 1993) || (date.year == 1993 && date.month < 2) || 
        (date.year == 1993 && date.month == 2 && date.day == 1))
    {
        return DEL_OK;
    }

    return DEL_SKIP;
}

int array_of_e9s_el_delete(array_of_e9s_t *array_of_e9s)
{
    for (int i = 0; i < array_of_e9s->e9s_number; i++)
        if (check_rule((array_of_e9s->array_of_e9s[i]).date) == DEL_OK) 
        {
            free(array_of_e9s->array_of_e9s[i].surname);
            free(array_of_e9s->array_of_e9s[i].readings);

            for (int j = i; j < array_of_e9s->e9s_number - 1; j++)
                array_of_e9s->array_of_e9s[j] = array_of_e9s->array_of_e9s[j + 1];

            i--;
            (array_of_e9s->e9s_number)--;
            if (array_of_e9s->e9s_number == 0)
            {
                return DEL_ERR;
            }
        }
            
    array_of_e9s->array_of_e9s = (experiment_t*) realloc(array_of_e9s->array_of_e9s, (array_of_e9s->e9s_number) * sizeof(experiment_t));
    if (array_of_e9s->array_of_e9s == NULL)
    {
        return INV_MEM_ERR;
    } 

    return NO_ERR;
}

void array_of_e9s_free(array_of_e9s_t array_of_e9s)
{
    for (int i = 0; i < array_of_e9s.e9s_number; i++)
    {
        free((array_of_e9s.array_of_e9s)[i].surname);
        free((array_of_e9s.array_of_e9s)[i].readings);
    }
 
    free(array_of_e9s.array_of_e9s);
}
