#include "shell.h"

/**
* handle_semicolon - function that splits command line arguments
* at the semicolon
* @str: command line argument.
* @parent: name of parent process.
* @env: list of environment variables.
* Return: void
*/

void handle_semicolon(char *str, char *parent, char **env)
{
	char *arr[4096], cpy[4096];
	int x = 0;

	arr[x] = _strtok(str, ";");

	while (arr[x] != NULL)
	{
		x++;
		arr[x] = _strtok(NULL, ";");
	}
	x = 0;
	while (arr[x] != NULL)
	{
		_strcpy(&cpy[0], arr[x]);
		run(&cpy[0], parent, env);
		x++;
	}
}

