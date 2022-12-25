#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MaxCrops 5 // maximum crops a Farmer can produce or a ShopOwner can take
#define warehouseSize 5 // size of the warehouse

sem_t full;
sem_t empty;

int in = 0;
int out = 0;


/*
PROBLEMS:
1. Shared memory ; so needs to manage the shared memory so that one can use at a time getting rid of race condition
2. Consuming from empty buffer; 
3. Producing and inserting to full buffer;
(2 & 3 are issue regarding unbounded buffer)

SOLUTIONS:
'in' is shared between the 5 farmers
'out' is shared between the 5 shopowners
so individually they need to be controlled using mutex

to ensure shoponwer cannot take anything from emty buffer a semephore variable is to be used
to ensure farmer cannot add anything to filled buffer different semaphore variable is to be used
 */

char crops[warehouseSize] = {'R', 'W', 'P', 'S', 'M'}; // indicating room for different crops
char warehouse[warehouseSize] = {'N', 'N', 'N', 'N', 'N'};//initially all the room is empty


void *Farmer(void *far);
void *ShopOwner(void *sho);


pthread_mutex_t mutex;

int main(){
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, warehouseSize);
	sem_init(&full, 0, 0);

	pthread_t Far[5], Sho[5];

	int a[5] = {1, 2, 3, 4, 5};

	int i;



	/* create 5 thread for Farmer 5 thread for Shopowner */

	for(i = 0; i < MaxCrops; i++){
		pthread_create(&Far[i], NULL, (void*) Farmer, &a[i]);
		pthread_create(&Sho[i], NULL, (void*) ShopOwner, &a[i]);
	}

	for(i = 0; i < MaxCrops; i++){
		pthread_join(Far[i], NULL);
		pthread_join(Sho[i], NULL);
	}

	
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
	
	return 0;
}



void *Farmer(void *far){
	
	for(int i = 0; i < MaxCrops; i++){
		sem_wait(&empty);
			pthread_mutex_lock(&mutex);
				warehouse[in] = crops[in];
				printf("Farmer %d: Insert crops %c at %d\n", *(int*)far, warehouse[in], in);
				in = (in+1)%warehouseSize;
			pthread_mutex_unlock(&mutex);									
		sem_post(&full);
	}
	printf("Farmer%d: %s\n", *(int*)far, warehouse);
}

void *ShopOwner(void *sho){
	
	for(int i = 0; i < MaxCrops; i++){
		sem_wait(&full);
			pthread_mutex_lock(&mutex);
				printf("Shop owner  %d: Remove crops %c from %d\n", *(int*)sho, warehouse[out], out);
				warehouse[i] = 'N';
				out = (out+1)%warehouseSize;
			pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
	printf("ShopOwner%d: %s\n", *(int*)sho, warehouse);
}
