#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define ALPHASTART 65
#define ALPHALENGTH 54
#define SPACEPROBABLE 8
int main(int argc, char* argv)
{
	srand(time(0));
	srand(rand());
	void *let;					 // Random 'Letter'
	int ii=0;					 //Counter varible
	int stop=0;					 // Stop signal
	let=malloc(sizeof(int));			//Make sure we actually have memory
	while(ii<INT_MAX && stop==0)
	{
		*(int*)let=ALPHASTART+( rand() % ALPHALENGTH)-SPACEPROBABLE;
	/* Generate a random number, and put it into our letter slot */
		if(*(int*)let<ALPHASTART) 
/* Spaces normally throw a bit of a monkey wrench into our whole typing 
thing, as space is assigned a value much lower than actual letters of 
the english alphabet.  Space is assigned a value of 20 in ASCII, whereas 
the letter A starts at 65.  By assigning numbers lower than 65 as space, 
I split the difference and allow a degree of control as to what is and 
is not a space with the 'Spaceprobable' variable.  I am also avoiding printing
out control characters this way.  */

		{
		printf(" ");
		}
		else
		{
/* If we have a number in our range of actual letters, we once again 
tell the computer to trust me, take this variable, and print it out as a 
'letter'.  Even though type-wise, I've given it no previous evidence of 
this. */
		printf("%c",*(char*)let);
		}
		ii++;    // Loop to next
	}
	free(let);   //Stop reserving the letter when we're done
	return 0;   // Operating system assumes 0 means "no errors."
}
