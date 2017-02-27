#include <stdio.h>


using namespace std;

int main()
{
	pid_t pID = fork(); /* fork from the main process */

	if(pID == -1) /* Check if the fork result is valid */
	{

	}	
	else if(pID == 0) /* Check if we are in the child process */	
	{

	}	
	else /* When we are still in the main process */
	{

	} 				
}