#ifndef __OPER_H__
#define __OPER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "defines.h"

sts_t *string_pars(FILE *fp, sts_t *sts);

sts_t *sts_node_add(char *word, sts_t *sts);

void sts_output(FILE *fp, sts_t *sts);

void sts_reverse(sts_t *sts);

#endif
