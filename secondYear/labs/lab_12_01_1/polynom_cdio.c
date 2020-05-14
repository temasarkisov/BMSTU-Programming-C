#include "polynom_cdio.h"

polynom_t *polynom_init(polynom_t *polynom)
{
    polynom = malloc(sizeof(polynom_t));
    if (!polynom)
    {
        return NULL;
    }
    polynom->size = 0;
    polynom->head = NULL;

    return polynom;
}

int32_t arg_input(int32_t *const arg)
{
    if (!scanf("%" PRId32, arg))
    {
        return INPUT_ERR;
    }

    return NO_ERR;
}

int32_t polynom_node_input(polynom_t *polynom)
{
    static int32_t prev_power = 0;
    char symb_curr = '\0';

    polynom_node_t *new_node = malloc(sizeof(polynom_node_t));
    if (!new_node)
    {
        return INV_MEM;
    }

    if (!scanf("%" PRId32, &(new_node->factor)))
    {
        free(new_node);
        return INPUT_ERR;
    }
    if (!scanf("%c", &symb_curr))
    {
        free(new_node);
        return INPUT_ERR;
    }
    if (symb_curr != ' ')
    {
        free(new_node);
        return INPUT_ERR;
    }
    if (!scanf("%" PRId32, &(new_node->power)))
    {
        free(new_node);
        return INPUT_ERR;
    }
    if (new_node->power < 0 || (new_node->power >= prev_power && polynom->size > 0))
    {
        free(new_node);
        return INPUT_ERR;
    }
    prev_power = new_node->power;
    if (!scanf("%c", &symb_curr))
    {
        free(new_node);
        return INPUT_ERR;
    }
    if (symb_curr != '\n' && symb_curr != ' ')
    {
        free(new_node);
        return INPUT_ERR;
    }

    new_node->next_node = polynom->head;
    polynom->head = new_node;
    (polynom->size)++;

    if (symb_curr == '\n')
    {
        return LAST_NODE;
    }

    return NO_ERR;
}

int32_t polynom_input(polynom_t *polynom)
{
    int32_t errno = NO_ERR;

    while (errno == NO_ERR)
    {
        errno = polynom_node_input(polynom);
    }

    return errno;
}

void polynom_output(polynom_t *polynom)
{
    polynom_node_t *curr_node = polynom->head;

    while (curr_node)
    {
        printf("%" PRId32 " ", curr_node->factor);
        printf("%" PRId32 " ", curr_node->power);
        curr_node = curr_node->next_node;
    }
    printf("L\n");
}

void polynom_free(polynom_t *polynom)
{
    polynom_node_t *curr_node = polynom->head;
    polynom_node_t *save_ptr = NULL;

    while (curr_node)
    {
        save_ptr = curr_node;
        curr_node = curr_node->next_node;

        free(save_ptr);
    }

    free(polynom);
}
