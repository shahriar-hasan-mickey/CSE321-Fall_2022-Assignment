#include <stdio.h>

void avg_wt(int *wt, int size){
	int total = 0;
	for(int i = 0; i < size; i++){
		total+=*(wt+i);
	}

	printf("\nAverage waiting time: %0.1f", (((float) total)/((float) size)));
}

void avg_ta(int *ta, int size){
	int total = 0;
	for(int i = 0; i < size; i++){
		total+=*(ta+i);
	}

	printf("\nAverage turnaround time: %0.1f\n", (((float) total)/((float) size)));
}

int main(){
	int bt[20], temp_bt[20], at[20], p[20], ta[20], ct[20], wt[20], count, time, i, no_of_process, highest_priority_index;

	printf("PLEASE STATE THE NUMBER OF PROCESSES: ");
	scanf("%d", &no_of_process);

	printf("\nProvide the arrival time, burst time and priority value in the following pattern:\n\tAT\tBT\tPT\n");
	for(i = 0; i < no_of_process; i++){
		printf("P%d\t", i+1);
		scanf("%d\t%d\t%d", &at[i], &bt[i], &p[i]);
		/*
		printf("P%d AT: ", i+1);
		scanf("%d", &at[i]);

		printf("P%d BT: ", i+1);
		scanf("%d", &bt[i]);


		printf("P%d PRIORITY: ", i+1);
		scanf("%d", &p[i]);

		*/
		temp_bt[i] = bt[i];
	}

	printf("\n");
	
	printf("Gantt chart (each instance represents every 1s interval):\n");
	temp_bt[19] = 999999;
	p[19] = 999999;
	count = 0;
	for(time = 0; count < no_of_process; time++){
		highest_priority_index = 19;
		for(i = 0; i < no_of_process; i++){
			if(at[i] <= time  && ((p[i] < p[highest_priority_index]  && temp_bt[i] > 0 ) || p[i] == p[highest_priority_index] && temp_bt[i] < temp_bt[highest_priority_index] && temp_bt[i] > 0)){
				highest_priority_index = i;
			}
		}
		temp_bt[highest_priority_index]--;
		printf("P%d ", highest_priority_index+1);

		if(temp_bt[highest_priority_index] == 0){
			count++;
			ct[highest_priority_index] = time + 1;
			ta[highest_priority_index] = ct[highest_priority_index] - at[highest_priority_index];
			wt[highest_priority_index] = ta[highest_priority_index] - bt[highest_priority_index];
		}
	}
	

	printf("\n\nProc\tAT\tBT\tCT\tWT\tTAT\tPRIORITY\n");
	for(i = 0; i < no_of_process; i++){
		printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], wt[i], ta[i], p[i]);
	}

	avg_wt(wt, no_of_process);
	avg_ta(ta, no_of_process);

	return 0;
}
