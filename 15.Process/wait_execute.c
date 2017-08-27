#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
  pid_t pid;
  pid = fork();
  pid = fork();
  int i;
  if(pid == -1)
    {
	printf("\nProcess not created\n");
        exit(0);
    }

  else if(pid == 0)
    {
	wait();
	printf("\nParent process starts\n");
	for(i=0;i<10;i++)
	   printf("%d ",i);
	printf("\nParent process ends\n");
    }

  else
    {
	printf("\nChild process starts\n");
	for(i=0;i<10;i++)
	   printf("%d ",i);
	printf("\nChild process ends\n");
	
    }
}
