#include "shell.h"

/**
* remove_newline - function that removes newline character from string.
* @str: String input
* Return: String without newline character
*/

cmd_arr_strct remove_newline(char *str)
{
	char token[4096], *cpy = str, **cmd_arr;
	int i = 0, index = 0;
	cmd_arr_strct rtn_strct;

	cmd_arr = malloc(sizeof(char **));

	while (*cpy)
	{
		if (*cpy == '\n' || *cpy == ';')
		{
			while (*cpy == '\n' || *cpy == ';')
				cpy++;

			token[i] = '\0';
			cmd_arr[index] = malloc(sizeof(char) * _str_len(token) + 1);
			cmd_arr[index] = _str_dup(token);
			index++;
			i = 0;
			set_mem(&token[0]);
		}
		token[i] = *cpy;
		cpy++;
		i++;
	}
	i = 0;
	cmd_arr[index] = malloc(sizeof(char *));
	cmd_arr[index] = (char *) 0;
	rtn_strct.cmd_arr = cmd_arr;
	rtn_strct.arr_size = index;
	return (rtn_strct);
}

