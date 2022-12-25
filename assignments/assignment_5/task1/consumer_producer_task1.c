#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define MAX 10
#define BUFLEN 6
#define NUMTHREAD 2


char buffer[BUFLEN+1];// cannot be BUFLEN if input character is 6 rather it should be BUFLEN + 1
char source[BUFLEN+1];

int pCount = 0;
int cCount = 0;
int buflen;

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;

int thread_id[NUMTHREAD] = {0, 1};
int i = 0;
int j = 0;

void *producer(int *id);
void *consumer(int *id);


int main(){
	int i;
	pthread_t thread[NUMTHREAD];
	
	strcpy(source, "abcdef");
	buflen = strlen(source);

	pthread_create(&thread[0], NULL, (void*) producer, &thread_id[0]);
	pthread_create(&thread[1], NULL, (void*) consumer, &thread_id[1]);

	for(i=0; i < NUMTHREAD; i++){
		pthread_join(thread[i], NULL);
	}

	pthread_mutex_destroy(&count_mutex);
	return 0;
}


void *producer(int *id){
	for(;pCount < MAX; pCount++){
		pthread_mutex_lock(&count_mutex);

		while(buflen == 0){
			pthread_cond_wait(&full, &count_mutex);
		}
		buffer[i] = source[i];
		printf("%d produced %c by Thread %d\n", pCount, buffer[i], *id);
		i = (i+1)%BUFLEN;
		buflen--;
		pthread_mutex_unlock(&count_mutex);
		pthread_cond_signal(&empty);

	}
}

void *consumer(int *id){
	for(;cCount < MAX ; cCount++){
		pthread_mutex_lock(&count_mutex);
		while(buflen == BUFLEN){
			pthread_cond_wait(&empty, &count_mutex);
		}
		printf("%d consumed %c by Thread %d\n", cCount, buffer[j], *id);
		j = (j+1)%BUFLEN;
		buflen++;
		pthread_mutex_unlock(&count_mutex);
		pthread_cond_signal(&full);
				j = (j+1)%BUFLEN;
			pthread_mutex_unlock(&count_mutex);
		}
}

