#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define READ_END 0
#define WRITE_END 1

int main(int argc, char* argv[]) 
{
    printf("There are ");
    pid_t pid;
    int filedescriptor[2];

    pipe(filedescriptor);
    pid = fork();

    if(pid==0)
    {
        dup2(filedescriptor[WRITE_END], STDOUT_FILENO);
        close(filedescriptor[READ_END]);
        execlp("ls", "ls", "/", NULL);
    }
    else
    { 
        pid=fork();

        if(pid==0)
        {
            
            dup2(filedescriptor[READ_END], STDIN_FILENO);
            close(filedescriptor[WRITE_END]);
            execlp("wc", "wc", "-l",NULL);
        }
    }

    printf(" files in the root directory.\n");
    return 0;
}
