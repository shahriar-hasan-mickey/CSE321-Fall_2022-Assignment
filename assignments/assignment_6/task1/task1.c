#include <stdio.h>
#include <stdbool.h>

int main(){
	int n = 5; 
	int m = 4;
	int alloc[5][4] = {{0, 1, 0, 3},
			   {2, 0, 0, 0},
			   {3, 0, 2, 0},
			   {2, 1, 1, 5},
			   {0, 0, 2, 2}};
	int max[5][4] = {{6, 4, 3, 4},
			 {3, 2, 2, 1},
			 {9, 1, 2, 6},
			 {2, 2, 2, 8},
			 {4, 3, 3, 7}};
	int total[5] = {10, 5, 7, 11};
	int avail[m];
	int need[5][4];

	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			need[i][j] = max[i][j] - alloc[i][j];
			printf("%d ", need[i][j]);
		}
		printf("\n");
	}

	for(j = 0; j < m; j++){
		avail[j] = total[j];
		for(i = 0; i < n; i++){
			avail[j] -= alloc[i][j];
		}
		printf("%d ", avail[j]);
	}
	printf("\n");
	
	bool state[5];
	for(i = 0 ; i < n; i++){
		state[i] = false;
	}

	int true_count = 0;
	int max_total[4] = {0, 0, 0, 0};
	bool max_greater_than_total = false;
	for(int k = 0; k < n; k++){
		for(i = 0; i < n; i++){
			if(state[i] != true){ // for preventing reiteration inside the set of elements which already had been considered
				for(j = 0; j < m; j++){
					max_total[j] += max[i][j];
					if(need[i][j]  <= avail[j]){
						state[i] = true;
						printf("T %d %d\n", i, j);
					}else{
						printf("F %d %d\n", i, j);
						state[i] = false;
						break;
					}
				}
				if(state[i] == true){
					true_count++;
					printf("P%d\n", i);
					for(int h = 0 ; h < m ; h++){
						avail[h] += alloc[i][h]; // taking the resources back once the constrain is fulfilled
						printf("%d ", avail[h]);
					}
					printf("\n");
				}		
			}
			printf("here\n");
		}
		printf("i ended\n");

		for( i = 0; i < m; i++){
			if(max_total[i] > total[i])
			{	
				max_greater_than_total = true;
				break;
			}
		}
		// if for the first iteration of the whole matrix not even one array is not smaller than or equals to available then its already a deadlock
		if(true_count == 0 || max_greater_than_total){
			printf("DEADLOCK AHEAD!\n");
			break;
		}
		if(true_count == n){
			printf("SAFE AHEAD\n");
			break;
		}
	}
}
