#include<stdio.h>

int F[1005][1200] = {0};

int main() {
    int n = 0;
    int m = 0;
    scanf("%d%d",&m,&n);

    F[1][0] = 1;
    F[2][0] = 2;
    int len = 1;

    for (int k = 3; k <= n - m; k++) {
        for (int j = 0; j < len; j++) {
            F[k][j] = F[k - 1][j] + F[k - 2][j];
        }
        for (int i = 0; i < len; ++i) {
            if (F[k][i] > 9) {
                F[k][i + 1]++;
                F[k][i] %= 10;
                if (F[k][len] != 0) {
                    len++;
                }
            }
        }
    }
    for (int j = len - 1; j >= 0;j--) {
        printf("%d",F[n - m][j]);
    }

    return 0;
}