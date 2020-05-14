#ifndef __SNPRINTF_H__
#define __SNPRINTF_H__

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>

#define CODE_SYMB_DELTA 48

#define MAX_SYMB_NUM 22

int my_snprintf(char *buffer, int size, char *format, ...);

#endif
