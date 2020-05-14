#include "test_auxiliary.h"

void size_zero(int *const is_failed)
{
    char buffer_my[BUFFER_SIZE];
    char buffer_og[BUFFER_SIZE];
    int size = 0;

    if (my_snprintf(buffer_my, size, "Run dat back Turbo") != snprintf(buffer_og, size, "Run dat back Turbo"))
    {
        printf("Test: size equal zero is failed.\n");
        *is_failed = TEST_FAILED;
    }
}

void size_less_len(int *const is_failed)
{
    char buffer_my[BUFFER_SIZE];
    char buffer_og[BUFFER_SIZE];
    int size = 3;
    char format[] = "%d";
    int source = 1234; 

    if (my_snprintf(buffer_my, size, format, source) != snprintf(buffer_og, size, format, source))
    {
        printf("Test: size less than length is failed.\n");
        *is_failed = TEST_FAILED;
    }
    else if (strcmp(buffer_my, buffer_og))
    {
        printf("Test: size less than length is failed.\n");
        *is_failed = TEST_FAILED;
    }
}

void size_more_len(int *const is_failed)
{
    char buffer_my[BUFFER_SIZE];
    char buffer_og[BUFFER_SIZE];
    int size = BUFFER_SIZE;
    char format[] = "%d";
    int source = 1234; 

    if (my_snprintf(buffer_my, size, format, source) != snprintf(buffer_og, size, format, source))
    {
        printf("Test: size more than length is failed.\n");
        *is_failed = TEST_FAILED;
    }
    else if (strcmp(buffer_my, buffer_og))
    {
        printf("str_my: |%s|   str_og: |%s|\n", buffer_my, buffer_og);
        printf("Test: size more than length is failed.\n");
        *is_failed = TEST_FAILED;
    }
}

void no_specifier(int *const is_failed)
{
    char buffer_my[BUFFER_SIZE];
    char buffer_og[BUFFER_SIZE];
    int size = BUFFER_SIZE;

    if (my_snprintf(buffer_my, size, "Metro Boomin wants some more.") != snprintf(buffer_og, size, "Metro Boomin wants some more."))
    {
        printf("Test: no specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
}

void d_specifier(int *const is_failed)
{
    char buffer_my[BUFFER_SIZE];
    char buffer_og[BUFFER_SIZE];
    int size = BUFFER_SIZE;
    char format[] = "%d"; 
    int source = 8613; 

    if (my_snprintf(buffer_my, size, format, source) != snprintf(buffer_og, size, format, source))
    {
        printf("Test: 'd' specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
    else if (strcmp(buffer_my, buffer_og))
    {
        printf("str_my: |%s|   str_og: |%s|\n", buffer_my, buffer_og);
        printf("Test: 'd' specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
}

void o_specifier(int *const is_failed)
{
    char buffer_my[BUFFER_SIZE];
    char buffer_og[BUFFER_SIZE];
    int size = BUFFER_SIZE;
    char format[] = "%o"; 
    int source = 8613; 

    if (my_snprintf(buffer_my, size, format, source) != snprintf(buffer_og, size, format, source))
    {
        printf("Test: 'o' specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
    else if (strcmp(buffer_my, buffer_og))
    {
        printf("Test: 'o' specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
}

void x_specifier(int *const is_failed)
{
    char buffer_my[BUFFER_SIZE];
    char buffer_og[BUFFER_SIZE];
    int size = BUFFER_SIZE;
    char format[] = "%x"; 
    int source = 8613; 

    if (my_snprintf(buffer_my, size, format, source) != snprintf(buffer_og, size, format, source))
    {
        printf("Test: 'x' specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
    else if (strcmp(buffer_my, buffer_og))
    {
        printf("Test: 'x' specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
}

void ld_specifier(int *const is_failed)
{
    char buffer_my[BUFFER_SIZE];
    char buffer_og[BUFFER_SIZE];
    int size = BUFFER_SIZE;
    char format[] = "%ld"; 
    int source = 8613; 

    if (my_snprintf(buffer_my, size, format, source) != snprintf(buffer_og, size, format, source))
    {
        printf("Test: 'ld' specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
    else if (strcmp(buffer_my, buffer_og))
    {
        printf("Test: 'ld' specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
}

void lo_specifier(int *const is_failed)
{
    char buffer_my[BUFFER_SIZE];
    char buffer_og[BUFFER_SIZE];
    int size = BUFFER_SIZE;
    char format[] = "%lo"; 
    int source = 8613; 

    if (my_snprintf(buffer_my, size, format, source) != snprintf(buffer_og, size, format, source))
    {
        printf("Test: 'lo' specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
    else if (strcmp(buffer_my, buffer_og))
    {
        printf("Test: 'lo' specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
}

void lx_specifier(int *const is_failed)
{
    char buffer_my[BUFFER_SIZE];
    char buffer_og[BUFFER_SIZE];
    int size = BUFFER_SIZE;
    char format[] = "%lx"; 
    int source = 8613; 

    if (my_snprintf(buffer_my, size, format, source) != snprintf(buffer_og, size, format, source))
    {
        printf("Test: 'lx' specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
    else if (strcmp(buffer_my, buffer_og))
    {
        printf("Test: 'lx' specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
}

void mix_specifier(int *const is_failed)
{
    char buffer_my[BUFFER_SIZE];
    char buffer_og[BUFFER_SIZE];
    int size = BUFFER_SIZE;
    char format[] = "%d %o %x"; 
    int source = 8613; 
    int source1 = 93;
    int source2 = 12341;

    if (my_snprintf(buffer_my, size, format, source, source1, source2) != snprintf(buffer_og, size, format, source, source1, source2))
    {
        printf("Test: mix specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
    else if (strcmp(buffer_my, buffer_og))
    {
        printf("Test: mix specifier is failed.\n");
        *is_failed = TEST_FAILED;
    }
}
