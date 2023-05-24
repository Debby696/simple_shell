#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
	pid_t child_1;
	pid_t parent_pid = getpid();
	int wstatus;
	
	for (int i = 0; i < 5; i++)
	{
		child_1 = fork();

		if (child_1 == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_1 == 0)
		{
			sleep(3);
			char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
			execve(argv[0], argv, NULL);
		}
		else
		{
			printf("PID %u\n", child_1);
			printf("Parent ID %u\n", parent_pid);
			wait(&wstatus);
		}
	}
	return (0);
}
