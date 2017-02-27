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

# System Call: exec
The exec() call replaces the entire current contents of the process with a new program. It loads the program into the current process space and runs it from the entry point.

So, fork() and exec() are often used in sequence to get a new program running as a child of a current process. Shells typically do this whenever you try to run a program like find - the shell forks, then the child loads the find program into memory, setting up all command line arguments, standard I/O and so forth.

But they're not required to be used together. It's perfectly acceptable for a program to call fork() without a following exec() if, for example, the program contains both parent and child code (you need to be careful what you do, each implementation may have restrictions).

Functions in the exec() family have different behaviours:

    l : arguments are passed as a list of strings to the main()
    v : arguments are passed as an array of strings to the main()
    p : path/s to search for the new running program
    e : the environment can be specified by the caller

You can mix them, therefore you have:

    int execl(const char *path, const char *arg, ...);
    int execlp(const char *file, const char *arg, ...);
    int execle(const char *path, const char *arg, ..., char * const envp[]);
    int execv(const char *path, char *const argv[]);
    int execvp(const char *file, char *const argv[]);
    int execvpe(const char *file, char *const argv[], char *const envp[]);

# Using fork, exec, wait, pipe
The purpose of this section is to work with fork , exec , and wait to create new processes and use pipe to communicate between parent/child processes. I'll implement a code to illustrate the following command: "ls / | wc -l". This command prints out the number of files in the root path: ls / shows the files/directories in the root path, and its output will be piped through | to wc -l , which counts the number of lines.


# IPC: Message Queues
IPC messaging lets processes send and receive messages, and queue messages for processing in an arbitrary order. Unlike the file byte-stream data flow of pipes, each IPC message has an explicit length. Messages can be assigned a specific type. Because of this, a server process can direct message traffic between clients on its queue by using the client process PID as the message type.
Before a process can send or receive a message, the queue must be initialized through the msgget function.
Operations to send and receive messages are performed by the msgsnd() and msgrcv() functions, respectively. 
 When a message is sent, its text is copied to the message queue. The msgsnd() and msgrcv() functions can be performed as either blocking or non-blocking operations. Non-blocking operations allow for asynchronous message transfer -- the process is not suspended as a result of sending or receiving a message. In blocking or synchronous message passing the sending process cannot continue until the message has been transferred or has even been acknowledged by a receiver. IPC signal and other mechanisms can be employed to implement such transfer. A blocked message operation remains suspended until one of the following three conditions occurs:

    The call succeeds.
    The process receives a signal.
    The queue is removed. 


