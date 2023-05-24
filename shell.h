#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <sys/errno.h>

/**
 * struct cmd_struct - a structure that hold command line args.
 * @cmd_arr: Array of command line arguments.
 * @arr_size: number of strings/elements in arr
 */
typedef struct cmd_struct
{
	char **cmd_arr;
	int arr_size;
} cmd_arr_strct;
/**
 * struct strtok_array - a structure that holds the result of strtok
 * @arr: pointer to string pointers
 * @arr_size: number of strings/elements in arr
 */
typedef struct strtok_array
{
	char **arr;
	int arr_size;
} str_arr_struct;

extern char **environ;
int _str_len(char *str);
cmd_arr_strct remove_newline(char *str);
char *_str_dup(char *str);
str_arr_struct _strtok(char *str, char *delim);
int _strcmp(char *s1, char *s2);
char *_getenv(char *env_name, char **env);
char **_get_tokens(char *str);
char *_strcat(char *dest, char *src);
int _getline(char *lineptr, int *len);
void handle_built_in_commands(char **argv, char **env, char *parent_name);
int check_built_cmd(char *str);
int handle_setenv(char **argv, char **env, char *parent_name);
int handle_unsetenv(char **argv, char **env, char *parent_name);
void free_mem(char **argv);
void handle_cd(char **argv, char **env, char *parent_name);
void set_mem(char *str);
char *_strcpy(char *dest, char *src);
#endif

