#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/**
* _getline - function that reads input from the standard input
* @lineptr: pointer to a string buffer that will store the read input.
* @len: pointer to int input to store the length of the read input.
* Return: number of bytes read or -1 incase EOF only is typed in.
*/
int _getline(char *lineptr, int *len)
{
	char buff[4096];
	int index = -1, x = 0;

	while (buff[x])
	{
		buff[x] = '\0';
		x++;
	}
	while (read(STDIN_FILENO, buff, 4096) && *buff != EOF)
	{
		index = _strlen(buff);
		break;
	}
	lineptr = _strcpy(lineptr, buff);
	*len = _strlen(lineptr);
	return (index);
}

