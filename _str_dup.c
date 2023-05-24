#include "shell.h"

/**
* _str_dup - function that duplicates a string
* @str: string that is to be duplicated
* Return: a copy of the string str
*/
char *_str_dup(char *str)
{
	char *dup = malloc(sizeof(char) * _str_len(str) + 1);

	if (dup == NULL)
	{
		free(dup);
		return (NULL);
	}
	_strcpy(dup, str);

	return (dup);
}

