#include <stdlib.h>
#include "_str_len.c"

/**
* _str_dup - function that duplicates a string
* @str: string that is to be duplicated
* Return: a copy of the string str
*/ 
char *_str_dup(char *str)
{
	char *cpy = str, *dup;
	int i = 0 , str_len = _str_len(cpy);

	dup = malloc(sizeof(char) * str_len + 1);

	if (dup == NULL)
	{
		free(dup);
		return (NULL);
	}
	for (; i < str_len; i++)
	{
		dup[i] = cpy[i];
	}

	return (dup);
}

