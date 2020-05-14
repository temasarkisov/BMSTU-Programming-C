#include"main.h"

int main()
{
    array_of_e9s_t array_of_e9s;
    array_of_e9s.array_of_e9s = NULL;
    array_of_e9s.e9s_number = 0;

    if (array_of_e9s_input(&array_of_e9s) != R_I)
    {
        return INPUT_ERR;
    }

    if (array_of_e9s_el_delete(&array_of_e9s) != NO_ERR)
    {
        array_of_e9s_free(array_of_e9s);
        return DEL_ERR;
    }

    if (array_of_e9s_el_averaged(&array_of_e9s) == INV_MEM_ERR)
    {
        array_of_e9s_free(array_of_e9s);
        return AVE_ERR;
    }

    if (key_word_oper(array_of_e9s) == KEY_ERR)
    {
        array_of_e9s_free(array_of_e9s);
        return KEY_ERR;
    }

    FILE *fp = fopen("results.txt", "w");

    if (fp == NULL)
    {
        fclose(fp);
        array_of_e9s_free(array_of_e9s);
        return FILE_ERR;
    } 

    array_of_e9s_output(fp, array_of_e9s);

    fclose(fp);
    array_of_e9s_free(array_of_e9s);
    return NO_ERR;
}
