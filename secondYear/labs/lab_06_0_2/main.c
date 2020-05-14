#include<stdio.h>

#define GOOD 0
#define NO_GOOD 1
#define NO_ERROR 1
#define ERROR 0
#define ZERO 0
#define ONE 1
#define TRUE 1
#define FALSE 0 
#define W_MAX 16  // Maximum word length.
#define S_MAX 256  // Maximum string length.

typedef char m_t[S_MAX][W_MAX];
typedef char s_t[W_MAX];

int string_input(char *string, const char *const delim)
{
    char sym;
    int ind_d = ZERO;
    int word_len = ZERO;

    for (int ind = ZERO; ind < S_MAX; ind++)
    {
        sym = getchar();
        if ((ind == S_MAX - 1 && sym != '\n') || (ind == ZERO && sym == '\n'))
            return ERROR;
        else if (sym == '\n')
            break;
        else if (ind < S_MAX && sym != '\n')
        {
            string[ind] = sym;
            word_len++;
            while (delim[ind_d] != '\0')
            {
                if (string[ind] == delim[ind_d])
                {
                    word_len = ZERO;
                    break;
                }
                ind_d++;
            }
            ind_d = ZERO;
            if (word_len > W_MAX)
                return ERROR;
        }
    }
   return NO_ERROR; 
}

int split(const char *string, char matrix[][S_MAX], const char *const delim)
{
    int row = ZERO;
    int col = ZERO;
    int ind_d = ZERO;
    int check = TRUE;

    while (*string)
    {
        while (delim[ind_d] != '\0')
        {
            if (*string == delim[ind_d])
            {
                check = FALSE;
                break;
            }
            ind_d++;
        }

        if (check == TRUE)
            matrix[row][col++] = *string;
        else
        {
            matrix[row++][col] = '\0';
            col = ZERO;
        }
        string++;
        check = TRUE;
        ind_d = ZERO;
    }
    
    matrix[row][col] = '\0';
    row++;

    return row;
}

int words_compare(const char *const word_1, const char *const word_2)
{
    int len_1 = ZERO, len_2 = ZERO; 
    
    while (word_1[len_1] != '\0')
        len_1++;

    while (word_2[len_2] != '\0')
        len_2++;

    if (len_1 == len_2)
    {
        for (int ind = ZERO; ind < len_1; ind++)
            if (word_1[ind] != word_2[ind])
                return FALSE;
    }
    else
        return FALSE;

    return TRUE;
}

int not_del_exist(char matrix[][S_MAX], const int w_num)
{
    for (int i = ZERO; i < w_num; i++)
        if (matrix[i][ZERO] != '\0')
            return NO_ERROR;

    return ERROR;
}

int num_of_rep(const char *const word, const int ind, char matrix[][S_MAX], const int w_num)
{
    int rep_num = ONE;

    for (int i = ZERO; i < w_num; i++)
        if (matrix[i][ZERO] != '\0' && i != ind)
            if (words_compare(word, matrix[i]))
            {
                rep_num++;
                matrix[i][ZERO] = '\0';
            }

    return rep_num;
}

int main()
{
    char string[S_MAX] = { 0 }; 
    char matrix[S_MAX][S_MAX] = { 0 };
    char delim[] = ",;:-.!? ";
    int w_num, rep_num;
    
    if (string_input(string, delim))
    {
        w_num = split(string, matrix, delim);
        if (not_del_exist(matrix, w_num))
        {
            printf("Result:");
            for (int i = ZERO; i < w_num; i++)
                if (matrix[i][ZERO] != '\0')
                {
                    rep_num = num_of_rep(matrix[i], i, matrix, w_num);
                    printf("\n%s %d", matrix[i], rep_num);
                }
            return GOOD;
        }
    }
    return NO_GOOD;
}

