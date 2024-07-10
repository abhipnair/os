# include <stdio.h>
# include <stdlib.h>
# define MAX_SIZE 20


int main(){

    int no_of_requests, head, ioq[MAX_SIZE], total_seek_time = 0;
    float avg_seek_time;

    printf("Enter the no of requests: ");
    scanf("%d", &no_of_requests);

    printf("Enter intial head position: ");
    scanf("%d", &head);

    ioq[0] = head;
    printf("Enter the disk queue: ");
    for (int i = 1; i <= no_of_requests; i++){
        scanf("%d", &ioq[i]);
    }

    ioq[no_of_requests+1] = ioq[no_of_requests];
    for (int i = 0; i <=no_of_requests; i++){
        total_seek_time += abs(ioq[i] - ioq[i + 1]);
    }

    printf("Total seek time is: %d\n", total_seek_time);
    printf("Average seek time: %f\n", (float) (total_seek_time/no_of_requests));

    return 0;
}