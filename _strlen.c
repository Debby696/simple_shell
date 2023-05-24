#include "shell.h"

/**
* _strlen - function that gets the length of a string
* @str: String input
* Return: Int value length of string
*/

int _strlen(char *str)
{
	int len = 0;
	char *cpy = str;

	while (*cpy)
	{
		len++;
		cpy++;
	}
	return (len);
}

