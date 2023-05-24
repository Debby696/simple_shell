#include "shell.h"

/**
 * _strcat - function that concates two strings
 * @dest: string that is being extended.
 * @src: string that will be appended at the end of dest string.
 * Return: a char string pointer made up of characters in dest and src
 */
char *_strcat(char *dest, char *src)
{
	int dest_size = _str_len(dest), src_size = _str_len(src), index = 0;
	char *rtn_str;

	rtn_str = malloc(sizeof(char) * (src_size + dest_size) + 1);

	while (index < dest_size)
	{
		rtn_str[index] = dest[index];
		if (dest[index + 1] == '\0')
			break;
		index++;
	}

	index = 0;
	while (index < src_size)
	{
		rtn_str[index + dest_size] = src[index];
		index++;
	}
	return (rtn_str);
}

