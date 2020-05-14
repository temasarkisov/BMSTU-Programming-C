#include<stdio.h>
#include<string.h>

#define ZERO 0
#define NAME_MAX_LEN 100
#define MAX_WORD_LEN 10
#define TRUE_FSCANF 1 

int word_def(char *file_name)
{
    FILE* in_file = fopen(file_name, "r");

    char word[MAX_WORD_LEN];
    int ind_word = ZERO;
    char sym;

    if (fscanf(in_file, "%c", &sym) == TRUE_FSCANF)
    {
	while (sym != EOF)
	{
	    fscanf(in_file, "%c", &sym);
	    printf("sym = %c\n", sym);
	   
	    while(sym == ' ')
	    {
	        fscanf(in_file, "%c", &sym);
	    }

	    printf("sym = %c\n", sym);
	    word[ind_word] = sym;
	    ind_word++;
	}
    }

    printf("word = %s\n", word);
    fclose(in_file);

    return 1;

}

int main()
{
    char file_name[] = "in.txt";

    int res = word_def(file_name);
}
