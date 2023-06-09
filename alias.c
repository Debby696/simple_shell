#include "shell.h"

/**
 * print_err - function that prints the error message.
 * @str: name of missing alias
 * @parent: name of parent process
 * Return: void.
 */
void print_err(char *str, char *parent)
{
	char err[4096] = {'\0'};

	_strcpy(&err[0], parent);
	_strcpy(&err[_strlen(err)], ": alias: ");
	_strcpy(&err[_strlen(err)], str);
	_strcpy(&err[_strlen(err)], ": not found\n");
	write(STDOUT_FILENO, err, _strlen(err));
}
/**
 * print_alias - function that prints aliases.
 * @arr: list of aliases
 * Return: void.
 */
void print_alias(char arr[4096][1000])
{
	int len = 0;
	char buff[4096] = {'\0'};

	while (arr[len][0] != '\0')
	{
		if (isatty(STDIN_FILENO))
			_strcpy(&buff[0], "alias ");
		_strcpy(&buff[_strlen(buff)], arr[len]);
		_strcpy(&buff[_strlen(buff)], "\n");
		write(STDOUT_FILENO, buff, _strlen(buff));
		len++;
	}
}
/**
 * add_quotation - function that handles alias built in commands.
 * @dest: dest string.
 * @str: source string.
 * Return: void.
 */
void add_quotation(char *dest, char *str)
{
	int x = 0;

	while (*str != '\0')
	{
		if (*str == '\'')
		{
			x++;
			str++;
			continue;
		}
		*dest++ = *str++;
		if (x == 2)
			break;
	}
	_strcpy(&dest[_strlen(dest)], "'");
}
/**
 * handle_alias - function that handles alias built in commands.
 * @argv: list of cli arguments.
 * @parent: name of calling process.
 * Return: void.
 */
void handle_alias(char **argv, char *parent)
{
	static char arr[4096][1000], cpy[4096] = {'\0'}, name[4096] = {'\0'};
	int x = 0, len = 0, index = 0;

	while (argv[x] != NULL)
		x++;
	if (x == 1)
		print_alias(arr);
	len = x = 0;
	while (argv[len] != NULL)
	{
		index = 0;
		while (argv[len][x] != '\0' && argv[len][x] != '=')
			x++;
		if (argv[len][x] == '=')
		{
			_strncpy(&name[0], argv[len], x);
			_strncpy(&cpy[0], arr[index], x);
			if (argv[len][x + 1] != '\'')
			while (arr[index][0] != '\0')
			{
				if (_strcmp(name, cpy) == 0)
				{
					_strcpy(&name[_strlen(name)], "='");
					add_quotation(&name[_strlen(name)], &argv[len][x + 1]);
					_strcpy(&arr[index][0], name);
					return;
				}
				_strncpy(&cpy[0], arr[index], x);
				index++;
			}
			_strcpy(&name[_strlen(name)], "='");
			add_quotation(&name[_strlen(name)], &argv[len][x + 1]);
			_strcpy(&arr[index][0], name);
			return;
		}
		if (len >= 1)
			print_err(argv[len], parent);
		x = 0;
		len++;
	}
}

