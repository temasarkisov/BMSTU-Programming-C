#include "test_auxiliary.h"

void experiment_formation(experiment_t *experiment, const int day, const int month, 
const int year, char *surname, const int readings_number, double *readings)
{
    experiment->date.day = day;
    experiment->date.month = month;
    experiment->date.year = year;
    
    experiment->surname = (char*) calloc(MAX_SYMB_NUM, sizeof(char));
    for (int i = 0; i < strlen(surname); i++)
        experiment->surname[i] = surname[i];
    
    experiment->readings_number = readings_number;
    experiment->readings = (double*) calloc(readings_number, sizeof(double));
    for (int i = 0; i < readings_number; i++)
        experiment->readings[i] = readings[i];
}

int is_array_of_e9s_equal(const array_of_e9s_t array_of_e9s_1, const array_of_e9s_t array_of_e9s_2)
{
    if (array_of_e9s_1.e9s_number != array_of_e9s_2.e9s_number)
        return NOT_EQ;

    for (int i = 0; i < array_of_e9s_1.e9s_number; i++)
    {
        if (array_of_e9s_1.array_of_e9s[i].date.day != array_of_e9s_2.array_of_e9s[i].date.day ||
            array_of_e9s_1.array_of_e9s[i].date.month != array_of_e9s_2.array_of_e9s[i].date.month ||
            array_of_e9s_1.array_of_e9s[i].date.year != array_of_e9s_2.array_of_e9s[i].date.year)
            return NOT_EQ;
        if (strcmp(array_of_e9s_1.array_of_e9s[i].surname, array_of_e9s_2.array_of_e9s[i].surname) != 0)
            return NOT_EQ;
        if (array_of_e9s_1.array_of_e9s[i].readings_number != array_of_e9s_2.array_of_e9s[i].readings_number)
            return NOT_EQ;
        for (int j = 0; j < array_of_e9s_1.array_of_e9s[i].readings_number; j++)
            if (array_of_e9s_1.array_of_e9s[i].readings[j] != array_of_e9s_2.array_of_e9s[i].readings[j])
                return NOT_EQ;
    }

    return EQ;
}

int array_of_e9s_el_delete_test(array_of_e9s_t *array_of_e9s_cur, array_of_e9s_t array_of_e9s_res)
{
    array_of_e9s_el_delete(array_of_e9s_cur);

    if (is_array_of_e9s_equal(*array_of_e9s_cur, array_of_e9s_res) == EQ)
    {
        array_of_e9s_free(*(array_of_e9s_cur));
        array_of_e9s_free(array_of_e9s_res);
        return TEST_PASSED;
    }

    array_of_e9s_free(*(array_of_e9s_cur));
    array_of_e9s_free(array_of_e9s_res);
    return TEST_FAILED;
}

int array_of_e9s_el_averaged_test(array_of_e9s_t array_of_e9s_cur, array_of_e9s_t array_of_e9s_res)
{
    array_of_e9s_el_averaged(&array_of_e9s_cur);

    if (is_array_of_e9s_equal(array_of_e9s_cur, array_of_e9s_res) == EQ)
    {
        array_of_e9s_free(array_of_e9s_cur);
        array_of_e9s_free(array_of_e9s_res);
        return TEST_PASSED;
    }

    array_of_e9s_free(array_of_e9s_cur);
    array_of_e9s_free(array_of_e9s_res);
    return TEST_FAILED;
}

int sort_by_date_test(array_of_e9s_t array_of_e9s_cur, array_of_e9s_t array_of_e9s_res)
{
    cocktail_sort(&array_of_e9s_cur, compare_by_date);

    if (is_array_of_e9s_equal(array_of_e9s_cur, array_of_e9s_res) == EQ)
    {
        array_of_e9s_free(array_of_e9s_cur);
        array_of_e9s_free(array_of_e9s_res);
        return TEST_PASSED;
    }

    array_of_e9s_free(array_of_e9s_cur);
    array_of_e9s_free(array_of_e9s_res);
    return TEST_FAILED;
}

int sort_by_technician_test(array_of_e9s_t array_of_e9s_cur, array_of_e9s_t array_of_e9s_res)
{
    cocktail_sort(&array_of_e9s_cur, compare_by_surname);

    if (is_array_of_e9s_equal(array_of_e9s_cur, array_of_e9s_res) == EQ)
    {
        array_of_e9s_free(array_of_e9s_cur);
        array_of_e9s_free(array_of_e9s_res);
        return TEST_PASSED;
    }

    array_of_e9s_free(array_of_e9s_cur);
    array_of_e9s_free(array_of_e9s_res);
    return TEST_FAILED;
}

int sort_by_data_test(array_of_e9s_t array_of_e9s_cur, array_of_e9s_t array_of_e9s_res)
{
    cocktail_sort(&array_of_e9s_cur, compare_by_readings);

    if (is_array_of_e9s_equal(array_of_e9s_cur, array_of_e9s_res) == EQ)
    {
        array_of_e9s_free(array_of_e9s_cur);
        array_of_e9s_free(array_of_e9s_res);
        return TEST_PASSED;
    }

    array_of_e9s_free(array_of_e9s_cur);
    array_of_e9s_free(array_of_e9s_res);
    return TEST_FAILED;
}
