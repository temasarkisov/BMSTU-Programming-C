#include "test_auxiliary.h"

int delete_one_el_test()
{
    array_of_e9s_t array_of_e9s_cur;
    array_of_e9s_cur.e9s_number = 2;
    array_of_e9s_cur.array_of_e9s = (experiment_t*) malloc(array_of_e9s_cur.e9s_number * sizeof(experiment_t));

    double readings1[] = { 1.5, 2.3 };
    double readings2[] = { 4.5, 3.3, 8.8 };
    experiment_formation(&array_of_e9s_cur.array_of_e9s[0], 2, 2, 1999, "Krivoy", 2, readings1);
    experiment_formation(&array_of_e9s_cur.array_of_e9s[1], 2, 2, 1977, "Pryamoy", 3, readings2);

    array_of_e9s_t array_of_e9s_res;
    array_of_e9s_res.e9s_number = 1;
    array_of_e9s_res.array_of_e9s = (experiment_t*) malloc(array_of_e9s_res.e9s_number * sizeof(experiment_t));
    
    experiment_formation(&array_of_e9s_res.array_of_e9s[0], 2, 2, 1999, "Krivoy", 2, readings1);

    if (array_of_e9s_el_delete_test(&array_of_e9s_cur, array_of_e9s_res) == TEST_PASSED)
        return TEST_PASSED;

    return TEST_FAILED;
}

int delete_more_than_one_el_test()
{
    array_of_e9s_t array_of_e9s_cur;
    array_of_e9s_cur.e9s_number = 3;
    array_of_e9s_cur.array_of_e9s = (experiment_t*) malloc(array_of_e9s_cur.e9s_number * sizeof(experiment_t));

    double readings1[] = { 1.5, 2.3 };
    double readings2[] = { 4.5, 3.3, 8.8 };
    double readings3[] = { 5, 32.3 };
    experiment_formation(&array_of_e9s_cur.array_of_e9s[0], 5, 10, 1999, "Krivoy", 2, readings1);
    experiment_formation(&array_of_e9s_cur.array_of_e9s[1], 2, 2, 1993, "Pryamoy", 3, readings2);
    experiment_formation(&array_of_e9s_cur.array_of_e9s[2], 1, 2, 1993, "Sokolov", 2, readings3);

    array_of_e9s_t array_of_e9s_res;
    array_of_e9s_res.e9s_number = 2;
    array_of_e9s_res.array_of_e9s = (experiment_t*) malloc(array_of_e9s_res.e9s_number * sizeof(experiment_t));
    
    experiment_formation(&array_of_e9s_res.array_of_e9s[0], 5, 10, 1999, "Krivoy", 2, readings1);
    experiment_formation(&array_of_e9s_res.array_of_e9s[1], 2, 2, 1993, "Pryamoy", 3, readings2);

    if (array_of_e9s_el_delete_test(&array_of_e9s_cur, array_of_e9s_res) == TEST_PASSED)
        return TEST_PASSED;

    return TEST_FAILED;
}

int averaged_int_values_test()
{
    array_of_e9s_t array_of_e9s_cur;
    array_of_e9s_cur.e9s_number = 1;
    array_of_e9s_cur.array_of_e9s = (experiment_t*) malloc(array_of_e9s_cur.e9s_number * sizeof(experiment_t));

    double readings1[] = { 2, 4 };
    experiment_formation(&array_of_e9s_cur.array_of_e9s[0], 2, 2, 1999, "Krivoy", 2, readings1);

    array_of_e9s_t array_of_e9s_res;
    array_of_e9s_res.e9s_number = 1;
    array_of_e9s_res.array_of_e9s = (experiment_t*) malloc(array_of_e9s_res.e9s_number * sizeof(experiment_t));
    
    double readings1_res[] = { 3 };
    experiment_formation(&array_of_e9s_res.array_of_e9s[0], 2, 2, 1999, "Krivoy", 1, readings1_res);

    if (array_of_e9s_el_averaged_test(array_of_e9s_cur, array_of_e9s_res) == TEST_PASSED)
        return TEST_PASSED;

    return TEST_FAILED;
}

int averaged_float_values_test()
{
    array_of_e9s_t array_of_e9s_cur;
    array_of_e9s_cur.e9s_number = 1;
    array_of_e9s_cur.array_of_e9s = (experiment_t*) malloc(array_of_e9s_cur.e9s_number * sizeof(experiment_t));

    double readings2[] = { 4.5, 3.3, 8.8 };
    experiment_formation(&array_of_e9s_cur.array_of_e9s[0], 2, 2, 1977, "Pryamoy", 3, readings2);

    array_of_e9s_t array_of_e9s_res;
    array_of_e9s_res.e9s_number = 1;
    array_of_e9s_res.array_of_e9s = (experiment_t*) malloc(array_of_e9s_res.e9s_number * sizeof(experiment_t));
    
    double readings2_res_el = (4.5 + 3.3 + 8.8) / 3;
    double readings2_res[] = { readings2_res_el };
    experiment_formation(&array_of_e9s_res.array_of_e9s[0], 2, 2, 1977, "Pryamoy", 1, readings2_res);

    if (array_of_e9s_el_averaged_test(array_of_e9s_cur, array_of_e9s_res) == TEST_PASSED)
        return TEST_PASSED;

    return TEST_FAILED;
}

int sort_by_date_cocktail_test()
{
    array_of_e9s_t array_of_e9s_cur;
    array_of_e9s_cur.e9s_number = 2;
    array_of_e9s_cur.array_of_e9s = (experiment_t*) malloc(array_of_e9s_cur.e9s_number * sizeof(experiment_t));

    double readings1[] = { 1.5, 2.3 };
    double readings2[] = { 4.5, 3.3, 8.8 };
    experiment_formation(&array_of_e9s_cur.array_of_e9s[0], 2, 2, 1999, "Krivoy", 2, readings1);
    experiment_formation(&array_of_e9s_cur.array_of_e9s[1], 2, 2, 1977, "Pryamoy", 3, readings2);

    array_of_e9s_t array_of_e9s_res;
    array_of_e9s_res.e9s_number = 2;
    array_of_e9s_res.array_of_e9s = (experiment_t*) malloc(array_of_e9s_res.e9s_number * sizeof(experiment_t));

    double readings1_res[] = { 4.5, 3.3, 8.8 };
    double readings2_res[] = { 1.5, 2.3 };
    experiment_formation(&array_of_e9s_res.array_of_e9s[0], 2, 2, 1977, "Pryamoy", 3, readings1_res);
    experiment_formation(&array_of_e9s_res.array_of_e9s[1], 2, 2, 1999, "Krivoy", 2, readings2_res);

    if (sort_by_date_test(array_of_e9s_cur, array_of_e9s_res) == TEST_PASSED)
        return TEST_PASSED;

    return TEST_FAILED;
}

int sort_by_t8n_cocktail_test()
{
    array_of_e9s_t array_of_e9s_cur;
    array_of_e9s_cur.e9s_number = 2;
    array_of_e9s_cur.array_of_e9s = (experiment_t*) malloc(array_of_e9s_cur.e9s_number * sizeof(experiment_t));

    double readings1[] = { 1.5, 2.3 };
    double readings2[] = { 4.5, 3.3, 8.8 };
    experiment_formation(&array_of_e9s_cur.array_of_e9s[0], 2, 2, 1999, "Pryamoy", 2, readings1);
    experiment_formation(&array_of_e9s_cur.array_of_e9s[1], 2, 2, 1977, "Krivoy", 3, readings2);

    array_of_e9s_t array_of_e9s_res;
    array_of_e9s_res.e9s_number = 2;
    array_of_e9s_res.array_of_e9s = (experiment_t*) malloc(array_of_e9s_res.e9s_number * sizeof(experiment_t));

    experiment_formation(&array_of_e9s_res.array_of_e9s[0], 2, 2, 1977, "Krivoy", 3, readings2);
    experiment_formation(&array_of_e9s_res.array_of_e9s[1], 2, 2, 1999, "Pryamoy", 2, readings1); 

    if (sort_by_technician_test(array_of_e9s_cur, array_of_e9s_res) == TEST_PASSED)
        return TEST_PASSED;

    return TEST_FAILED;
}

int sort_by_data_cocktail_test()
{
    array_of_e9s_t array_of_e9s_cur;
    array_of_e9s_cur.e9s_number = 2;
    array_of_e9s_cur.array_of_e9s = (experiment_t*) malloc(array_of_e9s_cur.e9s_number * sizeof(experiment_t));

    double readings1[] = { 4.5 };
    double readings2[] = { 1.5 };
    experiment_formation(&array_of_e9s_cur.array_of_e9s[0], 2, 2, 1999, "Pryamoy", 1, readings1);
    experiment_formation(&array_of_e9s_cur.array_of_e9s[1], 2, 2, 1977, "Krivoy", 1, readings2);

    array_of_e9s_t array_of_e9s_res;
    array_of_e9s_res.e9s_number = 2;
    array_of_e9s_res.array_of_e9s = (experiment_t*) malloc(array_of_e9s_res.e9s_number * sizeof(experiment_t));

    experiment_formation(&array_of_e9s_res.array_of_e9s[0], 2, 2, 1977, "Krivoy", 1, readings2);
    experiment_formation(&array_of_e9s_res.array_of_e9s[1], 2, 2, 1999, "Pryamoy", 1, readings1);

    if (sort_by_data_test(array_of_e9s_cur, array_of_e9s_res) == TEST_PASSED)
        return TEST_PASSED;

    return TEST_FAILED;
}

int main()
{
    int is_failed = 0;

    if (delete_one_el_test() == TEST_FAILED)
    {
        is_failed = 1;
        printf("Test:   delete_one_el_test()    failed.\n");
        printf("Description:   array_of_e9s_el_delete() deleted one element incorrectly.\n");
    }

    if (delete_more_than_one_el_test() == TEST_FAILED)
    {
        is_failed = 1;
        printf("Test:   delete_more_than_one_el_test()    failed.\n");
        printf("Description:   array_of_e9s_el_delete() deleted more than one element incorrectly.\n");
    } 

    if (averaged_int_values_test() == TEST_FAILED)
    {
        is_failed = 1;
        printf("Test:   averaged_int_values_test()    failed.\n");
        printf("Description:   array_of_e9s_el_averaged() averaged integer values incorrectly.\n");
    }

    if (averaged_float_values_test() == TEST_FAILED)
    {
        is_failed = 1;
        printf("Test:   averaged_float_values_test()    failed.\n");
        printf("Description:   array_of_e9s_el_averaged() averaged float values incorrectly.\n");
    }

    if (sort_by_t8n_cocktail_test() == TEST_FAILED)
    {
        is_failed = 1;
        printf("Test:   sort_by_technician_test()    failed.\n");
        printf("Description:   cocktail_sort() sorted by technician incorrectly.\n");
    }

    if (sort_by_data_cocktail_test() == TEST_FAILED)
    {
        is_failed = 1;
        printf("Test:   sort_by_data_test()    failed.\n");
        printf("Description:   cocktail_sort() sorted by data incorrectly.\n");
    }

    if (sort_by_date_cocktail_test() == TEST_FAILED)
    {
        is_failed = 1;
        printf("Test:   sort_by_date_test()    failed.\n");
        printf("Description:   cocktail_sort() sorted by date incorrectly.\n");
    }

    if (is_failed == 0)
    {
        return ALL_TESTS_PASSED;
    } 

    return NOT_ALL_TESTS_PASSED;
}
