#include<stdio.h>
#include<string.h>

#define ZERO 0
#define NO_ERROR 0
#define TRUE 1
#define FALSE 0
#define RIGHT_SCAN 1
#define MAX_NAME_SIZE 31
#define MAX_PRODUCER_SIZE 16

#define OPEN_ERROR -1
#define EMPTY_ERROR -2
#define WRONG_ARGS_ERROR 53

typedef unsigned int u_i;
typedef struct
{
    char name[MAX_NAME_SIZE];
    char producer[MAX_PRODUCER_SIZE];
    u_i price;
    u_i number;
} product;

// sb():

int file_size_bin(FILE *file_in)
{
    int size = ZERO;
    product el;

    while (fread(&el, sizeof(product), 1, file_in) == RIGHT_SCAN)
        size++;

    rewind(file_in);

    return size;
}

product get_number_by_pos(FILE *file_in, int position)
{
    product el;

    fseek(file_in, position * sizeof(product), SEEK_SET);
    fread(&el, sizeof(product), 1, file_in);

    return el;
}

void set_number_by_pos(FILE *file_in, const int position, product el)
{
    fseek(file_in, position * sizeof(product), SEEK_SET);
    fwrite(&el, sizeof(product), 1, file_in);
}

void switch_numbers_by_pos_bin(FILE *file, int pos_1, int pos_2)
{
    product el_1 = get_number_by_pos(file, pos_1);
    product el_2 = get_number_by_pos(file, pos_2);
    set_number_by_pos(file, pos_1, el_2);
    set_number_by_pos(file, pos_2, el_1);
}

void file_sort_bin(FILE *file_in, const int size)
{
    product el_1, el_2;

    for (int i = ZERO; i < size - 1; i++)
        for (int j = ZERO; j < size - 1; j++)
        {
            el_1 = get_number_by_pos(file_in, j);
            el_2 = get_number_by_pos(file_in, j + 1);

            if (el_1.price < el_2.price)
                switch_numbers_by_pos_bin(file_in, j, j + 1);
            else if (el_1.price == el_2.price && el_1.number <= el_2.number)
                switch_numbers_by_pos_bin(file_in, j, j + 1);
        }

    rewind(file_in);
}

void file_formation_bin(FILE *file_in, FILE *file_out)
{
    product el;

    while (fread(&el, sizeof(product), 1, file_in) == RIGHT_SCAN)
        fwrite(&el, sizeof(product), 1, file_out);

    rewind(file_in);
    rewind(file_out);
}

void sb(FILE *file_in, FILE *file_out)
{
    int size = file_size_bin(file_in);

    file_sort_bin(file_in, size);
    file_formation_bin(file_in, file_out);
}

// fb():

int is_name(char *name, char *string)
{
    int name_len = strlen(name);
    int string_len = strlen(string);
    
    if (string_len <= name_len)
    {
        for (int i = string_len - 1; i >= ZERO; i--)
        {
            if (string[i] != name[name_len - 1])
                return FALSE;
            name_len -= 1;
        }
    }
    else
        return FALSE;
    
    return TRUE;
}

void file_output_by_name_bin(FILE *file_in, char *string)
{
    product el;

    while (fread(&el, sizeof(product), 1, file_in) == RIGHT_SCAN)
        if (is_name(el.name, string))
        {
            printf("%s\n", el.name);
            printf("%s\n", el.producer);
            printf("%u\n", el.price);
            printf("%u\n", el.number);
        }

    rewind(file_in);
}

void fb(FILE *file_in, char *string)
{
    file_output_by_name_bin(file_in, string);
}

// ab():

product new_el_input()
{
    product new_el;
    
    scanf("%s", new_el.name);
    scanf("%s", new_el.producer);
    scanf("%u", &new_el.price);
    scanf("%u", &new_el.number);
    
    return new_el;
}

void file_addition_bin(FILE *file_in, const int size, const product new_el)
{
    product el;
    int check = FALSE;

    for (int i = ZERO; i < size; i++)
    {
        el = get_number_by_pos(file_in, i);

        if (new_el.price < el.price || (new_el.price == el.price && new_el.number <= el.number))
        {
            if (i == size - 1)
            {
                set_number_by_pos(file_in, size, new_el);
            }
            else
            {
                check = TRUE;
            }
        }
        else if (new_el.price > el.price || (new_el.price == el.price && new_el.number >= el.number))
        {
            if (i == ZERO)
            {
                for (int j = size; j > i; j--)
                    set_number_by_pos(file_in, j, get_number_by_pos(file_in, j - 1));
                set_number_by_pos(file_in, ZERO, new_el);
                i++;
            }
            else if (check == TRUE)
            {
                for (int j = size; j > i; j--)
                    set_number_by_pos(file_in, j, get_number_by_pos(file_in, j - 1));
                set_number_by_pos(file_in, i, new_el);
                check = FALSE;
                i++;
            }
        }
    }
}

void ab(FILE *file_in)
{
    int size = file_size_bin(file_in);
    product new_el = new_el_input();

    file_sort_bin(file_in, size);
    file_addition_bin(file_in, size, new_el);
}

// Another functions:

void create_binary(char *name)
{
    FILE *f = fopen(name, "wb");
    product cur = { "Vlad", "Micrasoft", 1000, 10 };
    product cur_1 = { "Elena", "Apple", 3000, 15 };
    product cur_2 = { "Mark", "Zavod", 1750, 15 };
    product cur_3 = { "Pasha", "Uliza", 300, 40 };
    product cur_4 = { "Masha", "Apple", 3000, 20 };
    fwrite(&cur, sizeof(product), 1, f);
    fwrite(&cur_1, sizeof(product), 1, f);
    fwrite(&cur_2, sizeof(product), 1, f);
    fwrite(&cur_3, sizeof(product), 1, f);
    fwrite(&cur_4, sizeof(product), 1, f);
    fclose(f);
}

void file_out_bin(char *name)
{
    product el;

    FILE *f = fopen(name, "rb");

    while (fread(&el, sizeof(product), 1, f) == RIGHT_SCAN)
    {
        printf("%s\n", el.name);
        printf("%s\n", el.producer);
        printf("%d\n", el.price);
        printf("%d\n", el.number);
        printf("\n");
    }
    printf("--------------------\n");

    rewind(f);
    fclose(f);
}

int main(int argc, char **argv)
{
    if (argc >= 3)
    {
        if (!strcmp(argv[1], "sb") && argc == 4)
        {
            FILE *file_in;
            FILE *file_out;
            //create_binary(argv[2]);
            file_in = fopen(argv[2], "rb+");
            file_out = fopen(argv[3], "wb");
        
            if (file_in && file_out)
            {
                product el;
                if (fread(&el, sizeof(product), 1, file_in) == RIGHT_SCAN)
                {
                    rewind(file_in);
                    //file_out_bin(argv[2]);
                    sb(file_in, file_out);
                    fclose(file_in);
                    fclose(file_out);
                    //file_out_bin(argv[3]);
                    return NO_ERROR;
                }
                else
                    return EMPTY_ERROR;
            }
            else
                return OPEN_ERROR;
        }
        else if (!strcmp(argv[1], "fb") && argc == 4)
        {
            FILE *file_in;
            //create_binary(argv[2]);
            file_in = fopen(argv[2], "rb");
        
            if (file_in)
            {
                product el;
                if (fread(&el, sizeof(product), 1, file_in) == RIGHT_SCAN)
                {
                    fb(file_in, argv[3]);
                    fclose(file_in);
                    return NO_ERROR;
                }
                else
                    return EMPTY_ERROR;
            }   
            else
                return OPEN_ERROR;
        }
        else if (!strcmp(argv[1], "ab") && argc == 3)
        {
            FILE *file_in_out;
            //create_binary(argv[2]);
            file_in_out = fopen(argv[2], "rb+");
        
            if (file_in_out)
            {
                product el;
                if (fread(&el, sizeof(product), 1, file_in_out) == RIGHT_SCAN)
                {
                    ab(file_in_out);
                    fclose(file_in_out);
                    //file_out_bin(argv[2]);
                    return NO_ERROR;
                }
                else
                    return EMPTY_ERROR;
            }   
            else
                return OPEN_ERROR;
        }
        else
            return WRONG_ARGS_ERROR;
    }
    else
        return WRONG_ARGS_ERROR;
}
