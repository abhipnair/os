# include <stdio.h>
# define MAX_SIZE 30

int main(){

    int pids[MAX_SIZE], burst_times[MAX_SIZE], turn_around_times[MAX_SIZE], waiting_times[MAX_SIZE];
    int total_turn_around_time = 0, total_waiting_time = 0, no_of_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &no_of_processes);

    for (int i = 0; i < no_of_processes; i++){
        printf("Enter the pid: ");
        scanf("%d", &pids[i]);
        printf("Enter the burst time: ");
        scanf("%d", &burst_times[i]);

    }

    for (int i = 0; i < no_of_processes - 1; i++){
        for (int j = 0; j < no_of_processes - 1 - i; j++){
            if(burst_times[j] > burst_times[j + 1]){
                int temp = pids[j];
                pids[j] = pids[j + 1];
                pids[j + 1] = temp;

                temp = burst_times[j];
                burst_times[j] = burst_times[j + 1];
                burst_times[j + 1] = temp;
            }
        }
    }

    turn_around_times[0] = burst_times[0];
    for (int i = 1; i < no_of_processes; i++){
        turn_around_times[i] = turn_around_times[i - 1] + burst_times[i];
    }

    for (int i = 0; i < no_of_processes; i++){
        waiting_times[i] = turn_around_times[i] - burst_times[i];
        total_turn_around_time += turn_around_times[i];
        total_waiting_time += waiting_times[i];
    }


    printf("The execution order is: \n");
    printf("PID\tBurst time\tTurn around time\tWaiting time\n");
    for (int i = 0; i < no_of_processes; i++){
        printf("%d\t%d\t\t%d\t\t%d\n", pids[i], burst_times[i], turn_around_times[i], waiting_times[i]);
    }

    float avg_wt_time = (float)total_waiting_time / no_of_processes;
    float avg_ta_time = (float)total_turn_around_time / no_of_processes;

    printf("Average turn around time is: %.2f\n", avg_ta_time);
    printf("Average waiting time is: %.2f", avg_wt_time);

    return 0;
}