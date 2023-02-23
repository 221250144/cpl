#include <stdio.h>

int a[1005][1005] = {0};

int F (int x,int y,int d) {
    int sum = 0;
    for (int i = x - d; i <= x + d; i++) {
        if (i <= x) {
            for (int j = x + y - d - i; j <= y - x + d + i; ++j) {
                sum += a[i][j];
            }
        } else {
            for (int j = y - x + i - d; j <= y + x - i + d; ++j) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

int main () {
    int n = 0;
    int m = 0;
    int d = 0;
    scanf("%d%d%d",&n,&m,&d);

    for (int i = 50; i < n + 50; ++i) {
        for (int j = 50; j < m + 50; ++j) {
            scanf("%d",&a[i][j]);
        }
    }

    int max = -100000;
    int ans[100005][2] = {0};
    int tmp = 0;
    int begin = 0;
    int end = 0;
    for (int i = 50; i < n + 50; ++i) {
        for (int j = 50; j < m + 50; ++j) {
            if (j == 50) {
                tmp = F(i,j,d);
            } else {
                for (int k = i - d; k <= i + d; k++) {
                    if (k <= i) {
                        tmp -= a[k][i + j - 1 - d - k];
                        tmp += a[k][k + d - i + j];
                    } else {
                        tmp -= a[k][j - 1 - i + k - d];
                        tmp += a[k][j + i - k + d];
                    }
                }
            }

            if (tmp > max) {
                max = tmp;
                begin = end;
                ans[begin][0] = i;
                ans[begin][1] = j;
                end = begin + 1;
            } else if (tmp == max) {
                ans[end][0] = i;
                ans[end][1] = j;
                end++;
            }
        }
    }

    printf("%d %d\n",max,end - begin);
    for (int i = begin; i < end; ++i) {
        printf("%d %d\n",ans[i][0] - 49,ans[i][1] - 49);
    }

    return 0;
}