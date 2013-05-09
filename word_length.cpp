#include "stdafx.h"

void get_word_length(int* WordLength)
{
	int state = 0;
	int word_length = 0;
	int c = 0;
	while ((c=getchar()) != EOF)
	{
		if (c==' ' || c=='\t' || c=='\n')
		{
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
			if (word_length > 9)
			{
				WordLength[0]++;
			}
			else
			{
				WordLength[word_length]++;
			}
			word_length = 0;
		}
		else if (state == IN)
		{
			word_length++;
		}
	}
	if (word_length > 9)
	{
		WordLength[0]++;
	}
	else
	{
		WordLength[word_length]++;
	}
}

int get_max_length(int* WordLength, int WordLength_size)
{
	int max = 0;
	for (int i=0; i<WordLength_size; i++)
	{
		if (WordLength[i] > max)
		{
			max = WordLength[i];
		}
	}
	return max;
}

void print_char(int length, int WordLength, char c)
{
	printf("%d:", length);
	for (int i=0; i<WordLength; i++)
	{
		printf("%c", c);
	}
	printf("\n");
}

void printf_word_length(int* WordLength, int WordLength_size)
{
	printf("word length:\n");
	for (int i=0; i<10; i++)
	{
		int word_length = 0;
		int max = get_max_length(WordLength, WordLength_size);
		if (max > 50)
		{
			word_length = (WordLength[i] * 50 / max) + 0.5;
		}
		else
		{
			word_length = WordLength[i];
		}
		print_char(i, word_length, '*');
	}
}

void word_length()
{	
	int WordLength[10] = {0};
	get_word_length(WordLength);
	printf_word_length(WordLength, 10);
}