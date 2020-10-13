#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int array[3];
//int a = 0;

void *mythread(void *dummy) {

   pthread_t mythid;
   
   mythid = pthread_self();

   for (int i = 0; i < 1e7; ++i)
   {
   	array[0]++;
   	array[2]++;
   }

   //printf("Thread %u, Calculation result = %d\n", (unsigned)mythid, a);

   return NULL;
}

int main() {

	pthread_t thid1, mythid; 
	int result;

	result = pthread_create( &thid1, (pthread_attr_t *)NULL, mythread, NULL);
   
	if(result != 0){
		printf ("Error on thread create, return value = %d\n", result);
		exit(-1);
	}   
	printf("Thread created, thid = %u\n", (unsigned)thid1);

	mythid = pthread_self();
   
	for (int i = 0; i < 1e7; ++i)
	{
   		array[1]++;
   		array[2]++;
	}
   
	//printf("Thread %u, Calculation result = %d\n", (unsigned)mythid, a);
	pthread_join(thid1, (void **)NULL);

	for (int j = 0; j < 3; ++j)
	{
		printf("a[%d] = %d\n", j, array[j]);
	}
	
	return 0;
}