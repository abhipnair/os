# include <stdio.h>
# include <stdlib.h>
# define MAX_SIZE 20

int main(){

    int head, tracks, diskq[MAX_SIZE], no_of_req, head_index, total_seek_time = 0;

    printf("Enter the no.of requests: ");
    scanf("%d", &no_of_req);

    printf("Enter the no.of tracks: ");
    scanf("%d", &tracks);

    printf("Enter the inital head posititon: ");
    scanf("%d", &head);

    diskq[0] = 0;
    printf("Enter the disk queue: ");
    for(int i = 1; i <= no_of_req; i++){
        scanf("%d", &diskq[i]);
    }
    diskq[no_of_req+1] = head;
    diskq[no_of_req + 2] = tracks;
    no_of_req+=3;

    for (int i = 0; i < no_of_req - 1; i++){
        for (int j = 0; j < no_of_req - 1 - i; j++){

            if(diskq[j] > diskq[j + 1]){
                int temp = diskq[j];
                diskq[j] = diskq[j + 1];
                diskq[j + 1] = temp;
            }

        }
    }

    printf("Disk queue is: ");
    for (int i = 0; i < no_of_req; i++){
        printf("%d  ", diskq[i]);

    }

    // finding the disk index
    for (int i = 0; i < no_of_req; i++){
        if(diskq[i] == head){
            head_index = i;
            break;
        }
    }

    // head -> 199
    printf("\nOrder of request serves: ");
    for (int i = head_index; i < no_of_req - 1; i++){
        printf("%d  ", diskq[i]);
        total_seek_time += abs(diskq[i] - diskq[i + 1]);
    }
    printf("%d  ", diskq[no_of_req - 1]);
    total_seek_time += diskq[no_of_req - 1];

    for (int i = 0; i < head_index - 1; i++){
        printf("%d  ", diskq[i]);
        total_seek_time += abs(diskq[i] - diskq[i + 1]);
    }
    printf("%d\n", diskq[head_index - 1]);
    printf("\nTotal seek time is: %d", total_seek_time);
    float avg_seek = (float)total_seek_time / (no_of_req - 3);
    printf("\nAverage seek time is: %f\n", avg_seek);


    return 0;
}