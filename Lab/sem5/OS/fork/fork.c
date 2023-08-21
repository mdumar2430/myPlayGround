#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	printf("PPID\t-Process-\tPID\n");
	int pid1=fork();
	if(pid1!=0)
      	{
		int pid2=fork();
		if(pid2==0)
		{
			printf("%d\t-P2-\t\t%d\n", getppid(),getpid());
			int pid3=fork();
			if(pid3==0)
				printf("%d\t-P3-\t\t%d\n", getppid(),getpid());
		}
		else
		{
			printf("%d\t-P0-\t\t%d\n", getppid(),getpid());
		}
	}
	else
	{
		printf("%d\t-P1-\t\t%d\n", getppid(),getpid());
	}
	return 0;
}
