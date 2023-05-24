#include "shell.h"
#include <stdlib.h>

/**
* free_mem -function that frees memory of string arrays.
* @argv: String arrays thats been allocated memory.
* Return: void.
*/
void free_mem(char **argv)
{
	int x = 0;

	while (argv != NULL && argv[x] != NULL)
	{
		free(argv[x]);
		x++;
	}
}

