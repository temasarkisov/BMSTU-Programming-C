#ifndef __STRUCTS_T_H__
#define __STRUCTS_T_H__

typedef struct 
{
    int day;
    int month;
    int year;
} date_t;

typedef struct 
{
    date_t date;
    char *surname;
    int readings_number;
    double *readings;
} experiment_t;

typedef struct 
{
    experiment_t *array_of_e9s;
    int e9s_number;
} array_of_e9s_t;

#endif
