#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t sema;
void *func(void *id){
	int idx = *(int*)id;
	sem_wait(&sema);
	printf("%d entered\n", idx);
	printf("%d exiting\n", idx);
	sem_post(&sema);
}


int main(){
	pthread_t id[2];
	sem_init(&sema, 0, 1);
	int a[2] = {1, 2};

	pthread_create(&id[0], NULL, (void*) func, &a[0]);
	pthread_create(&id[1], NULL, (void*) func, &a[1]);

	pthread_join(id[0], NULL);
	pthread_join(id[1], NULL);
	sem_destroy(&sema);
	return 0;
}
