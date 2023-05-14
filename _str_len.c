/**
 * _str_len - function that gets the length of a string
 * @str: String input
 * Return: int value length of string
 */
int_str_len(char*str)
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

