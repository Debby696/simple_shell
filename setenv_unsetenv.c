#include "shell.h"
#include <signal.h>

/**
 * handle_setenv - function that handles setenv built in command.
 * @argv: list of cli arguments.
 * @env: list of environment variables.
 * @parent_name: name of calling process.
 * Return: void.
 */
int handle_setenv(char **argv, char **env, char *parent_name)
{
	int x = 0, env_len = 0;
	char new_env[4096] = {'\0'}, err[4096] = {'\0'}, str[4096] = {'\0'};

	while (argv[x])
		x++;
	_strcpy(&err[0], parent_name);
	_strcpy(&err[_strlen(err)], ": ");
	_strcpy(&err[_strlen(err)], "setenv: ");

	if (x != 3)
	{
		x > 3 ? _strcpy(&err[_strlen(err)], "Too many arguments\n")
		: _strcpy(&err[_strlen(err)], "Fewer arguments than expected\n");
		write(STDERR_FILENO, err, _strlen(err));
		return (-1);
	}
	while (env[env_len] != NULL)
	{
		_strcpy(&str[0], env[env_len]);
		if (_strcmp(_strtok(str, "="), argv[1]) == 0)
			break;
		env_len++;
	}
	if (env[env_len] == NULL)
	{
		_strcpy(&new_env[0], argv[1]);
		_strcpy(&new_env[_strlen(new_env)], "=");
		_strcpy(&new_env[_strlen(new_env)], argv[2]);
		env[env_len] = _strdup(new_env);
		env[env_len + 1] = (char *) 0;
		return (0);
	}
	else
	{
		_strcpy(&new_env[0], argv[1]);
		_strcpy(&new_env[_strlen(new_env)], "=");
		_strcpy(&new_env[_strlen(new_env)], argv[2]);
		env[env_len] = _strdup(new_env);
		return (0);
	}
}

/**
 * handle_unsetenv - function that handles unsetenv built in command.
 * @argv: list of cli arguments.
 * @env: list of environment variables.
 * @parent_name: name of calling process.
 * Return: void.
 */
int handle_unsetenv(char **argv, char **env, char *parent_name)
{
	int len = 0, x = 0;
	char err[4096] = {'\0'}, str[4096] = {'\0'};

	while (argv[x])
		x++;

	_strcpy(&err[0], parent_name);
	_strcpy(&err[_strlen(err)], ": ");
	_strcpy(&err[_strlen(err)], "unsetenv: ");
	if (x > 2 || x < 2)
	{
		x > 2 ? _strcpy(&err[_strlen(err)], "Too many arguments\n")
		: _strcpy(&err[_strlen(err)], "Fewer arguments than expected\n");
		write(STDERR_FILENO, err, _strlen(err));
		return (-1);
	}
	if (env[len] == NULL)
		return (0);

	while (env[len] != NULL)
	{
		_strcpy(&str[0], env[len]);
		if (_strcmp(_strtok(str, "="), argv[1]) == 0)
			break;
		len++;
	}
	if (env[len] != NULL)
	{
		if (env[len + 1] != NULL)
			env[len] = env[len + 1];
		else
			env[len] = (char *) 0;
	}
	return (0);
}

