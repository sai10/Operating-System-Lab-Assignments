#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* mythread1(void* vargp)
{
	sleep(5);
	printf("\n\nTHread1 : HOw are you\n");
	return NULL;
}


void* mythread2(void* vargp)
{
	sleep(5);
	printf("\n\nTHread2 : I am fine\n");
	return NULL;
}

void main()
{
	thread_t tid1,tid2;
	printf("BEFORE THREAD");
	pthread_create(&tid1,NULL,&mythread1,NULL);
	pthread_create(&tid2,NULL,&mythread2,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	printf("AFTER THREAD");
	exit(0);
}
