#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int _str_len(char *str)
{
	int len = 0;
	char *cpy = str;

	while (*cpy)
	{
		len++;
		cpy++;
	}
	return (len);
}
char *remove_newline(char *str)
{
	char *cpy = malloc(sizeof(str));
	int i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break;
		cpy[i] = str[i];
		i++;
		
	}
	return cpy;
}
int main()
{
	char *buff, *prompt = "$ ", *lineptr;
	size_t len = 0;
	int buffsize = 0, wstatus;
	pid_t child_pid;
	
	write(STDOUT_FILENO, prompt, _str_len(prompt));

	while ((buffsize = getline(&lineptr, &len, stdin)) != -1)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			char *argv[] = {remove_newline(lineptr), NULL};
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&wstatus);
			write(STDOUT_FILENO, prompt, _str_len(prompt));
		}
	}
	free(lineptr);
	return (0);
}
