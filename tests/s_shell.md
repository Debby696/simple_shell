The GNU C Library ---> https://www.gnu.org/software/libc/manual/html_node/index.html
getpid ----> Get process identifier
getppid ----> Get parent process ID

Process_creation -----> https://www.gnu.org/software/libc/manual/html_node/Process-Creation-Concepts.html

Wait / waitpid ---> If you want your program to wait for a child process to finish executing before continuing, you must do this explicitly after the fork operation, by calling wait or waitpid

Running a command ----> https://www.gnu.org/software/libc/manual/html_node/Running-a-Command.html

executing a program with the system call execve

execve(pathname of file to excute, 
	command line args of new program to be executed,
	environment of the new program)

fork ---> Creates a new child process that runs along with the parent process but on a different stact and heap.

wait ---> Suspends execution of the calling process until on of its children terminates.

stat ---> You can use stat to check if a file exists in a given directory.

getcwd ---> Return a string containing an absolute path of the current working directory.

Shell looks for files in the paths speacified in the PATH environment variable.
If the path give contains any slashes shell doesn't use PATH

read 
	man sh
	man exit
	man 2 form
	man 2 wait
	man getcwd
	man 2 stat


job controll ---> https://www.gnu.org/software/libc/manual/html_node/Job-Control.html

To implement ctrl - D read on signal handling. --GNU C library.




