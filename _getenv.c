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
	int x = 0;
	char *rtn_str = NULL;

	while (env[x] != NULL)
	{
		rtn_str = malloc(sizeof(_strtok(env[x], "=").arr[0]) + 1);
		rtn_str = _strtok(env[x], "=").arr[0];
		if (_strcmp(env_name, rtn_str) == 0)
		{
			free(rtn_str);
			return (_strtok(env[x], "=").arr[1]);
		}
		x++;
	}
	return (NULL);
}

