#include<pthread.h>
#include<stdio.h>

void* print_xs(void* unused)
{
	while(1)
		fputc('x',stderr);
	return NULL;

}

int main()
{

	pthread_t thread_id;    // pthread_t is the type of the thread
	pthread_create(&thread_id,NULL,&print_xs,NULL); // creating a thread 1 -thread is id(thread pointer) 2-  3- 4- data passed to the thread 
	while(1)
		fputc('o',stderr);
	return 0;		

}
