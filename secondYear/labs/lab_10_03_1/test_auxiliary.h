#ifndef __TEST_AUXILIARY_H__
#define __TEST_AUXILIARY_H__

#include <stdio.h>
#include <stdlib.h>

#include "structs_t.h"
#include "experiment_sort.h"

int array_of_e9s_el_delete(array_of_e9s_t *array_of_e9s);

void array_of_e9s_free(array_of_e9s_t array_of_e9s);

int array_of_e9s_el_averaged(array_of_e9s_t *const array_of_e9s);

void experiment_formation(experiment_t *experiment, const int day, const int month, 
const int year, char *surname, const int readings_number, double *readings);

int is_array_of_e9s_equal(const array_of_e9s_t array_of_e9s_1, const array_of_e9s_t array_of_e9s_2);

int array_of_e9s_el_delete_test(array_of_e9s_t *array_of_e9s_cur, array_of_e9s_t array_of_e9s_res);

int array_of_e9s_el_averaged_test(array_of_e9s_t array_of_e9s_cur, array_of_e9s_t array_of_e9s_res);

int sort_by_date_test(array_of_e9s_t array_of_e9s_cur, array_of_e9s_t array_of_e9s_res);

int sort_by_technician_test(array_of_e9s_t array_of_e9s_cur, array_of_e9s_t array_of_e9s_res);

int sort_by_data_test(array_of_e9s_t array_of_e9s_cur, array_of_e9s_t array_of_e9s_res);

#endif
