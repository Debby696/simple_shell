#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char **argv, char **envp)
{
	char cwd[PATH_MAX];
	struct stat sb;
	int i = 0;
	const char const *path = getenv("PATH");

	/*get the current working directory- getcwd */
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
	}
	while (environ[i] != NULL)
	{
		printf("%d %s\n", i, environ[i]);
		i++;
	}
	i = 0;
	while (envp[i] != NULL)
	{
		printf(">>>>%d %s\n", i, envp[i]);
		i++;
	}
	printf("Path %s\n", path);
	/* Find if file is in the dir
	* If not go to the parent directory
	*/
	return (0);
}
