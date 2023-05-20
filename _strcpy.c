#include "shell.h"

/**
 * _strcpy - function that copies scr str to dest str
 * @dest: destination string.
 * @src: source string.
 * Return: pointer to destination string.
 */
char *_strcpy(char *dest, char *src)
{
	if (dest == NULL || src == NULL)
		return (NULL);
	while ((*dest++ = *src++))
		;
	return (dest);
}

