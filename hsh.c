#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

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

	if (stat(argv[0], &st) != 0)
	{
		perror(parent_name);
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
 * handle_path - function that checks if a binary file is located in
 *	one of the directory in the path environment variable.
 * @env: list of environment variables.
 * @argv: list of command line arguments.
 * Return: A pointee to the first directory contaning the binary @cmd_str
 *	or NULL if the it is not found.
 */
char *handle_path(char **env, char **argv)
{
	char *path = _getenv("PATH", env), cmd[4096], dir[4096];
	struct stat st;
	int i = 0;

	if (argv[0] == NULL)
		return (NULL);

	if (path == NULL)
		return (NULL);

	cmd[0] = '/';
	_strcpy(&cmd[1], argv[0]);

	_strcpy(&dir[0], strtok(path, ":"));
	while (dir[i] != '\0')
		i++;
	_strcpy(&dir[i], &cmd[0]);

	if (stat(dir, &st) == 0)
	{
		_strcpy(argv[0], &dir[0]);
		return (argv[0]);
	}

	while (_strcpy(&dir[0], strtok(NULL, ":")) != NULL)
	{
		i = 0;
		while (dir[i] != '\0')
			i++;

		_strcpy(&dir[i], &cmd[0]);

		if (stat(dir, &st) == 0)
		{
			_strcpy(argv[0], &dir[0]);
			return (argv[0]);
		}
	}
	return (argv[0]);
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
	char *argv[4096], *cp = str;
	int x = 0;
	struct stat st;

	argv[x] = strtok(cp, " ");

	while (argv[x] != NULL)
	{
		x++;
		argv[x] = strtok(NULL, " ");
	}

	argv[x] = (char *) 0;

	if (stat(argv[0], &st) != 0)
		argv[0] = handle_path(env, argv);

	if (check_built_cmd(argv[0]) == 0)
		run_child_process(parent, argv, env);
	else
		handle_built_in_commands(argv, env, parent);

}
/**
 * run_non_interactive - shell function for the non interactive mode.
 * @lineptr: String gotten from the command line.
 * @len: len of lineptr.
 * @env: list of environment variables.
 * @parent: name of the calling process.
 * Return: void
 */
void run_non_interactive(char *lineptr, int len, char *parent, char **env)
{
	char *arr[4096];
	int i = 0;

	if ((_getline(&lineptr[0], &len)) != -1)
	{
		arr[i] = strtok(lineptr, "\n");
		while (arr[i] != NULL)
		{
			i++;
			arr[i] = strtok(NULL, "\n");
		}
		i = 0;
		while (arr[i] != NULL)
		{
			run(arr[i], parent, env);
			i++;
		}
		i = 0;
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
	char lineptr[4096], *arr[4096];
	int len = 0, i = 0;

	if (ac != 1)
		return (1);

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		while ((len = _getline(&lineptr[0], &len)) != -1)
		{
			arr[i] = strtok(lineptr, "\n");
			while (arr[i] != NULL)
			{
				i++;
				arr[i] = strtok(NULL, "\n");
			}
			i = 0;
			while (arr[i] != NULL)
			{
				run(arr[i], av[0], env);
				i++;
			}
			i = 0;
			write(STDOUT_FILENO, "$ ", 2);
		}
		write(STDOUT_FILENO, "\nexit\n", 6);
	}
	else
		run_non_interactive(&lineptr[0], len, av[0], env);
	return (0);
}

