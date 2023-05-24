#include "shell.h"

/**
 * _get_tokens - function that converts a string to tokens
 *	at the specified section by the delimeter.
 * @str: input string that is to be broken into tokens.
 * Return: An array of the tokens
 */

char **_get_tokens(char *str)
{
	str_arr_struct argv = _strtok(str, " ");

	return (argv.arr);
}

