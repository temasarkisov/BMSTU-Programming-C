#include<stdio.h>
#include<string.h>

#define ZERO 0
#define NO_ERROR 1
#define ERROR 0
#define RT_R 0
#define WG_R 1

char *my_strpbrk(char *str1, const char *str2)
{
    int len2 = ZERO;
    
    while (*str1 && *str1 != *str2)
    {
        while (*str2)
        {
            if (*str1 == *str2)
                break;
            len2++;
            str2++;
        }
        if (*str2 != '\0')
            break;
        str1++;
        str2 = str2 - len2;
        len2 = ZERO;
    }
    
    if (*str1 == '\0')
        return NULL;
    
    return str1;
}

int my_strspn(const char *str1, const char *str2)
{
    int len2 = ZERO, count = ZERO, pos = ZERO;
    
    while (*str1 && count == ZERO)
    {
        while (*str2)
        {
            if (*str1 == *str2)
            {
                count++;
                break;
            }
            len2++;
            str2++;
        }

        if (count == ZERO)
        {
            break;
        }

        count = ZERO;
        str1++;
        pos++;
        str2 = str2 - len2;
        len2 = ZERO;
    }
    
    return pos;
}

int my_strcspn(const char *str1, const char *str2)
{
    int len2 = ZERO, num = ZERO;
    
    while (*str1 && *str1 != *str2)
    {
        while (*str2)
        {
            if (*str1 == *str2)
                break;
            len2++;
            str2++;
        }
        if (*str2 != '\0')
            return num;
        str1++;
        num++;
        str2 = str2 - len2;
        len2 = ZERO;
    }
    
    return num;
}

char *my_strchr(char *str, const int ch)
{
    while (*str && *str != ch)
        str++;

    if (*str == '\0' && ch != '\0')
        return NULL;

    return str;
}

char *my_strrchr(char *str, const int ch)
{
    int len_btn = -1;

    while (*str)
    {
        if (*str == ch)
            len_btn = ZERO;
        else if (len_btn != -1)
            len_btn++;
        str++;
    }
    if (len_btn == -1 && *str == '\0' && ch != '\0')
        return NULL;
    else
    {
        str = str - len_btn - 1;
        return str;
    }
}

int test_for_strpbrk()
{
    char *test_str = strpbrk("hello world", "owo");
    char *my_str = my_strpbrk("hello world", "owo");
    
    if (strlen(test_str) == strlen(my_str))
    {
        for (int i = ZERO; i < strlen(my_str); i++)
            if (my_str[i] != test_str[i])
                return ZERO;
    }
    else 
        return ERROR;

    return NO_ERROR;
}

int test_for_strspn()
{
    int test_str = strspn("hello world", "hello");
    int my_str = my_strspn("hello world", "hello");

    if (my_str != test_str)
        return ERROR;
    
    return NO_ERROR;
}

int test_for_strcspn()
{
    int test_str = strcspn("hello world", "hello");
    int my_str = my_strcspn("hello world", "hello");

    if (my_str != test_str)
        return ERROR;
  
    return NO_ERROR;
}

int test_for_strchr()
{
    char *test_str = strchr("hello world", '\0');
    char *my_str = my_strchr("hello world", '\0');

    if (strlen(test_str) == strlen(my_str))
    {
        for (int i = ZERO; i < strlen(my_str); i++)
            if (my_str[i] != test_str[i])
                return ZERO;
    }
    else
        return ERROR;

    return NO_ERROR;
}

int test_for_strrchr()
{
    char *test_str = strrchr("hello world", '\0');
    char *my_str = my_strrchr("hello world", '\0');
    
    if (strlen(test_str) == strlen(my_str))
    {
        for (int i = ZERO; i < strlen(my_str); i++)
            if (my_str[i] != test_str[i])
                return ZERO;
    }
    else
        return ERROR;

    return NO_ERROR;
}

int main()
{
    if (test_for_strpbrk() && test_for_strspn() && 
        test_for_strcspn() && test_for_strchr() && 
        test_for_strrchr())
    {
        printf("FUNC_TESTING (PASSED)\n");
        return RT_R;
    }

    printf("FUNC_TESTING (FAILED)\n");
    return WG_R;
}
