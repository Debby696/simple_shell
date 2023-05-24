#include "shell.h"

/**
 * _strcpy - function that copies scr str to dest str
 * @dest: destination string.
 * @src: source string.
 * Return: pointer to destination string.
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	while ((dest[x] = src[x]))
		x++;
	return (dest);
}


