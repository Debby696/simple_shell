#include <unistd.h>
#include <stdlib.h>
/**
 * _getline - function that reads input from the standard input
 * @lineptr: pointer to a string buffer that will store the read input.
 * @len: pointer to int input tonstorre the length of the read input
 * Return: number of bytes read or -1 incase EOF only is typed in.
 */
int _getline(char *lineptr, int *len)
{
	char buff[4096];
	int index = -1;
	set_mem(&buff[0]);
	while (read(STDIN_FILENO, buff, 4096) && *buff != EOF)
	{
		index = _str_len(buff);
		break;
	}
	lineptr = _strcpy(lineptr, buff);
	*len = _str_len(lineptr);
	return (index);
}
