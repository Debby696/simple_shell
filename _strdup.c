#include "shell.h"

/**
* _strdup - function that duplicates a string
* @str: string that is to be duplicated
* Return: a copy of the string str
*/
char *_strdup(char *str)
{
	char *dup = malloc(sizeof(char) * _strlen(str) + 1);

	if (dup == NULL)
	{
		free(dup);
		return (NULL);
	}
	_strcpy(dup, str);
	return (dup);
}

