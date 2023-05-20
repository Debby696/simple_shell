#include "shell.h"

/**
 * _strcmp - function that compares two.
 * @s1: first input string
 * @s2: second input string
 * Return: if strings are equal it returns 0 if not -1
 */
int _strcmp(char *s1, char *s2)
{
	char *cpy_1 = s1, *cpy_2 = s2;

	while ((*cpy_1 && *cpy_2) && (*cpy_1 == *cpy_2))
	{
		cpy_1++;
		cpy_2++;

	}
	return (*cpy_1 - *cpy_2);
}

