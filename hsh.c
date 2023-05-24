#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

/**
 * run_command - A function that executes a command using execve
 * @argv: list of command line arguments.
 * @env: The environment variables passed from the parent process.
 * @parent_name: name of the parent process running the shell
 * Return: void
 */
void run_command(char **argv, char **env, char *parent_name)
{
	if (execve(argv[0], argv, env) == -1)
	{
		parent_name = argv[0];
		perror(parent_name);
		exit(1);
	}
}
/**
 * handle_path - function that checks if a binary file is located in
 *	one of the directory in the path environment variable.
 * @env: list of environment variables.
 * @argv: list of command line arguments.
 * @parent_name: name of shell program
 * Return: A pointee to the first directory contaning the binary @cmd_str
 *	or NULL if the it is not found.
 */
char *handle_path(char **env, char **argv, char *parent_name)
{
	char *path = _getenv("PATH", env), *cmd, *err_msg;
	int x = 0;
	struct stat st;
	str_arr_struct directories = _strtok(path, ":");

	if (argv[0] == NULL)
		return (NULL);

	if (stat(argv[0], &st) == 0)
		return (argv[0]);

	cmd = _strcat("/", argv[0]);

	if (path == NULL)
		return (NULL);

	while (x < directories.arr_size)
	{
		if (stat(_strcat(directories.arr[x], cmd), &st) == 0)
		{
			return (_strcat(directories.arr[x], cmd));
		}
		x++;
	}
	err_msg = _strcat(parent_name, ": ");
	err_msg = _strcat(err_msg, argv[0]);
	return (err_msg);
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

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		exit(1);
	}
	if (child_pid == 0)
		run_command(argv, env, parent_name);
	else
		wait(&wstatus);
}
/**
 * run_non_interactive - shell function for the non interactive mode.
 * @lineptr: String gotten from the command line.
 * @len: len of lineptr.
 * @env: list of environment variables.
 * @parent_name: name of the calling process.
 * Return: void
 */
void run_non_interactive(char *lineptr, int len, char **env, char *parent_name)
{
	char **argv;
	struct stat st;
	cmd_arr_strct cmd_struct;
	int x = 0;

	if (_getline(lineptr, &len) != -1)
	{
		x = 0;
		cmd_struct = remove_newline(lineptr);
		while (x < cmd_struct.arr_size)
		{
			argv = _get_tokens(cmd_struct.cmd_arr[x]);
			if (argv[0] != NULL)
				handle_built_in_commands(argv, env, parent_name);

			if (stat(argv[0], &st) != 0 &&
				check_built_cmd(argv[0]) == 0)
				argv[0] = handle_path(env, argv, parent_name);

			if (stat(argv[0], &st) != 0 && argv[0] != NULL &&
				check_built_cmd(argv[0]) == 0)
				perror(argv[0]);

			if (argv[0] != NULL && stat(argv[0], &st) == 0 &&
				check_built_cmd(argv[0]) == 0)
				run_command(argv, env, parent_name);
			x++;
		}
		free_mem(argv);
		free_mem(cmd_struct.cmd_arr);
	}

}
/**
* main - entry point.
* @ac: Argument count
* @av: Array of command line arguments
* @env: environment variables
* Return: 0 on success
*/
int main(int ac, char **av, char **env)
{
	char *prompt = "$ ", lineptr[4096], **argv;
	int len = 0, x = 0;
	struct stat st;
	cmd_arr_strct cmd_struct;

	if (ac != 1)
		return (1);
	if (isatty(STDIN_FILENO)) /* Run commands in interactive mode */
	{
		set_mem(&lineptr[0]);
		write(STDOUT_FILENO, prompt, _str_len(prompt));
		while ((len = _getline(&lineptr[0], &len)) != -1)
		{
			x = 0;
			cmd_struct = remove_newline(lineptr);
			while (x < cmd_struct.arr_size)
			{
				argv = _get_tokens(cmd_struct.cmd_arr[x]);
				if (argv[0] != NULL)
					handle_built_in_commands(argv, env, av[0]);
				if (stat(argv[0], &st) != 0 &&
					check_built_cmd(argv[0]) == 0)
					argv[0] = handle_path(env, argv, av[0]);
				if (stat(argv[0], &st) != 0 && argv[0] != NULL &&
					check_built_cmd(argv[0]) == 0)
					perror(argv[0]);
				if (argv[0] != NULL && stat(argv[0], &st) == 0 &&
					check_built_cmd(argv[0]) == 0)
					run_child_process(av[0], argv, env);
				x++;
			}
			write(STDOUT_FILENO, "$ ", 2);
			free_mem(argv);
			free_mem(cmd_struct.cmd_arr);
		}
		write(STDOUT_FILENO, "\nexit\n", _str_len("\nexit\n"));
	}
	else  /* Run code in none interactive mode */
		run_non_interactive(lineptr, len, env, av[0]);
	return (0);
}

