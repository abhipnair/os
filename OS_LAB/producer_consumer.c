# include <stdio.h>

int mutex = 1;
int empty = 3;
int full = 0;
int item = 0;

void wait(int *semaphore){
    (*semaphore)--;
}

void signal(int *semaphore){
    (*semaphore)++;
}

void producer(){
    wait(&mutex);
    wait(&empty);
    signal(&full);
    item++;
    printf("Produced item is: %d\n", item);
    signal(&mutex);
}


void consumer(){
    wait(&mutex);
    wait(&full);
    signal(&empty);
    printf("Consumed item is: %d", item);
    item--;
    signal(&mutex);
}

int main(){

    int choice;

    printf("Menu: \n(1) Produce \n(2) Consume \n(3) EXIT\n");

    while(1){
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        if (choice == 1){
            if (mutex == 1 && empty != 0){
                producer();
            }
            else {
                printf("Buffer is full\n");
            }
        }
        else if(choice == 2){
            if (mutex == 1 && full != 0){
                consumer();
            }
            else {
                printf("Buffer is empty");
            }
        }
        else if (choice == 3){
            printf("\nExiting\n");
            break;
        }
        else {
            printf("Invalid choice\n");
        }
        
    }

    return 0;
}