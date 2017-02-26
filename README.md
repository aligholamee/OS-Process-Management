# OS-Process-Management
Some coding experience on creating processes, communication between them and message queue processing.


# Using fork, exec, wait, pipe
The purpose of this section is to work with fork , exec , and wait to create new processes and use pipe to communicate between parent/child processes. I'll implement a code to illustrate the following command: "ls / | wc -l". This command prints out the number of files in the root path: ls / shows the files/directories in the root path, and its output will be piped through | to wc -l , which counts the number of lines.

# Data Type: pid_t
The pid_t data type represents process IDs. You can get the process ID of a process by calling getpid. The function getppid returns the process ID of the parent of the current process (this is also known as the parent process ID).