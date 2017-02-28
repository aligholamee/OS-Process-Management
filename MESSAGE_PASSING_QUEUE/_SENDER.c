/* The purpose of this file is to send the user input to the reciever through the pipe(tunnel) */
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>						/* Needed for read, write */
#include <stdlib.h>						/* Needed for exit */

#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);

using namespace std;

int main()
{
	char DATA_BUF[100];										/* Input data is written to this char array */
	int F_D;												/* Used as file descriptor to mention the file which is closed/opened */ 
	int BYTE_LENGTH;									    /* Grabbed data byte count which is provided by read function */
	int STRING_CNT;											/* Counts the number of strings in the input file */

	F_D = open("tunnel",O_WRONLY);							/* Open the tunnel pipe for write purpose only */

	if(F_D == -1)
	{
		die("Error occured creating the tunnel.");
		return 1;
	}
	else
	{
		printf("Input data is readable through the terminal...\n");
	}

	while(1)
	{
		BYTE_LENGTH = read(0,DATA_BUF,100);			 	   /* Read data from the input */

		if(BYTE_LENGTH < 0)								   /* When we reach EOF */
			break;		

		write(F_D,DATA_BUF,BYTE_LENGTH);		  
	}

	close(F_D);
	printf("\n");
	return 0;
}
