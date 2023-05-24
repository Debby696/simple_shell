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
	if (chdir(argv[1]) == 0)
	{
		update_dir_env("PWD", argv[1], parent_name, env);
		update_dir_env("OLDPWD", _getenv("PWD", env), parent_name, env);
	}
	else
	{
		err_msg = _strcat(err_msg, ": ");
		err_msg = _strcat(err_msg, argv[1]);
		err_msg = _strcat(err_msg, ": No such file or directory\n");
		write(STDERR_FILENO, err_msg, _str_len(err_msg));
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
	char *err_msg = parent_name;

	err_msg = _strcat(_strcat(err_msg, ": "), argv[0]);

	while (argv[x])
		x++;
	if (x > 2)
	{
		err_msg = _strcat(err_msg, ": too many arguments\n");
		write(STDERR_FILENO, err_msg, _str_len(err_msg));
	}
	if (x == 1)
	{
		if (chdir(_getenv("HOME", env)) == 0)
		{
			update_dir_env("OLDPWD", _getenv("PWD", env), parent_name, env);
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
				update_dir_env("PWD", _getenv("OLDPWD", env), parent_name, env);
				update_dir_env("OLDPWD", cur_dir, parent_name, env);
			}
		}
		else
		{
			last_condition(argv, parent_name, env, err_msg);
		}
	}
}
