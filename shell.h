#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *_strcpy(char *dest, char *src);
int _strlen(char *str);
int _getline(char **lineptr, int *len);
char *_strdup(char *str);
void run_command(char **argv, char **env, char *parent_name);
void run_child_process(char *parent_name, char **argv, char **env);
void handle_lineptr(char *lineptr, char *parent, char **env);
int _strcmp(char *s1, char *s2);
char *_getenv(char *env_name, char **env);
char *_strcat(char *dest, char *src);
int check_built_cmd(char *str);
void handle_built_in_commands(char **argv, char **env, char *parent_name);
char *_strtok(char *src, char *delim);
int handle_setenv(char **argv, char **env, char *parent_name);
int handle_unsetenv(char **argv, char **env, char *parent_name);
void handle_cd(char **argv, char **env, char *parent_name);
void run(char *str, char *parent, char **env);
void handle_seperator(char *str, char *parent, char **env);
char *handle_path(char **env, char *str);
void handle_logic_operators(char *str, char *parent, char **env);
#endif
