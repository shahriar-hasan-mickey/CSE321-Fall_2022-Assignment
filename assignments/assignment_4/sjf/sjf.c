#include <stdio.h>

void avg_wt(int *wt, int size){
        int total = 0;
        for(int i = 0; i < size; i++){
                total+=*(wt+i);
        }
        printf("Average waiting time: %0.1f\n", (((float) total)/(float) size));

}

void avg_ta(int *ta, int size){
        int total = 0;
        for(int i = 0; i < size; i++){
                total+=*(ta+i);
        }
        printf("Average turnaround time: %0.1f\n", (((float) total)/(float) size));
}


int main(){
        int bt[20], at[20], no_of_process, P[20], wt[20], temp_bt[20], ta[20];
        int i, time, count, index_of_smallest_bt, ct[20];

        // prompting the user for the number of processes
        printf("PLEASE ENTER THE NUMBER OF PROCESSESS: ");
        scanf("%d", &no_of_process);

        // taking the AT and BT for each process from the user
        for(i = 0; i < no_of_process; i++){
                printf("Enter the arrival time (AT) of process P%d: ", i+1);
                scanf("%d", &at[i]);
                printf("Enter the burst time (BT) of process P%d:   ", i+1);
                scanf("%d", &bt[i]);
                printf("\n");
                // making a copy of the burst time array
                temp_bt[i] = bt[i];

        }


        printf("Gantt chart (each instance is for every 1s): ");
        temp_bt[19] = 99999; // if the size is set to 20 then the max index is 19 (always remeber teh max index is (LENTH - 1))
        count = 0;
        // Looping until all processes have completed execution
        for(time = 0; count != no_of_process /*SINCE WE DON'T KNOW THE EXACT RUNNING TIME SO WE ARE COMPARING THE NO. OF PROCESS INSTEAD*/; time++){

                index_of_smallest_bt = 19;  // since max index is 19 it cannot be set to 20 (which was the mistake I did for which I couldn't find the error)
                for(i = 0; i < no_of_process; i++){

                //      printf("%d", i);

                        if(at[i] <= time && temp_bt[i] < temp_bt[index_of_smallest_bt] && temp_bt[i] > 0){
                                //printf("\n%d\n", i);
                                index_of_smallest_bt = i;
                        }
                }
                temp_bt[index_of_smallest_bt]--;
                printf("P%d ", index_of_smallest_bt+1);

                if(temp_bt[index_of_smallest_bt] == 0){
                        count++; // incrementing when a process execution has completed
                        ct[index_of_smallest_bt] = time + 1; //calculating completion time
                        ta[index_of_smallest_bt] = ct[index_of_smallest_bt] - at[index_of_smallest_bt];
                        wt[index_of_smallest_bt] = ta[index_of_smallest_bt] - bt[index_of_smallest_bt];
                }
        }
        printf("\n\nProc\tAT\tBT\tCT\tWT\tTAT\n");
        for(i = 0 ; i < no_of_process; i++){
                printf("P%d\t%-d\t%-d\t%-d\t%-d\t%-d\n", i+1, at[i], bt[i], ct[i], wt[i], ta[i]);
        }


        // calculating the avg waiting time by calling the avg_wt()
        printf("\n");
        avg_wt(wt, no_of_process);
        avg_ta(ta, no_of_process);
        return 0;
}
