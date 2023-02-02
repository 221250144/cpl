#include <stdio.h>

int f[105][10005] = {0};

int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    int a[105] = {0};
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j == a[i]) {
                f[i][j] = f[i - 1][j] + 1;
            } else if (j > a[i]) {
                f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]];
            } else {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    printf("%d",f[n][m]);

    return 0;
}