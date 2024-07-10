# include <stdio.h>
# define MAX_SIZE 30


int main(){

    int pids[MAX_SIZE], burst_times[MAX_SIZE], remaining_burst_times[MAX_SIZE];
    int turn_around_times[MAX_SIZE], waiting_times[MAX_SIZE];
    int total_time = 0, total_ta_time = 0, total_wt_time = 0, no_of_processes, completed = 0;
    int time_slice;

    printf("Enter the number of requests: ");
    scanf("%d", &no_of_processes);

    for (int i = 0; i < no_of_processes; i++){
        printf("Enter the pid: ");
        scanf("%d", &pids[i]);
        printf("Enter the burst time: ");
        scanf("%d", &burst_times[i]);
        remaining_burst_times[i] = burst_times[i];
    }

    printf("Enter the time slice: ");
    scanf("%d", &time_slice);

    int i = 0;
    while (completed < no_of_processes){

        if (remaining_burst_times[i] > 0){
            if (remaining_burst_times[i] > time_slice){
                remaining_burst_times[i] -= time_slice;
                total_time += time_slice;
            }
            else {
                total_time += remaining_burst_times[i];
                turn_around_times[i] = total_time;
                waiting_times[i] = turn_around_times[i] - burst_times[i];
                total_ta_time += turn_around_times[i];
                total_wt_time += waiting_times[i];
                remaining_burst_times[i] = 0;
                completed ++;
            }
        }

        i = (i + 1)%no_of_processes;
    }

    printf("The execution order is: \n");
    printf("PID\tBurst time\tTurn around time\tWaiting time\n");
    for (int i = 0; i < no_of_processes; i++){
        printf("%d\t%d\t\t%d\t\t\t%d\n", pids[i], burst_times[i], turn_around_times[i], waiting_times[i]);
    }

    float avg_wt_time = (float)total_wt_time / no_of_processes;
    float avg_ta_time = (float)total_ta_time / no_of_processes;

    printf("Average turn around time is: %.2f\n", avg_ta_time);
    printf("Average waiting time is: %.2f", avg_wt_time);

    return 0;
}