#include "main.h"

int main()
{
    int is_failed = PASSED;

    val_positive_arg(&is_failed);    
    val_neg_arg(&is_failed);
    ddx_non_zero_power(&is_failed);
    ddx_zero_power(&is_failed);
    sum_diff_sizes(&is_failed);
    sum_same_sizes(&is_failed);
    dvd_mix(&is_failed);

    if (is_failed == PASSED)
    {
        return ALL_TESTS_PASSED;
    }

    return NOT_ALL_TESTS_PASSED;
}
