#include "polynom_oper.h"

void polynom_reverse(polynom_t *polynom)
{
    polynom_node_t *curr_node = polynom->head;
    polynom_node_t *save_prev = NULL;
    polynom_node_t *save_next = NULL;

    while (curr_node)
    {
        save_next = curr_node->next_node;
        curr_node->next_node = save_prev;
        save_prev = curr_node;
        curr_node = save_next;
    }

    polynom->head = save_prev;
}

int32_t polynom_node_add(polynom_t *polynom, const int32_t factor, const int32_t power)
{
    polynom_node_t *new_node = malloc(sizeof(polynom_node_t));
    if (!new_node)
    {
        return INV_MEM;
    }

    new_node->factor = factor;
    new_node->power = power;

    new_node->next_node = polynom->head;
    polynom->head = new_node;
    (polynom->size)++;

    return NO_ERR;
} 

int32_t power(int32_t value, const int32_t power)
{
    int32_t value_powered = value;

    if (power == 0)
    {
        value = 1;
        return value;
    }

    for (int i = 1; i < power; i++)
    {
        value_powered *= value;
    }

    return value_powered;
}

int32_t polynom_val_oper(polynom_t *polynom, int32_t arg)
{
    int32_t value = 0;

    polynom_node_t *curr_node = polynom->head;
    while (curr_node)
    {
        value += curr_node->factor * power(arg, curr_node->power);
        curr_node = curr_node->next_node;
    }

    return value;
}

int32_t polynom_ddx_oper(polynom_t *polynom)
{
    polynom_node_t *curr_node = polynom->head;

    if (curr_node->power == 0)
    {
        if (polynom->size == 1)
        {
            return SIZE_ERR;
        }

        polynom_node_t *save_ptr = polynom->head;
        polynom->head = polynom->head->next_node;
        (polynom->size)--;
        curr_node = curr_node->next_node;
        free(save_ptr);
    }

    while (curr_node)
    {
        curr_node->factor = curr_node->factor * curr_node->power;
        curr_node->power--;
        curr_node = curr_node->next_node;
    }

    return NO_ERR;
}

int32_t polynom_sum_oper(polynom_t *polynom_a, polynom_t *polynom_b, polynom_t *polynom_r)
{
    int32_t power_curr = 0;
    polynom_node_t *curr_node_a = polynom_a->head;
    polynom_node_t *curr_node_b = polynom_b->head;

    while (curr_node_a || curr_node_b)
    {
        if (curr_node_a && curr_node_b && power_curr == curr_node_a->power && power_curr == curr_node_b->power)
        {   
            if (polynom_node_add(polynom_r, curr_node_a->factor + curr_node_b->factor, power_curr) == INV_MEM)
            {
                return INV_MEM;
            }
            curr_node_a = curr_node_a->next_node;
            curr_node_b = curr_node_b->next_node;
            polynom_r->size++;
        }
        else if (curr_node_a && power_curr == curr_node_a->power)
        {
            if (polynom_node_add(polynom_r, curr_node_a->factor, power_curr) == INV_MEM)
            {
                return INV_MEM;
            }
            curr_node_a = curr_node_a->next_node;
            polynom_r->size++;
        }
        else if (curr_node_b && power_curr == curr_node_b->power)
        {
            if (polynom_node_add(polynom_r, curr_node_b->factor, power_curr) == INV_MEM)
            {
                return INV_MEM;
            }
            curr_node_b = curr_node_b->next_node;
            polynom_r->size++;
        }

        power_curr++;
    }

    return NO_ERR;
}

int32_t polynom_dvd_oper(polynom_t *polynom, polynom_t *polynom_odd, polynom_t *polynom_even)
{
    polynom_node_t *curr_node = polynom->head;
    while (curr_node)
    {
        if (curr_node->power % 2 == 0)
        {
            if (polynom_node_add(polynom_even, curr_node->factor, curr_node->power) == INV_MEM)
            {
                return INV_MEM;
            }
        }
        else
        {
            if (polynom_node_add(polynom_odd, curr_node->factor, curr_node->power) == INV_MEM)
            {
                return INV_MEM;
            }
        }
        
        (polynom->size)++;
        curr_node = curr_node->next_node;
    }

    return NO_ERR;
}

int32_t polynom_key_oper()
{
    char *keyword = calloc(KEY_WORD_SIZE, sizeof(char));
    if (!keyword)
    {
        return INV_MEM;
    }
    if (!scanf("%s", keyword))
    {
        free(keyword);
        return INV_MEM;
    }

    if (strcmp(keyword, "val") == 0)
    {
        int32_t arg = 0;
        int32_t value = 0;
        polynom_t *polynom = NULL;

        polynom = polynom_init(polynom);
        if (!polynom)
        {
            free(keyword);
            return INV_MEM;
        }

        if (polynom_input(polynom) != LAST_NODE)
        {
            polynom_free(polynom);
            free(keyword);
            return INPUT_ERR;
        }
        
        if (arg_input(&arg) != NO_ERR)
        {
            polynom_free(polynom);
            free(keyword);
            return INPUT_ERR;
        }

        value = polynom_val_oper(polynom, arg);
        printf("%" PRId32, value);
        polynom_free(polynom);
        free(keyword);

        return NO_ERR;
    }
    if (strcmp(keyword, "ddx") == 0)
    {
        polynom_t *polynom = NULL;

        polynom = polynom_init(polynom);
        if (!polynom)
        {
            free(keyword);
            return INV_MEM;
        }

        if (polynom_input(polynom) != LAST_NODE)
        {
            polynom_free(polynom);
            free(keyword);
            return INPUT_ERR;
        }

        polynom_ddx_oper(polynom);
        polynom_reverse(polynom);
        polynom_output(polynom);
        polynom_free(polynom);
        free(keyword);

        return NO_ERR;
    }
    if (strcmp(keyword, "sum") == 0)
    {
        polynom_t *polynom_a = NULL;
        polynom_t *polynom_b = NULL;
        polynom_t *polynom_r = NULL;

        polynom_a = polynom_init(polynom_a);
        if (!polynom_a)
        {
            free(keyword);
            return INV_MEM;
        }
        if (polynom_input(polynom_a) != LAST_NODE)
        {
            polynom_free(polynom_a);
            free(keyword);
            return INPUT_ERR;
        }
        polynom_b = polynom_init(polynom_b);
        if (!polynom_b)
        {
            polynom_free(polynom_a);
            free(keyword);
            return INV_MEM;
        }
        if (polynom_input(polynom_b) != LAST_NODE)
        {
            polynom_free(polynom_a);
            polynom_free(polynom_b);
            free(keyword);
            return INPUT_ERR;
        }
        polynom_r = polynom_init(polynom_r);
        if (!polynom_r)
        {
            polynom_free(polynom_a);
            polynom_free(polynom_b);
            free(keyword);
            return INV_MEM;
        }

        if (polynom_sum_oper(polynom_a, polynom_b, polynom_r) != NO_ERR)
        {
            polynom_free(polynom_a);
            polynom_free(polynom_b);
            polynom_free(polynom_r);
            free(keyword);
            return INV_MEM;
        }

        polynom_output(polynom_r);
        polynom_free(polynom_a);
        polynom_free(polynom_b);
        polynom_free(polynom_r);
        free(keyword);

        return NO_ERR;  
    }
    if (strcmp(keyword, "dvd") == 0)
    {
        polynom_t *polynom = NULL;
        polynom_t *polynom_odd = NULL;
        polynom_t *polynom_even = NULL;

        polynom = polynom_init(polynom);
        if (!polynom)
        {
            free(keyword);
            return INV_MEM;
        }
        if (polynom_input(polynom) != LAST_NODE)
        {
            polynom_free(polynom);
            free(keyword);
            return INPUT_ERR;
        }
        polynom_odd = polynom_init(polynom_odd);
        if (!polynom_odd)
        {
            polynom_free(polynom);
            free(keyword);
            return INV_MEM;
        }
        polynom_even = polynom_init(polynom_even);
        if (!polynom_even)
        {
            polynom_free(polynom);
            polynom_free(polynom_odd);
            free(keyword);
            return INV_MEM;
        }

        if (polynom_dvd_oper(polynom, polynom_odd, polynom_even) != NO_ERR)
        {
            polynom_free(polynom);
            polynom_free(polynom_odd);
            polynom_free(polynom_even);
            free(keyword);
            return INV_MEM;
        }

        polynom_output(polynom_even);
        polynom_output(polynom_odd);
        polynom_free(polynom);
        polynom_free(polynom_odd);
        polynom_free(polynom_even);
        free(keyword);

        return NO_ERR;  
    }

    free(keyword);
    return KEY_ERR;
}