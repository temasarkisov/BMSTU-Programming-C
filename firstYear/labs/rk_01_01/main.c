#include <stdio.h>

//20

void array_input(int n, int *a)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
}

int uni_value(int n, int *a)
{
	int count = n;
	int q = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == a[j] && i > j)
				break;
			if (a[i] == a[j] && i != j)
				q++;
		}
	}
	count -= q;

	return count;
}

int main (void)
{
       int num;
       scanf("%d", &num);

       int array[num];
       array_input(num, array);

       int count = uni_value(num, array);
       printf("%d", count);

       return 0;
}
