#ifndef __POLYNOM_CDIO_H__
#define __POLYNOM_CDIO_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

#include "structs.h"
#include "errno.h"
#include "polynom_oper.h"

polynom_t *polynom_init(polynom_t *polynom);

int32_t arg_input(int32_t *const arg);

int32_t polynom_node_input(polynom_t *polynom);

int32_t polynom_input(polynom_t *polynom);

void polynom_output(polynom_t *polynom);

void polynom_free(polynom_t *polynom);

#endif