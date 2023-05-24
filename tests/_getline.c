#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

/**
* _getline - function that reads input from the standard input
* @lineptr: pointer to a string buffer that will store the read input.
* @len: pointer to int input to store the length of the read input.
* Return: number of bytes read or -1 incase EOF only is typed in.
*/
int _getline(char **lineptr, int *len)
{
	char *buff = malloc(sizeof(char) * 4096);
	int index = -1, handle_open;

	while (handle_open = open(STDIN_FILENO, O_RDONLY) && *buff != EOF)
	{
		read(handle_open, buff, 4096);
		index = strlen(buff);
		break;
	}
	*len = index;
	*lineptr = malloc(sizeof(char) * index + 1);
	*lineptr = buff;
	return (index);
}
int main()
{
	char *buff;
	int len;
	_getline(&buff, &len);
	return (0);
}
