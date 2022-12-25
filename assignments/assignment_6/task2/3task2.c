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
			printf("%d ", need[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	bool state[4]; // setting the length to 4 and looping until m=4 not n=6 makes the value changed due to overflow when the state value of 4th and 5th 
		       // index are changed, as they do not exist so instead they overwrite the 1st value of need.
	for(i = 0; i < m; i++){
		state[i] = 0;
	}

	printf("need @ %p state @ %p\n", &need, &state);
	int true_count = 0;
	int sequence[6];
	int h;
	for(int k = 0; k < n; k++){
		i = 0;
		for(; i < n; i++){
			if(state[i] == 0){
				j = 0;
				for(; j < m; j++){
					if(need[i][j] > avail[j]){
						state[i] = 0;
						break;
					}

//					if(need[i][j] <= avail[j]){
//						printf("here i->%d, j->%d :%d\n", i, j, need[0][0]);
//						state[i] = 1;
//						printf("here i->%d, j->%d :%d\n", i, j, need[0][0]);
//					}else{
//						state[i] = 0;
//						break;
//					}
				}
				if(j == m){
					state[i] = 1;
				}
				if(state[i] == 1){
					
					sequence[true_count] = i;
					true_count++;
					for(h = 0; h < m; h++){
						avail[h]+=alloc[i][h];
					}
				//	printf("here i->%d:%d\n", i, need[0][0]);
				}

			}


		}
		if(true_count == n){
			break;
		}
		printf("%d\n", need[0][0]);
	}
	for(i = 0; i < n; i++){
		if(i < n-1){
			printf("P%d --> ", sequence[i]);
		}else{
			printf("P%d\n", sequence[i]);
		}
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("%d ", need[i][j]);
		}
		printf("\n");
	}

	return 0;
}
