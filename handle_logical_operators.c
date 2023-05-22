#include "shell.h"
#include <sys/stat.h>

/**
 * handle_logic_operators - function that gets cmd tokens and runs the command.
 * @str: command line arguments.
 * @parent: name of parent program.
 * @env: environment variables.
 * Return: void.
*/
void handle_logic_operators(char *str, char *parent, char **env)
{
	char buff[4096], *arr[4096];
	int i = 0;
	struct stat st;

	arr[i] = _strtok(str, "&&");

	while (arr[i] != NULL)
	{
		i++;
		arr[i] = _strtok(NULL, "&&");
	}
	i = 0;
	while (arr[i] != NULL)
	{
		_strcpy(&buff[0], arr[i]);
		if (stat(handle_path(env, _strtok(buff, " ")), &st) == 0)
			run(arr[i], parent, env);
		else
		{
			run(arr[i], parent, env);
			break;
		}
		i++;
	}
}

