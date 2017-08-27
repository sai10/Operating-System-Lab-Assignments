#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>



void* mythreads(void* vargp)
{
	sleep(10);
	printf("SLEEP IS OVER");
	return NULL;
} 

int main()
{
	
	pthread_t  tid;
	printf("BEFORE THREAD");
	pthread_create(&tid,NULL,&mythreads,NULL);
	pthread_join(tid,NULL);
	printf("AFTER THREAD");
	exit(0);
}
