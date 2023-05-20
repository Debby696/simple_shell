#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *_strcpy(char *dest, char *src);
int _strlen(char *str);
int _getline(char *lineptr, int *len);
char *_strdup(char *str);
void run_command(char **argv, char **env, char *parent_name);
void run_child_process(char *parent_name, char **argv, char **env);
int _strcmp(char *s1, char *s2);
char *_getenv(char *env_name, char **env);
char *_strcat(char *dest, char *src);
int check_built_cmd(char *str);
void handle_built_in_commands(char **argv, char **env, char *parent_name);
#endif
