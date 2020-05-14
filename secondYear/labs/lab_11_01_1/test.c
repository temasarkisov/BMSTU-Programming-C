#include "test.h"

int main()
{
    int is_failed = TEST_PASSED;

    size_zero(&is_failed);
    size_less_len(&is_failed);
    size_more_len(&is_failed);
    no_specifier(&is_failed);
    d_specifier(&is_failed);
    o_specifier(&is_failed);
    x_specifier(&is_failed);
    ld_specifier(&is_failed);
    lo_specifier(&is_failed);
    lx_specifier(&is_failed);
    mix_specifier(&is_failed);

    if (is_failed == TEST_PASSED)
    {
        printf("ALL_TESTS_PASSED\n");
        return ALL_TESTS_PASSED;
    }

    printf("NOT_ALL_TESTS_PASSED\n");
    return NOT_ALL_TESTS_PASSED;
}