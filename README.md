# OS-Process-Management
Some coding experience on creating processes, communication between them and message queue processing.

# Data Type: pid_t
The pid_t data type represents process IDs. You can get the process ID of a process by calling getpid. The function getppid returns the process ID of the parent of the current process (this is also known as the parent process ID).

# System Call: fork
The fork system call splits the execution into two processes.The return value of fork is recorded in a variable of type pid_t, which is the POSIX type for process identifiers (PIDs). 

# System Call: wait
The parent process will often want to wait until all child processes have been completed. this can be implemented with the wait() function call.

wait(): Blocks calling process until the child process terminates. If child process has already teminated, the wait() call returns immediately. if the calling process has multiple child processes, the function returns when one returns.

waitpid(): Options available to block calling process for a particular child process not the first one.

# Using fork, exec, wait, pipe
The purpose of this section is to work with fork , exec , and wait to create new processes and use pipe to communicate between parent/child processes. I'll implement a code to illustrate the following command: "ls / | wc -l". This command prints out the number of files in the root path: ls / shows the files/directories in the root path, and its output will be piped through | to wc -l , which counts the number of lines.

