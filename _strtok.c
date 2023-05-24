#include "shell.h"
#include <stdlib.h>

/**
 * check_empty - A function that checks if input string in
 *	_strtok is an empty string.
 * @str: input string taken by _strtok.
 * Return: Number of empty characters.
 */
int check_empty(char *str)
{
	int x = 0;
	char *empty = " ", *cpy = str;

	while (*cpy++ == *empty)
		x++;
	return (x);
}
/**
 * set_mem - function that sets string char to null byte;
 * @str: pointer to string that is to be set
 * Return: void.
 */
void set_mem(char *str)
{
	int set = 0;

	while (str[set])
	{
		str[set] = '\0';
		set++;
	}
}
/**
* _strtok - function that splits string into token at the positions specified
*	by the delimeter.
* @str: Input string that is to be split into tokens.
* @delim: String specifying the positions to split the string at
* Return: The function returns an array of the split strings.
*/
str_arr_struct _strtok(char *str, char *delim)
{
	char *cp = str, token[4096];
	int i = 0, index = 0;
	str_arr_struct cmd_arr;

	cmd_arr.arr = malloc(sizeof(char **));
	while (*cp != '\0' && (_str_len(str) != check_empty(str)))
	{
		if (*cp == *delim)
		{
			while (*cp == *delim)
				cp++;
			token[i] = '\0';
			if (check_empty(token) != _str_len(token))
			{
				cmd_arr.arr[index] = _str_dup(token);
				index++;
			}
			set_mem(&token[0]);
			i = 0;
		}
		token[i] = *cp;
		if (*(cp + 1) == '\0' && *cp != '\0')
		{
			token[i + 1] = '\0';
			cmd_arr.arr[index] = _str_dup(token);
			index++;
		}
		cp++;
		i++;
	}
	cmd_arr.arr[index] = malloc(sizeof(char *) + 1);
	cmd_arr.arr[index] = (char *) 0;
	cmd_arr.arr_size = index;
	return (cmd_arr);
}

