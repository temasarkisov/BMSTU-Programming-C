#include "experiment_sort.h"

int compare_by_surname(const experiment_t experiment_1, const experiment_t experiment_2)
{
    return (strcmp(experiment_1.surname, experiment_2.surname));
}

int compare_by_date(const experiment_t experiment_1, const experiment_t experiment_2)
{
    if (experiment_1.date.year > experiment_2.date.year)
    {
        return 1;
    }
    else if (experiment_1.date.year == experiment_2.date.year && 
        experiment_1.date.month > experiment_2.date.month)
    {
        return 1;
    }
    else if (experiment_1.date.year == experiment_2.date.year && 
        experiment_1.date.month == experiment_2.date.month &&
        experiment_1.date.day > experiment_2.date.day)
    {
        return 1;
    }
    else if (experiment_1.date.year == experiment_2.date.year && 
        experiment_1.date.month == experiment_2.date.month &&
        experiment_1.date.day == experiment_2.date.day)
    {
        return 0;
    }

    return -1;
}

int compare_by_readings(const experiment_t experiment_1, const experiment_t experiment_2)
{
    if (experiment_1.readings[0] > experiment_2.readings[0])
        return 1;
    else if (experiment_1.readings[0] == experiment_2.readings[0])
        return 0;

    return -1;
}

void cocktail_sort(array_of_e9s_t *const array_of_e9s, int (*compare_by)(const experiment_t, const experiment_t))
{
    experiment_t experiment_curr;
    int left_wall = 0;
    int right_wall = array_of_e9s->e9s_number - 1;

    while (left_wall < right_wall)
    {
        for (int i = left_wall; i < right_wall; i++)
        {
            if (compare_by((array_of_e9s->array_of_e9s)[i], (array_of_e9s->array_of_e9s)[i + 1]) > 0)
            {
                experiment_curr = (array_of_e9s->array_of_e9s)[i];
                (array_of_e9s->array_of_e9s)[i] = (array_of_e9s->array_of_e9s)[i + 1];
                (array_of_e9s->array_of_e9s)[i + 1] = experiment_curr;  
            }
        }
        right_wall--;
        
        for (int i = right_wall; i > left_wall; i--)
        {
            if (compare_by((array_of_e9s->array_of_e9s)[i], (array_of_e9s->array_of_e9s)[i - 1]) < 0)
            {
                experiment_curr = (array_of_e9s->array_of_e9s)[i];
                (array_of_e9s->array_of_e9s)[i] = (array_of_e9s->array_of_e9s)[i - 1];
                (array_of_e9s->array_of_e9s)[i - 1] = experiment_curr;  
            }
        }
        left_wall++;
    }
}
