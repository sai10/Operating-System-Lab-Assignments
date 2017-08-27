#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
  pid_t pid;
  pid = fork();
  pid = fork();
  if(pid == -1)
    {
	printf("Process not created\n");
        exit(0);
    }

  else if(pid == 0)
    { 
	printf("Child: Child pid = %d, Parent pid = %d \n", getpid(), getppid());
        exit(0);
    }

  else
    { 
	printf("Parent pid = %d \n",getpid());
	exit(0);
    }
}
