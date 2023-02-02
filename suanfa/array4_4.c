#include<stdio.h>

int main() {
    int A[4][4];
    int B[4][4];

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d",&A[i][j]);
            B[j][3 - i] = A[i][j];
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%-4d",B[i][j]);
            if(j == 3){
                printf("\n");
            }
        }
    }

    printf("\n");

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%-4d",A[i][j]);
            if(j == 3){
                printf("\n");
            }
        }
    }

    return 0;
}