#include "shell.h"

/**
 * check_delim - function that checks whether a charactter is the delimeter.
 * @c: character to be checked.
 * @delim: delimeter charater.
 * Return: 1 if character is delim 0 if not.
 */
int check_delim(char c, char *delim)
{
	if (c == *delim)
		return (1);
	return (0);
}

/**
 * _strtok - function that breaks up a string into tokens
 * @src: String that is to be broken up.
 * @delim: character specifiying where the string is to be broken.
 * Return: ret a pointer to a string token.
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
		if (check_delim(*src, delim))
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
		if (check_delim(*src, delim))
		{
			*src = '\0';
			backup = src + 1;
			return (ret);
		}
		src++;
	}
}

