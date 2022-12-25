#include <stdio.h>
#include <stdbool.h>

int main(){
	int n = 6;
	int m = 4;
	int alloc[6][4] = {{0, 1, 0, 3},
			   {2, 0, 0, 3}, 
			   {3, 0, 2, 0},
			   {2, 1, 1, 5},
			   {0, 0, 2, 2},
			   {1, 2, 3, 1}};
	int max[6][4] = {{6, 4, 3, 4},
			 {3, 2, 2, 4},
			 {9, 1, 2, 6},
			 {2, 2, 2, 8},
			 {4, 3, 3, 7},
			 {6, 2, 6, 5}};
	int total[4] = {10, 6, 10, 15};
	int avail[4] = {0, 0, 0, 0};
	
	int need[6][4];

	int i, j;
	for(i = 0; i < m; i++){
		avail[i] = total[i];
	}

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			need[i][j] = max[i][j] - alloc[i][j];
			avail[j] -= alloc[i][j];
		}
	}

	bool state[4];
	for(i = 0; i < m; i++){
		state[i] = false;
	}

	int true_count = 0;
	int sequence[6];
	for(int k = 0; k < n; k++){
		i = 0;
		for(; i < n; i++){
			
			if(state[i] != true){
				j = 0;
				for(; j < m; j++){
					printf("%d ", need[i][j]);
					if(need[i][j] <= avail[j]){
						state[i] = true;
						printf("true %d, i=%d, j=%d\n", need[i][j], i, j);
					}else{
						state[i] = false;
						printf("false %d, i=%d, j=%d\n\n", need[i][j], i, j);
						break;
					}
				//	printf("here i=%d, j=%d\n", i, j);
				}

				if(state[i] == true){
					sequence[true_count] = i;
					true_count++;
					for(int h = 0; h < m; h++){
						avail[h]+=alloc[i][h];
					}
					printf("\n");
				}
			}
		}
		if(true_count == n){
			break;
		}
	}
	for(i = 0; i < n; i++){
		if(i < n-1){
			printf("P%d --> ", sequence[i]);
		}else{
			printf("P%d\n", sequence[i]);
		}
	}
//	}

	return 0;
}
