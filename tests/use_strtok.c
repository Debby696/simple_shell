#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "_strtok.c"

extern char **environ;

int main()
{
	char *buff, *test_buff = "///bin: /usr /bin:/home: /usr";
	size_t len  = 0;
	int x = 0;
	str_arr_struct arr, env_arr;

	getline(&buff, &len, stdin);
	arr = _strtok(test_buff, " ");

	while (environ[x] != NULL)
	{
		env_arr = _strtok(environ[x], "=");
		printf("%s\n", env_arr.arr[0]);
		x++;
	}

	for (x = 0; x < arr.arr_size; x++)
	{
		printf("Strings %s\n", arr.arr[x]);
	}

	free(buff);
	
	return (0);
}

