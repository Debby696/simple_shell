#include "shell.h"
#include <sys/stat.h>

/**
 * handle_path - function that checks if a binary file is located in
 *	one of the directory in the path environment variable.
 * @env: list of environment variables.
 * @str: string input
 * Return: A pointee to the first directory contaning the binary @cmd_str
 *	or NULL if the it is not found.
 */
char *handle_path(char **env, char *str)
{
	char path[4096], *path_pt = &path[0], cmd[4096] = {'\0'}, dir[4096] = {'\0'};
	struct stat st;

	if (str == NULL)
		return (NULL);

	if (path_pt == NULL)
		return (NULL);

	_strcpy(path_pt, _getenv("PATH", env));

	cmd[0] = '/';
	_strcpy(&cmd[1], str);

	_strcpy(&dir[0], _strtok(path, ":"));

	_strcpy(&dir[_strlen(dir)], &cmd[0]);

	if (stat(dir, &st) == 0)
	{
		_strcpy(str, &dir[0]);
		return (str);
	}

	while (_strcpy(&dir[0], _strtok(NULL, ":")) != NULL)
	{

		_strcpy(&dir[_strlen(dir)], &cmd[0]);

		if (stat(dir, &st) == 0)
		{
			_strcpy(str, &dir[0]);
			return (str);
		}
	}
	return (str);
}

