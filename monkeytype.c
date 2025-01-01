#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define ALPHASTART 65
#define ALPHALENGTH 56

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
		*(int*)let=ALPHASTART+( rand() % ALPHALENGTH);
		printf("%c",*(char*)let);
		ii++;
	}
	free(let);
	return 0;

}
