#include "shell.h"


/**
 * update_dir_env - function that updates the OLDPWD and PWD env vaiables.
 * @var_name: name of environment variable.
 * @new_value: value it will be updated to.
 * @env: list of environment variables.
 * @parent_name: name of calling process.
 * Return: void.
 */
void update_dir_env(char *var_name, char *new_value,
		    char *parent_name, char **env)
{
	char *av[4];

	av[0] = "setenv";
	av[1] = var_name;
	av[2] = new_value;
	av[3] = (char *) 0;
	handle_setenv(av, env, parent_name);
}
/**
 * last_condition - function that runs the last condition.
 * @argv: list of cli arguments.
 * @env: list of environment variables.
 * @parent_name: name of calling process.
 * @err_msg: error message
 * Return: void.
 */
void last_condition(char **argv, char *parent_name, char **env, char *err_msg)
{
	char err[4096] = {'\0'};
	char *cur_dir = _getenv("PWD", env);

	if (chdir(argv[1]) == 0)
	{
		update_dir_env("PWD", argv[1], parent_name, env);
		update_dir_env("OLDPWD", cur_dir, parent_name, env);
	}
	else
	{
		_strcpy(&err[0], err_msg);
		_strcpy(&err[_strlen(err)], ": ");
		_strcpy(&err[_strlen(err)], argv[1]);
		_strcpy(&err[_strlen(err)], ": No such file or directory\n");
		write(STDERR_FILENO, err, _strlen(err));
	}

}
/**
 * handle_cd - function that handles the built in commands.
 * @argv: list of cli arguments.
 * @env: list of environment variables.
 * @parent_name: name of calling process.
 * Return: void.
 */
void handle_cd(char **argv, char **env, char *parent_name)
{
	int x = 0;
	char err[4096];

	_strcpy(&err[0], parent_name);
	_strcpy(&err[_strlen(err)], ": ");
	_strcpy(&err[_strlen(err)], argv[0]);
	while (argv[x])
		x++;
	if (x > 2)
	{
		_strcpy(&err[_strlen(err)], ": too many arguments\n");
		write(STDERR_FILENO, err, _strlen(err));
	}
	if (x == 1)
	{
		char *cur_dir = _getenv("PWD", env);

		if (chdir(_getenv("HOME", env)) == 0)
		{
			update_dir_env("OLDPWD", cur_dir, parent_name, env);
			update_dir_env("PWD", _getenv("HOME", env), parent_name, env);
		}
	}
	if (x == 2)
	{
		char *cur_dir = _getenv("PWD", env);

		if (_strcmp(argv[1], "-") == 0)
		{
			if (chdir(_getenv("OLDPWD", env)) == 0)
			{
				update_dir_env("PWD", _getenv("PWD", env), parent_name, env);
				update_dir_env("OLDPWD", cur_dir, parent_name, env);
			}
		}
		else
			last_condition(argv, parent_name, env, &err[0]);
	}
}

