#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main()
{
    char *lineptr = NULL;
    size_t len = 0;
    ssize_t line_size = 0;

    write(STDOUT_FILENO, "$ ", sizeof(char) * 2);

    line_size = getline(&lineptr, &len, stdin);
    
    write(STDOUT_FILENO, lineptr, line_size);
    free(lineptr);

    return (0);

}
