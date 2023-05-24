#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "_str_len.c"

/**
* _str_dup - function that duplicates a string
* @str: string that is to be duplicated
* Return: a copy of the string str
*/ 
char *_str_dup(char *str)
{
	char *cpy = str, *dup = malloc(sizeof(char) * _str_len(cpy) + 1); 
	int i = 0;

	while (*cpy)
	{
		if (*(cpy + 1) == '\0')
		{
			dup[i] = *cpy;
			dup[i +1] = *(cpy + 1);
			break;
		}
		dup[i] = *cpy;
		cpy++;
		i++;
	}
	return (dup);
}
/**
* _strtok - function that splits string into token at the positions specified 
*	by the delimeter.
* @str: Input string that is to be split into tokens.
* @delim: String specifying the positions to split the string at
* Return: The function returns an array of the split strings.
*/ 
char **_strtok(char *str, char *delim)
{
	char *cpy = str, *dup = str, *token, **rtn_arr, *ctrl_str = str;
	int cpy_index = 0, start = 0, stop = 0, count = 0, 
		arr_index = 0, rng = 0, control = 0;

	while(*ctrl_str == *delim)
	{
		ctrl_str++;
		control++;
	}

	cpy = dup = _str_dup(ctrl_str);

	while (*cpy)
	{
		if (*cpy == *delim)
		{
			stop = cpy_index;
		}

		if (*(cpy + 1) == '\0')
		{
			if (control > 0)
				stop = cpy_index + 1 + control;
			else
				stop = cpy_index + 1;
		}

		if (*cpy != *delim && *(cpy - 1) == *delim || *(cpy + 1) == '\0')
		{
			token = malloc(sizeof(char) *(stop - start) + 1);

			rtn_arr[arr_index] = malloc(sizeof(char) * (stop -start) + 1);

			rng = stop - start;
			while (count < rng && dup[start] != *delim)
			{
				rtn_arr[arr_index][count] = dup[start];
				count++;
				start++;
			}
			/*rtn_arr[arr_index] = _str_dup(token);*/
			arr_index++;
			start = cpy_index;
			count = 0;
		}
		cpy_index++;
		cpy++;
	}
	rtn_arr[arr_index] = NULL;
	return (rtn_arr);
}

int main()
{
	char *buff, *arr, *test_buff = "///bin: /usr /bin:/home: /usr";
	size_t len  = 0;
	int x = 0;

	getline(&buff, &len, stdin);
	arr = malloc(sizeof(char) * _str_len(_strtok(test_buff, ":")[3]) + 1);
	arr = _strtok(test_buff, ":")[3];
	printf("Yes %s\n", arr);
	free(buff);
	free(arr);
	
	return (0);
}

