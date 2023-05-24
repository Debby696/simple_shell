#include <stdio.h>

char [2][2] arrays()
{
	char arr[2][2] = {{'a', 'd'}, {'c', 'b'}};
	return (arr);
}
int main (void)
{
	char rtn[2][2];
	printf("Hi there %s\n", arrays());
	return (0);
}
