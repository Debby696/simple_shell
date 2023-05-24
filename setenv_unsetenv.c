#include "shell.h"

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
	char *new_env, *err_msg;

	while (argv[x])
		x++;
	err_msg = _strcat(_strcat(parent_name, ": "), "setenv: ");
	if (x != 3)
	{
		err_msg = x > 3 ? _strcat(err_msg, "Too many arguments\n")
		: _strcat(err_msg, "Fewer arguments than expected\n");
		write(STDERR_FILENO, err_msg, _str_len(err_msg));
		return (-1); /*exit(EXIT_FAILURE);*/
	}

	while (env[env_len] != NULL &&
		_strcmp(_strtok(env[env_len], "=").arr[0], argv[1]) != 0)
		env_len++;

	if (env[env_len] == NULL)
	{
		new_env = _strcat(_strcat(argv[1], "="), argv[2]);
		env[env_len] = malloc(sizeof(char) * _str_len(new_env) + 1);
		env[env_len] = new_env;
		env[env_len + 1] = malloc(sizeof(char *));
		env[env_len + 1] = (char *) 0;
		return (0); /*exit(EXIT_SUCCESS);*/
	}
	else
	{
		new_env = _strcat(_strcat(argv[1], "="), argv[2]);
		env[env_len] = malloc(sizeof(char) * _str_len(new_env) + 1);
		env[env_len] = new_env;
		return (0); /*exit(EXIT_SUCCESS);*/
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
	int env_len = 0, index = 0, check = 0, x = 0;
	char *err_msg;

	while (argv[x])
		x++;
	err_msg = _strcat(_strcat(parent_name, ": "), "usetenv: ");
	if (x > 2 || x < 2)
	{
		err_msg = x > 2 ? _strcat(err_msg, "Too many arguments\n")
		: _strcat(err_msg, "Fewer arguments than expected\n");
		write(STDERR_FILENO, err_msg, _str_len(err_msg));
		return (-1); /*exit(EXIT_FAILURE);*/
	}
	while (env[env_len] != NULL &&
		_strcmp(_strtok(env[env_len], "=").arr[0], argv[1]) != 0)
		env_len++;

	if (env[env_len] == NULL)
		return (0);/*exit(EXIT_SUCCESS);*/

	while (env[check] != NULL)
	{
		if (check == env_len)
			check++;

		if (env[check] == NULL)
			break;

		env[index] = env[check];
		index++;
		check++;
	}
	env[index] = (char *) 0;
	return (0); /*exit(EXIT_SUCCESS);*/
}

