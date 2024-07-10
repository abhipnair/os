# include <stdio.h>
# include <stdlib.h>

# define MAX_SIZE 20

int main(){

    int diskq[MAX_SIZE], no_of_rq, head_pos, head_index, total_seek_time = 0;

    printf("Enter the no.of requests: ");
    scanf("%d", &no_of_rq);

    printf("Enter the intial head position: ");
    scanf("%d", &head_pos);

    diskq[0] = 0;
    printf("Enter the disk queue: ");
    for (int i = 1; i <= no_of_rq; i++){
        scanf("%d", &diskq[i]);
    }
    diskq[no_of_rq+1] = head_pos;
    no_of_rq+=2;

    for (int i = 0; i < no_of_rq - 1; i++){
        for (int j = 0; j < no_of_rq - 1 - i; j++){
            if(diskq[j] > diskq[j + 1]){
                int temp = diskq[j];
                diskq[j] = diskq[j + 1];
                diskq[j+1] = temp;
            }
        }
    }

    printf("Disk queue is: ");
    for (int i = 0; i < no_of_rq; i++){
        printf("%d  ", diskq[i]);
    }

    // finding the index of the head position. 
    for (int i = 0; i < no_of_rq; i++){
        if(diskq[i] == head_pos){
            head_index = i;
            break;
        }
    }
    // head --> 0
    printf("\nOrder of the request serviced: ");
    for (int i = head_index; i > 0; i--){
        printf("%d ", diskq[i]);
        total_seek_time += abs(diskq[i] - diskq[i - 1]);
    }
    printf("0 ");
    total_seek_time += diskq[head_index + 1]; // 0 - diskq[head_index+1]

    for (int i = head_index + 1; i < no_of_rq - 1; i++){
        printf("%d ", diskq[i]);
        total_seek_time += abs(diskq[i] - diskq[ i + 1]);
    }
    printf("%d \n", diskq[no_of_rq - 1]); // printing the last value. 

    printf("Total seek time is: %d", total_seek_time);
    printf("\nAverage seek time is: %f\n", (float)(total_seek_time/no_of_rq-2));



    return 0;
}