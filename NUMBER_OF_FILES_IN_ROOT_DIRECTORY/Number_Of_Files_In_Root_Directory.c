#include <stdio.h>												/* Working with I/O */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>												/* System call */
#include <sys/wait.h>

#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);
#define MAX_BUF 2024

int main()
{
	int i = 0;													 /* A simple loop counter :) */
	int counter = 0;											 /* Counts the number of lines in the string provided in the child process */
	int dirFileNum;												 /* Keeps the list of files in the directory */
	int tunnel[2];												 /* Defining an array of integer to let the child process store a number and parent process to pick that number */
	pid_t pID = fork();	
	char buf[MAX_BUF];										     /* Fork from the main process */

	int bytes_read;


	if (pipe(tunnel) == -1)										 /* Pipe from the parent to the child */
		die("pipe died.");

	if(pID == -1) 												 /* Check if the fork result is valid */
	{
		die("fork died.");
	}	
	else if(pID == 0) 											 /* Check if we are in the child process */	
	{
		dup2 (tunnel[1], STDOUT_FILENO);						 /* Redirect standard output */					
		close(tunnel[1]);
		execlp("bin/ls", "bin/ls","/",(char *)NULL);		 		 /* Execute the child command */
		//die("execl died.");
	}	
	else														 /* When we are still in the main process */
	{
		dup2 (tunnel[0], STDIN_FILENO);
		close(tunnel[0]);
		execlp("wc","wc","-l",(char *)NULL);
		//wait(NULL);												 /* Wait until the job is done by the child process */		
	} 		

	return 0;		
}