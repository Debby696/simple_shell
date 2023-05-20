#include "shell.h"

/**
 * _getenv - function path gets a shell environment variable.
 * @env_name: name of the environemt variable you want to get.
 * @env: list of environment variable strings.
 * Return: string pointer to the environemt variable or NULL
 *	if it is not found.
 */

char *_getenv(char *env_name, char **env)
{
	char str[4096];
	int x = 0;

	while (env[x] != NULL)
	{
		_strcpy(&str[0], env[x]);
		if (_strcmp(strtok(str, "="), env_name) == 0)
		{
			return (strtok(NULL, "="));
		}
		x++;
	}
	return (NULL);
}

