#ifndef __EXPERIMENT_SORT_H__
#define __EXPERIMENT_SORT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs_t.h"
#include "errno.h"

int compare_by_surname(const experiment_t experiment_1, const experiment_t experiment_2);

int compare_by_date(const experiment_t experiment_1, const experiment_t experiment_2);

int compare_by_readings(const experiment_t experiment_1, const experiment_t experiment_2);

void cocktail_sort(array_of_e9s_t *const array_of_e9s, int (*compare_by)(const experiment_t, const experiment_t));

#endif
