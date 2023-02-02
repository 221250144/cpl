#include<stdio.h>

int main()
{
    int m = 0;
    int n = 0;
    int p = 0;
    scanf("%d%d%d",&m,&n,&p);

    int A[200][200] = {0};
    int B[200][200] = {0};
    int C[200][200] = {0};

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d",&A[i][j]);
        }
    }
    //读入A
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= p; ++j) {
            scanf("%d",&B[i][j]);
        }
    }
    //读入B
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= p; ++j) {
            for (int k = 1; k <= n; ++k) {
                int temp = 0;
                temp = A[i][k] * B[k][j];
                C[i][j] += temp;
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= p; ++j) {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }




    return 0;
}