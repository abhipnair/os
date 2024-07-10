# include <stdio.h>
# define MAX_SIZE 18

int main(){


    int allocation_matrix[MAX_SIZE][MAX_SIZE], max_matrix[MAX_SIZE][MAX_SIZE], avilable[MAX_SIZE];
    int need_matrix[MAX_SIZE][MAX_SIZE], work[MAX_SIZE], finish[MAX_SIZE] = {0};
    int m, n;
    printf("Enter the number of proceses: ");
    scanf("%d", &m);
    printf("Enter the number of resources: ");
    scanf("%d", &n);

    printf("Enter the allocation matrix: \n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &allocation_matrix[i][j]);
        }
    }

    printf("Enter the max matrix: \n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &max_matrix[i][j]);
        }
    }

    printf("Enter the avilable matrix: \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &avilable[i]);
        work[i] = avilable[i];
    }

    //calaculating need matrix.
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            need_matrix[i][j] = max_matrix[i][j] - allocation_matrix[i][j];
        }
    }

    int ss_index = 0, safe_sequence[MAX_SIZE];

    for (int k = 0; k < m; k++){
        for (int i = 0; i < m; i++){

            if (finish[i] == 0){

                int flag = 0;

                for (int j = 0; j < n; j++){
                    if (need_matrix[i][j] > work[j]){
                        flag = 1;
                    }


                }

                if (flag == 0){

                    safe_sequence[ss_index++] = i;
                    for (int l = 0; l < n; l++){
                        work[l]+=allocation_matrix[i][l];
                    }
                    finish[i] = 1;

                }

            }


        }
    }

    //printing need matrix
    printf("Need matrix is: \n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d  ", need_matrix[i][j]);
        }
        printf("\n");
    }


    printf("\nSafe sequence is: \n");
    for (int i = 0; i < m; i++){

        printf("P%d  ", safe_sequence[i]);

    }

    return 0;
}