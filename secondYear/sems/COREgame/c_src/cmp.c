#include "../c_src_headers/cmp.h"

int cmp(int argc, char *argv[])
{
	FILE *fp[2];
	size_t line = 1;
    size_t byte_num = 1;
    int curr_bytes[2];

	if (argc != CORR_ARG_NUM)
    {
	    printf("usage: %s file1 file2\n", argv[0]);
        return ERR;
    }

	for (size_t i = 1; i < 3; i++) 
    {
		if (!strcmp(argv[i], "-")) 
        {
			argv[i] = "<stdin>";
			fp[i - 1] = stdin;
		} 
        else 
        {
            fp[i - 1] = fopen(argv[i], "r");
			if (!fp[i - 1]) 
            {
				printf("fopen %s:", argv[i]);
				return ERR;
			}
		}
	}

    curr_bytes[0] = getc(fp[0]);
    curr_bytes[1] = getc(fp[1]);

    while (curr_bytes[0] != EOF && curr_bytes[1] != EOF)
    {
		if (curr_bytes[0] == curr_bytes[1]) 
        {
			if (curr_bytes[0] == '\n')
            {
				line++;
            }
        } 
         
        else 
        {
			printf("%s %s differ: byte %zu, line %zu\n", argv[1], argv[2], byte_num, line);
			return DIFF;
		} 

        curr_bytes[0] = getc(fp[0]);
		curr_bytes[1] = getc(fp[1]);
        byte_num++;
	}

	return SAME;
}