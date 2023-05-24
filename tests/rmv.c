#include <stdlib.h>
/**
* remove_newline - function that removes newline character from string.
* @str: String input
* Return: String without newline character
*/

char *remove_newline(char *str)
{
	char *rtn_str, *cpy = str;
	int i = 0;

	rtn_str = malloc(sizeof(char) * _str_len(cpy));
	while (*cpy)
	{
		if (*cpy == '\n')
		{
			rtn_str[i] = '\0';
			break;
		}

		rtn_str[i] = *cpy;
		cpy++;
		i++;
	}

	return (rtn_str);
}

