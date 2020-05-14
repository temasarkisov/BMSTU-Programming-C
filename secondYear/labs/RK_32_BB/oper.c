#include "oper.h"

sts_t *string_pars(FILE *fp, sts_t *sts)
{
    char word_curr[WORD_SIZE];

    sts = (sts_t *) malloc(sizeof(sts_t));
    if (!sts)
    {
	    return NULL;
    }
    sts->size = 0;

    while (fscanf(fp, "%s", word_curr) == 1)
    {
        sts = sts_node_add(word_curr, sts);
        if (!sts)
        {
            return NULL;
        }

        for (int i = 0; i < WORD_SIZE; i++)
	    {
	        word_curr[i] = '\0';
	    }
    }

    return sts;
}

sts_t *sts_node_add(char *word, sts_t *sts)
{
    sts_node_t *node_new = (sts_node_t *) malloc(sizeof(sts_node_t));
    if (!node_new)
    {
        return NULL;
    }
    node_new->word = (char *) calloc(WORD_SIZE, sizeof(char));
    if (!node_new->word)
    {
        free(node_new);
        return NULL;
    }

    strcpy(node_new->word, word);
    node_new->next = sts->head;
    sts->head = node_new;
    (sts->size)++;

    return sts;
}

void sts_output(FILE *fp, sts_t *sts)
{
    sts_node_t *curr_node = sts->head;

    while(curr_node)
    {
	    fprintf(fp, "%s\n", curr_node->word);
	    curr_node = curr_node->next;
    }
}

void sts_reverse(sts_t *sts)
{
    sts_node_t *curr_node = sts->head;
    sts_node_t *save_prev = NULL;
    sts_node_t *save_next = NULL;

    while(curr_node)
    {
	    save_next = curr_node->next;
	    curr_node->next = save_prev;
	    save_prev = curr_node;
	    curr_node = save_next;
    }

    sts->head = save_prev;
}

