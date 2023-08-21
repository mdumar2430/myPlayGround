#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
	printf("%d\n",getpid());
	int pid2= fork();
	int pid3= fork();
	if(pid2==0)
	{
		printf("%d\n", getppid());
	}
	else
	{
}
