#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * check_symbol - function that checks for symbol in first character.
 * @str: String gotten from the command line.
 * @parent: name of the calling process.
 * Return: int
 */
int check_symbol(char *str, char *parent)
{
	char err[4096] = {'\0'};
	int x = 0;

	if (*str == ';' || *str == '&' || *str == '|')
	{
		_strcpy(&err[0], parent);
		_strcpy(&err[_strlen(err)], ": syntax error near unexpected token");
		if (*str == ';')
		{
			*(str + 1) == ';' ? _strcpy(&err[_strlen(err)], "\';;\'")
			: _strcpy(&err[_strlen(err)], " \';\'");
		}
		if (*str == '|')
		{
			*(str + 1) == '|' ? _strcpy(&err[_strlen(err)], "\'||\'")
			: _strcpy(&err[_strlen(err)], " \'|\'");
		}
		if (*str == '&')
		{
			*(str + 1) == '&' ? _strcpy(&err[_strlen(err)], "\'&&\'")
			: _strcpy(&err[_strlen(err)], " \'&\'");
		}
		_strcpy(&err[_strlen(err)], " \n");
		write(STDERR_FILENO, err, _strlen(err));

		return (1);
	}

	while (str[x] != '\0' && (str[x] == ' ' || str[x] == '\n'))
		x++;
	if (x == _strlen(str))
		return (1);
	return (0);
}
/**
 * handle_lineptr - function that handles lineptr from getline.
 * @lineptr: String gotten from the command line.
 * @env: list of environment variables.
 * @parent: name of the calling process.
 * Return: void
 */
void handle_lineptr(char *lineptr, char *parent, char **env)
{
	char *arr[4096];
	int i = 0, x = 0;

	arr[i] = _strtok(lineptr, "\n");
	while (arr[i] != NULL)
	{
		i++;
		arr[i] = _strtok(NULL, "\n");
	}
	i = 0;
	while (arr[i] != NULL)
	{
		while (arr[i][x] != '\0' && arr[i][x] == ' ')
			x++;
		if (_strlen(arr[i]) == x)
		{
			i++;
			continue;
		}
		handle_seperator(arr[i], parent, env);
		i++;
		x = 0;
	}
	i = 0;
}
/**
 * run_child_process - function that forks and runs a child process.
 * @parent_name: Name of the calling process.
 * @argv: list of arguments for execve
 * @env: environment variables that will be passed to execve
 * Return: zero on success 1 on failure
 */
void run_child_process(char *parent_name, char **argv, char **env)
{
	pid_t child_pid;
	int wstatus;
	struct stat st;
	char err[4096], *err_pt = &err[0];

	if (stat(argv[0], &st) != 0)
	{
		_strcpy(err_pt, parent_name);
		_strcpy((err_pt + _strlen(err_pt)), ": ");
		_strcpy((err + _strlen(err_pt)), argv[0]);
		perror(err_pt);
		return;
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror(parent_name);
			exit(1);
		}
	}
	else
		wait(&wstatus);
}
/**
 * run - function that gets cmd tokens and runs the command.
 * @str: command line arguments.
 * @parent: name of parent program.
 * @env: environment variables.
 * Return: void.
*/
void run(char *str, char *parent, char **env)
{
	char *argv[4096], buff[4096] = {'\0'};
	int x = 0;

	argv[x] = _strtok(str, " ");

	while (argv[x] != NULL)
	{
		x++;
		argv[x] = _strtok(NULL, " ");
	}

	argv[x] = (char *) 0;

	_strcpy(buff, argv[0]);

	if (check_built_cmd(argv[0]) == 1)
		handle_built_in_commands(argv, env, parent);
	else
	{
		argv[0] = handle_path(env, buff);
		run_child_process(parent, argv, env);
	}

	x = 0;
	while (buff[x])
	{
		buff[x] = '\0';
		x++;
	}
}
/**
* main - entry point.
* @ac: argument count.
* @av: list of command line arguments.
* @env: list of environment variables.
* Return: int
*/
int main(int ac, char **av, char **env)
{
	char line[4096] = {'c'}, *argv[4096];
	int i = 0;

	if (ac != 1)
		return (1);

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	while (read(STDIN_FILENO, line, 4096) && *line != EOF)
	{
		argv[i] = _strtok(line, "\n");
		if (check_symbol(line, av[0]) == 0)
		{
			while (argv[i] != NULL)
			{
				i++;
				argv[i] = _strtok(NULL, "\n");
			}
			i = 0;

			while (argv[i] != NULL)
			{
				handle_lineptr(argv[i], av[0], env);
				i++;
			}
			i = 0;
			while (line[i] != '\0')
			{
				line[i] = '\0';
				i++;
			}
			i = 0;
		}
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\nexit\n", _strlen("\nexit\n"));
	return (0);
}
