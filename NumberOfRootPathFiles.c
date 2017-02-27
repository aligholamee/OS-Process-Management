#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);

int main()
{
	const char *path = (char *)"/"; 							 /* Root path */
	const char *childCommand = (char *)"ls |"; 					 /* Command to be executed by the child process */
	const char *parentCommand = (char *)"wc -l"					 /* Command to be executed by the parent process */

	int tunnel[2];												 /* Defining an array of integer to let the child process store a number and parent process to pick that number */
	pid_t pID = fork();											 /* fork from the main process */

	if(pID == -1) 												 /* Check if the fork result is valid */
	{
		//
	}	
	else if(pID == 0) 											 /* Check if we are in the child process */	
	{

	}	
	else														 /* When we are still in the main process */
	{
		//
	} 		

	return 0;		
}