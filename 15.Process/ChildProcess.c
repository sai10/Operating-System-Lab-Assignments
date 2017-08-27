#include  <stdio.h>
#include <stdlib.h>
#include  <sys/types.h>
#include <unistd.h>
int  main()
{
    pid_t pid = fork();
    if (pid == 0)
        printf("Child process created and its pid is %d and its parent pid is %d \n",getpid(),getppid());
    else if (pid > 0)
        printf("Parent process created,the pid of current process is %d \n", getpid()); 
    else
	exit(10);
    return 0;
}
