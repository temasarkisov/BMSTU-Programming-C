// От -100 до 100
// Пузырёк

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define VALUES_NUMBER 100
#define RIGHT_NUMBER_ARGS 3
#define ZERO 0
#define RIGHT_READ 1
#define SUCCESS 0
#define CREATE_ERROR -1
#define READ_ERROR -2
#define EMPTY_ERROR -3
#define WRONG_ARGS_ERROR -4
#define WRONG_NUMBER_ARGS_ERROR -5
#define NO_ERROR 0
#define TRUE 1
#define FALSE 0

void file_filling(FILE *file_bin)
{
    srand(time(NULL));
    int value;

    for (int i = ZERO; i < VALUES_NUMBER; i++)
    {
        value = rand() / 201 - 100;
        fwrite(&value, sizeof(value), 1, file_bin);
    }
}

void file_reading(FILE *file_bin)
{
    int value;

    while (fread(&value, sizeof(value), 1, file_bin) == RIGHT_READ)
        printf("%d\n", value);
}

int get_number_by_pos(FILE *file_bin, int position)
{
    int value;

    fseek(file_bin, position * sizeof(value), SEEK_SET);
    fread(&value, sizeof(value), 1, file_bin);

    return value;
}

void set_number_by_pos(FILE *file_bin, int position, int value)
{
    fseek(file_bin, position * sizeof(value), SEEK_SET);
    fwrite(&value, sizeof(value), 1, file_bin);
}

int file_length(FILE *file_bin)
{
    int value, length = ZERO;

    while (fread(&value, sizeof(value), 1, file_bin) == RIGHT_READ)
        length++;
    rewind(file_bin);

    return length;
}

void file_sort(FILE *file_bin)
{
    int length = file_length(file_bin);

    for (int i = ZERO; i < length - 1; i++)
        for (int j = ZERO; j < length - 1; j++)
            if (get_number_by_pos(file_bin, j) > get_number_by_pos(file_bin, j + 1))
            {
                int value_b = get_number_by_pos(file_bin, j);
                int value_a = get_number_by_pos(file_bin, j + 1);
                set_number_by_pos(file_bin, j, value_a);
                set_number_by_pos(file_bin, j + 1, value_b);
            }
}

int string_compare(const char *const string_1, const char *const string_2)
{
    for (int i = ZERO; string_1[i] != '\0' && string_2[i]; i++)
        if (string_1[i] != string_2[i])
            return FALSE;

    return TRUE;
}

int main(int argc, char **argv)
{
    FILE *file_bin;

    if (argc != RIGHT_NUMBER_ARGS)
        return WRONG_NUMBER_ARGS_ERROR;

    if (string_compare(argv[1], "c"))
    {
        file_bin = fopen(argv[2], "wb");
        if (file_bin)
        {
            file_filling(file_bin);
            fclose(file_bin);
            return NO_ERROR;
        }
        else
            return CREATE_ERROR;
    }
    else if (string_compare(argv[1], "p"))
    {
        file_bin = fopen(argv[2], "rb");
        if (file_bin && file_length(file_bin))
        {
            file_reading(file_bin);
            fclose(file_bin);
            return NO_ERROR;
        }
        else if (!file_bin)
            return READ_ERROR;
        else
            return EMPTY_ERROR;
    }
    else if (string_compare(argv[1], "s"))
    {
        file_bin = fopen(argv[2], "rb+");
        if (file_bin && file_length(file_bin))
        {
            file_sort(file_bin);
            fclose(file_bin);
            return NO_ERROR;
        }
        else if (!file_bin)
            return READ_ERROR;
        else
            return EMPTY_ERROR;
    }
    return WRONG_ARGS_ERROR;
}
