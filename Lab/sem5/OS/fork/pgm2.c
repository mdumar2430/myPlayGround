#include <stdio.h>
#include <unistd.h>
int main()
{
 int p1=fork();
 if(p1==0)
 {
  printf("P4 pid:%d ppid:%d\n",getpid(),getppid());
 }
 else
 {
  int p2=fork();
  if(p2==0)
  {
   int p3=fork();
   if(p3 == 0)
    printf("P6 pid:%d ppid:%d\n",getpid(),getppid());
   else
    printf("P3 pid:%d ppid:%d\n",getpid(),getppid());
  }
  else
  {
   int p4 = fork();
   if(p4==0)
   {
    int p5=fork();
    if(p5 == 0)
     printf("P4 pid:%d ppid:%d\n",getpid(),getppid());
    else
     printf("P2 pid:%d ppid:%d\n",getpid(),getppid());
   }
   else
    printf("P1 pid:%d ppid:%d\n",getpid(),getppid());
  }
 }
 return 0;
}
