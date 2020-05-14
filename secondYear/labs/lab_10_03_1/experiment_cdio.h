#ifndef __EXPERIMENT_CDIO_H__
#define __EXPERIMENT_CDIO_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs_t.h"
#include "errno.h"

int date_input(date_t *const date);

char *surname_input();

double *readings_input(int *const readings_number);

int experiment_input(experiment_t *const experiment);

int array_of_e9s_input(array_of_e9s_t *array_of_e9s);

void date_el_right_output(FILE *p_out, const int el);

void experiment_output(FILE *p_out, const experiment_t experiment);

void array_of_e9s_output(FILE *p_out, const array_of_e9s_t array_of_e9s);

int check_rule(const date_t date);

int array_of_e9s_el_delete(array_of_e9s_t *array_of_e9s);

void array_of_e9s_free(array_of_e9s_t array_of_e9s);

#endif
