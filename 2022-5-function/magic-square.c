#include<stdio.h>
int a[1000][1000] = {0};

int main()
{
    int n = 0;
    scanf("%d",&n);
    int x = 1;
    int y = n / 2 + 1;
    a[x][y] = 1;

    for (int i = 2; i <= n * n; i++) {
        if (x - 1 < 1) x = x + n;
        if (y + 1 > n) y = y - n;

        if (a[x - 1][y + 1] == 0) {
            a[x - 1][y + 1] = i;
            x = x - 1;
            y = y + 1;
        } else if (a[x - 1][y + 1] != 0) {
            for (int p = 1; p <= n; ++p) {
                for (int q = 1; q <= n; ++q) {
                    if (a[p][q] == i - 1) {
                        a[p + 1][q] = i;
                        x = p + 1;
                        y = q;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}