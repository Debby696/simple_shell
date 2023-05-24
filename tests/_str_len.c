/**
* _str_len - function that gets the length of a string
* @str: String input
* Return: Int value length of string
*/

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

