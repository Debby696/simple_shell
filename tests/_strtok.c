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
 * copy_characters - function that copy characters from cpy
 *	string into token string.
 * @start: start index on cpy.
 * @stop: stop index on cpy.
 * @index: Number of tokens in list of strings arr.
 * @arr: list of string tokens.
 * @token: string copied from cpy.
 * @cpy: input string from strtok
 * @delim: the delimeter character.
 * Return: Void.
 */
void copy_characters(int *start, int *stop, int *index,
		     char **arr, char *token, char *cpy, char *delim)
{
	int rng = *stop - *start, cp_start = *start, cp_stop = *stop,
		count = 0, cp_index = *index;
	char *empty_check = " ";

	while (count < rng && cpy[cp_start] != *delim &&
	cpy[cp_start] != *empty_check)
	{
		token[count] = cpy[cp_start];
		cp_start++;
		count++;
	}
	if (_str_len(token) > 0)
	{
		if (cp_index == 0)
			*arr = token;
		else
			arr[cp_index] = _str_dup(token);
		count = 0;
		cp_start = cp_stop + 1;
		cp_index++;
	}
	*start = cp_start;
	*index = cp_index;
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
	char *cpy = str, **arr, *token;
	int start = 0, stop = 0, cpy_index, index = 0;
	str_arr_struct rtn_struct;

	if (_str_len(str) == check_empty(str))
	{
		rtn_struct.arr = malloc(sizeof(char *) + 1);
		rtn_struct.arr[0] = (char *) 0;
		rtn_struct.arr_size = 0;
		return (rtn_struct);
	}

	while (cpy[start] == *delim)
		start++;
	stop = cpy_index = start;

	while (cpy[cpy_index])
	{
		printf("Strtok %c\n", cpy[cpy_index]);
		if (cpy[cpy_index] == *delim)
			stop = cpy_index;

		if (cpy[cpy_index + 1] == '\0')
			stop = cpy_index + 1;

		if ((cpy[cpy_index - 1] == *delim || cpy[cpy_index + 1] == '\0')
		&& stop > start)
		{
		printf("Start copy %c\n", cpy[cpy_index]);
			token = malloc(sizeof(char) * (stop - start));
			if (index == 0)
				arr = malloc(sizeof(char) * (stop - start));
			else
				arr[index] = malloc(sizeof(char) * (stop - start));
			copy_characters(&start, &stop, &index, arr, token, cpy, delim);
		}
		cpy_index++;
	}
	rtn_struct.arr = arr;
	printf("Strtok %s\n", arr[1]);
	sleep(100);
	rtn_struct.arr_size = index;
	rtn_struct.arr[index] = (char *) 0;
	return (rtn_struct);
}

str_arr_struct _strtok(char *str, char *delim)
{
	char *cp = str, *token, *cp_token;
	int i = 0, index = 0;
	str_arr_struct cmd_arr;

	token = malloc(sizeof(char) * _str_len(cp) + 1);
	cmd_arr.arr = malloc(sizeof(char **));

	while (*cp)
	{
		if (*cp == *delim)
		{
			int set = 0;

			while (*cp == *delim)
			{
				if (*(cp + 1) == '\0' && index == 0)
					break;
				cp++;
			}
			token [i] = '\0';
			cp_token = _str_dup(token);
			cmd_arr.arr[index] = malloc(sizeof(char) * _str_len(cp_token));
			cmd_arr.arr[index] = _str_dup(cp_token);
			index++;
			while (token[set])
			{
				token[set] = '\0';
				set++;
			}
			i = 0;
		}
		token[i] = *cp;
		if (*(cp + 1) == '\0' && *cp != '\0')
		{
			token [i + 1] = '\0';
			cp_token = _str_dup(token);
			cmd_arr.arr[index] = malloc(sizeof(char) * _str_len(cp_token));
			cmd_arr.arr[index] = cp_token;
			index++;
		}
		cp++;
		i++;
	}
	/*i = 0;
	while (i < index)
	{
		printf("\n=======Argv %s=============\n", cmd_arr.arr[i]);
		i++;
	}*/
	cmd_arr.arr[index] = malloc(sizeof(char *));
	cmd_arr.arr[index] = (char *) 0;
	cmd_arr.arr_size = index;

	return (cmd_arr);
}
