#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
	const char *path = (char *)"/"; /* Root path */

	const char *childCommand = (char *)"ls |"; /* Command to be executed by the child process */

	const char *parentCommand = (char *)"wc -l" /* Command to be executed by the parent process */

	pid_t pID = fork(); /* fork from the main process */

	if(pID == -1) /* Check if the fork result is valid */
	{
		//
	}	
	else if(pID == 0) /* Check if we are in the child process */	
	{

	}	
	else /* When we are still in the main process */
	{
		//
	} 		

	return 0;		
}