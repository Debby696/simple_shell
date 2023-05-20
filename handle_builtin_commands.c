#include "shell.h"

/**
 * check_built_cmd - function that checks for built in commands
 * @str: command line argument.
 * Return: 1 if a builtin argument is found 0 if none is found
 */
int check_built_cmd(char *str)
{
	if (str == NULL)
		return (0);
	if (_strcmp(str, "setenv") == 0)
		return (1);
	if (_strcmp(str, "unsetenv") == 0)
		return (1);
	if (_strcmp(str, "exit") == 0)
		return (1);
	if (_strcmp(str, "cd") == 0)
		return (1);
	return (0);
}
/**
 * string_to_int - function that converts a string to an int.
 * @str: string to be converted.
 * Return: str as an int.
 */
int string_to_int(char *str)
{
	int num = 0, i = 0;

	for (; str[i] != '\0'; i++)
	{
		num = num * 10 + (str[i] - 48);
	}
	return (num);
}
/**
 * check_digit - function that checks if all character in a string are digits.
 * @str: string inputt.
 * Return: 0 if all are string else -1.
 */
int check_digit(char *str)
{
	int x = 0;

	while (str[x] != '\0')
	{
		if (str[x] >= '0' && str[x] <= '9')
		{
			x++;
			continue;
		}
		return (-1);
	}
	return (0);
}
/**
 * handle_exit - function that handle the exit built in command.
 * @argv: list of command line strings
 * @parent_name: name of calling process.
 * Return void.
 */
void handle_exit(char **argv, char *parent_name)
{
	char err[4096];
	int x = 0;

	_strcpy(&err[0], parent_name);
	_strcpy(&err[_strlen(err)], ": ");

	while (argv[x])
	{
		x++;
	}
	if (x == 1)
	{
		write(STDERR_FILENO, "exit\n", _strlen("exit\n"));
		exit(0);
	}
	else if (x == 2 && check_digit(argv[1]) == 0)
	{
		if (isatty(STDIN_FILENO))
			write(STDERR_FILENO, "exit\n", _strlen("exit\n"));
		exit(string_to_int(argv[1]));
	}
	else if (x > 2 && check_digit(argv[1]) == 0)
	{
		_strcpy(&err[_strlen(err)], "exit: too many arguments\n");
		write(STDERR_FILENO, err, _strlen(err));
		return;
	}
	else
	{
		_strcpy(&err[_strlen(err)], "exit: ");
		_strcpy(&err[_strlen(err)], argv[1]);
		_strcpy(&err[_strlen(err)], ": numeric argument required\n");
		write(STDERR_FILENO, err, _strlen(err));
		exit(2);
	}
}
/**
 * handle_built_in_commands - function that handles shell built in commands.
 * @argv: list of cli arguments.
 * @env: list of environment variables.
 * @parent_name: name of calling process.
 * Return: void.
 */
void handle_built_in_commands(char **argv, char **env, char *parent_name)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		handle_exit(argv, parent_name);
		return;
	}
	if (_strcmp(argv[0], "setenv") == 0)
		handle_setenv(argv, env, parent_name);

	if (_strcmp(argv[0], "unsetenv") == 0)
		handle_unsetenv(argv, env, parent_name);
}

