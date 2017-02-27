/* The purpose of this file is to grab data which is provided by sender through the tunnel */

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);

int main()
{
	char DATA_BUF[100];										/* Grabbed data is written to this char array */
	int F_D;												/* Used as file descriptor to mention the file which is closed/opened */ 
	int BYTE_LENGTH;									    /* Grabbed data byte count which is provided by read function */
	int STRING_CNT;											/* Counts the number of strings in the grabbed file */


	unlink("tunnel");										/* Make sure non of the internal processes are using this - OFCOURSE NOT :) */
	mkfifo("tunnel",0660);									/* Create a pipe named "tunnel" */

	/* Second argument is used for the permissions:
	  From left to right:
	  '0' is for octal read
	  '6' is for user permission
	  '6' is for group permission
	  '0' is for adjust permission	*/

	F_D = open("tunnel",O_RDONLY);							/* Open the tunnel pipe for read purpose only */

	if(F_D == -1)
	{
		die("Error occured creating the tunnel.");
	}
	else
	{
		printf("Connection established through the tunnel...\n");
	}

	while(1)
	{
		BYTE_LENGTH = 	read(F_D,DATA_BUF,100);			    /* Read data from the tunnel */

		if(BYTE_LENGTH < 0)									/* When we reach EOF */
			break;					
		DATA_BUF[BYTE_LENGTH] = '\0';						/* Append EOF at the end of recieved string */			
		printf("String #%d : %s", STRING_CNT, DATA_BUF);
		STRING_CNT++;
	}

	close(F_D);
	unlink("tunnel");
	printf("\n");
	return 0;
}