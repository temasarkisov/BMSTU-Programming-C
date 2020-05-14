#ifndef __POLYNOM_OPER_H__
#define __POLYNOM_OPER_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "structs.h"
#include "errno.h"
#include "defines.h"
#include "polynom_cdio.h"

void polynom_reverse(polynom_t *polynom);

int32_t power(int32_t value, const int32_t power);

int32_t polynom_node_add(polynom_t *polynom, const int32_t factor, const int32_t power);

int32_t polynom_val_oper(polynom_t *polynom, int32_t arg);

int32_t polynom_ddx_oper(polynom_t *polynom);

int32_t polynom_sum_oper(polynom_t *polynom_a, polynom_t *polynom_b, polynom_t *polynom_r);

int32_t polynom_dvd_oper(polynom_t *polynom, polynom_t *polynom_odd, polynom_t *polynom_even);

int32_t polynom_key_oper();

#endif