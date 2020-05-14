#include "main.h"

int main()
{
    sts_t *sts = NULL;
    FILE *fp_in;
    FILE *fp_out;

    fp_in = fopen("in.txt", "r");
    if (!fp_in)
    {
	    return ERR;
    }

    fp_out = fopen("out.txt", "w");
    if (!fp_out)
    {
	    return ERR;
    }

    sts = string_pars(fp_in, sts);
    if (!sts)
    {
	    return ERR;
    }

    sts_output(fp_out, sts);

    return NO_ERR;   
}
