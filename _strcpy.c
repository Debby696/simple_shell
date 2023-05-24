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

	if (dest == NULL || src == NULL)
		return (NULL);
	while (src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

