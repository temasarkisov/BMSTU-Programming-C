#ifndef __TEST_AUXILIARY__
#define __TEST_AUXILIARY__

#include <stdio.h>
#include <string.h>

#include "snprintf.h"

#define BUFFER_SIZE 100
#define TEST_PASSED 0
#define TEST_FAILED 1;

void size_zero(int *const is_failed);

void size_less_len(int *const is_failed);

void size_more_len(int *const is_failed);

void no_specifier(int *const is_failed);

void d_specifier(int *const is_failed);

void o_specifier(int *const is_failed);

void x_specifier(int *const is_failed);

void ld_specifier(int *const is_failed);

void lo_specifier(int *const is_failed);

void lx_specifier(int *const is_failed);

void mix_specifier(int *const is_failed);

#endif