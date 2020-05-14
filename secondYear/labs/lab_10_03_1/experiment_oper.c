#include"experiment_oper.h"

int array_of_e9s_el_averaged(array_of_e9s_t *const array_of_e9s)
{
    double average = 0;

    for (int i = 0; i < array_of_e9s->e9s_number; i++)
    {
        for (int j = 0; j < (array_of_e9s->array_of_e9s[i]).readings_number; j++)
            average += (array_of_e9s->array_of_e9s[i]).readings[j];

        average /= (array_of_e9s->array_of_e9s[i]).readings_number;
        (array_of_e9s->array_of_e9s[i]).readings[0] = average;
        (array_of_e9s->array_of_e9s[i]).readings_number = 1;
        average = 0;

        (array_of_e9s->array_of_e9s[i]).readings = (double*) realloc((array_of_e9s->array_of_e9s[i]).readings, sizeof(double));
        if ((array_of_e9s->array_of_e9s[i]).readings == NULL)
            return INV_MEM_ERR;
    }

    return NO_ERR;
}

int key_word_oper(array_of_e9s_t array_of_e9s)
{
    char *key_word = (char*) malloc(MAX_SYMB_NUM * sizeof(char));

    if (!scanf("%s", key_word))
    {
        free(key_word);
        return KEY_EXISTS;
    }
    if (strcmp(key_word, "DATE") == 0)
    {
        cocktail_sort(&array_of_e9s, compare_by_date);
        free(key_word);
        return KEY_EXISTS;
    }
    else if (strcmp(key_word, "TECHNICIAN") == 0)
    {
        cocktail_sort(&array_of_e9s, compare_by_surname);
        free(key_word);
        return KEY_EXISTS;
    }
    else if (strcmp(key_word, "DATA") == 0)
    {
        cocktail_sort(&array_of_e9s, compare_by_readings);
        free(key_word);
        return KEY_EXISTS;
    }

    free(key_word);
    return KEY_ERR;
}

