//array.cpp
#include "stdafx.h"

void array()
{
	int numbers[10] = {0};
	int white = 0;
	int nother = 0;
	int c = 0;
	int count = 0;
	while((c = getchar()) != EOF)
	{
		count++;
		if (c>='0' && c<='9')
		{
			numbers[c-'0']++; 
		}
		else if (c=='\n' || c=='\t' || c==' ')
		{
			white++;
		}
		else
		{
			nother++;
		}
	}
	printf("numbers:");
	for (int i=0; i<10; i++)
	{
		printf("%d ", numbers[i]);
	}
	printf("\n");
	printf("place white:%d\n", white);
	printf("nother:%d\n", nother);
	printf("count:%d\n", count);
}