# Simple Shell

**Objective: Create a shell named hsh that mimics the bash shell**

## Requirements:

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)
* Write a README with the description of your project
* You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

## Description
hsh is a simple UNIX command language interpreter that works by  reading commands from standard input and executes them.

## How hsh works

* First, it Prints a prompt and waits for a command from the user.
* Creates a child process in which the command is checked
* Checks for built-ins, aliases in the PATH, and local executable programs
* The child process is replaced by the command, which accepts arguments
* When the command is done, the program returns to the parent process and prints the prompt
* The program is ready to receive a new command
* Exit with Ctrl-D or type "exit" 
* Works also in non interactive mode

## Compilation

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Contributors.
* Opeyemi Philip (https://github.com/Debby696).
* Innocent Nderitu

## Tools used:
* c programming language
* Betty linter
* shell
