#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main()
{
 	int i,pipe1[2],oddCount=0,evenCount=0;
 	int wrmes[20],rdmes[20];
 	int retmes = pipe(pipe1);
 	if(retmes == -1)
 	{
  		printf("Unable to create pipe 1\n");
  		return 1;
	}
 	if (fork()==0)
 	{
  		printf("\nChild process- Enter a 5 random numbers : \n");
		for (i=0;i<5;i++)
  			scanf("%d",&wrmes[i]);
  		write(pipe1[1],wrmes,sizeof(wrmes));
 	}
 	else
 	{
  		read(pipe1[0],rdmes,sizeof(rdmes));
  		for (i=0;i<5;i++)
  		{
   			if(rdmes[i]%2==0)
				evenCount++;
			else
				oddCount++;
  		}
  		printf("\nParent process:- No.of Odd Numbers: %d 
		No. of Even numbers: %d\n\n",oddCount,evenCount);
 	}
    	return 0;
}
