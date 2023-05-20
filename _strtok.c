#include "shell.h"

/**
 * is_delim - function that checks whether a charactter is the delimeter.
 * @c: character to be checked.
 * @delim: delimeter charater.
 * Return: 1 if character is delim 0 if not.
 */
unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - function that breaks up a string into tokens
 * @src: String that is to be broken up.
 * @delim: character specifiying where the string is to be broken.
 * Return: pointer to string token.
 */
char *_strtok(char *src, char *delim)
{
	static char *backup;
	char *ret;

	if (!src)
		src = backup;
	if (!src)
		return (NULL);

	while (1)
	{
		if (is_delim(*src, delim))
		{
			src++;
			continue;
		}

		if (*src == '\0')
			return (NULL);
		break;
	}
	ret = src;
	while (1)
	{
		if (*src == '\0')
		{
			backup = src;
			return (ret);
		}
		if (is_delim(*src, delim))
		{
			*src = '\0';
			backup = src + 1;
			return (ret);
		}
		src++;
	}
}

