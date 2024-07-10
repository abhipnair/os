# include <stdio.h>
# define MAX_SIZE 30
int main(){

    int pids[MAX_SIZE], arrival_times[MAX_SIZE], burst_times[MAX_SIZE], completion_times[MAX_SIZE];
    int waiting_times[MAX_SIZE], turn_around_times[MAX_SIZE];
    int no_of_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &no_of_processes);
    for (int i = 0; i < no_of_processes; i++){
        printf("Enter the pid: ");
        scanf("%d", &pids[i]);
        printf("Enter the arrival time: ");
        scanf("%d", &arrival_times[i]);
        printf("Enter the burst time: ");
        scanf("%d", &burst_times[i]);

    }

    for (int i = 0; i < no_of_processes - 1; i++){

        for (int j = 0; j < no_of_processes - 1 - i; j++){
            if(arrival_times[j] > arrival_times[j + 1]){

                int temp = pids[j];
                pids[j] = pids[j + 1];
                pids[j + 1] = temp;

                temp = burst_times[j];
                burst_times[j] = burst_times[j + 1];
                burst_times[j + 1] = temp;

                temp = arrival_times[j];
                arrival_times[j] = arrival_times[j + 1];
                arrival_times[j + 1] = temp;
            }
        }

    }

    completion_times[0] = burst_times[0];

    for (int i = 1 ; i < no_of_processes; i++){

        completion_times[i] = completion_times[i - 1] + burst_times[i];

    }

    int total_tat_time = 0, total_wt_time = 0;

    for (int i = 0; i < no_of_processes; i++){
        turn_around_times[i] = completion_times[i] - arrival_times[i];
        waiting_times[i] = turn_around_times[i] - burst_times[i];

        total_tat_time += turn_around_times[i];
        total_wt_time += waiting_times[i];
    }

    printf("The execution order is: \n");
    printf("PID\tArrival time\tBurst time\tCompletion time\tTurn around time\tWaiting time\n");
    for (int i = 0; i < no_of_processes; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", pids[i], arrival_times[i], burst_times[i], completion_times[i], turn_around_times[i], waiting_times[i]);
    }

    float avg_wt_time = (float) total_wt_time / no_of_processes;
    float avg_tat_time = (float) total_tat_time / no_of_processes;

    printf("Avg. Turn around time is: %.2f\n", avg_tat_time);
    printf("Avg. Waiting time is: %.2f\n", avg_wt_time);


    return 0;
}