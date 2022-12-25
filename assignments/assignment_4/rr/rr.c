#include <stdio.h>

void avg_wt(int *wt, int size){
	int total = 0;
	for(int i = 0; i < size; i++){
		total+=*(wt+i);
	}

	printf("\nAverage waiting time: %0.1f\n", (((float) total)/ ((float) size)));
}

void avg_ta(int *ta, int size){
	int total = 0;
	for(int i = 0; i < size; i++){
		total+=*(ta+1);
	}
	printf("Average turnaround time: %0.1f\n", (((float) total)/((float) size)));
}

int main(){
        int bt[20], wt[20], ta[20], ct[20], at[20];
        int temp_bt[20], done[20], no_of_process, i, j, time[50], count;
        int q = 20;

        printf("PLEASE STATE THE NUMBER OF PROCESSES: ");
        scanf("%d", &no_of_process);

        for(i = 0; i < no_of_process; i++){
		printf("Enter the burst time (BT) of P%d: ", i+1);
                scanf("%d", &bt[i]);
                at[i] = 0;
                temp_bt[i] = bt[i];
        }

        time[0] = 0;
        printf("\nGantt chart:\t\t");
	count = 0;
        for(i = 0, j = 0; count < no_of_process; i = (i+1)%no_of_process){
                if(temp_bt[i] > 0){
                        if(temp_bt[i] >= q){
                                time[j+1] = time[j] + q;
                                temp_bt[i]-=q;;
                        } else{

                                time[j+1] = time[j] + temp_bt[i];
                                temp_bt[i]-=temp_bt[i];
                        }

                        j++;

                        printf("|   P%d\t", i+1);
                }

                if(temp_bt[i] == 0 && done[i] == 0){
                        count++;
                        done[i] = 1;
                        ct[i] = time[j];
                        ta[i] = ct[i] - at[i];
                        wt[i] = ta[i] - bt[i];
                }
        }

        printf("|\nTime(ms):\t\t%d\t", time[0]);
	
        for(i = 1; i <= j; i++){
                printf("%d\t", time[i]);
        }

        printf("\n\nProc\tAT\tBT\tCT\tWT\tTAT\n");
        for(i = 0; i < no_of_process; i++){
                printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], wt[i], ta[i]);
        }
	
	avg_wt(wt, no_of_process);
	avg_ta(ta, no_of_process);

        return 0;
}
