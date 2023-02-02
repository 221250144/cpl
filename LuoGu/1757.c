#include <stdio.h>

int max(int a,int b) {
    return a > b ? a: b;
}

int main()
{
    int T,M;
    scanf("%d%d",&T,&M);
    int t[1005] = {0};
    int v[1005] = {0};
    for (int i = 1; i <= M; ++i) {
        scanf("%d%d",&t[i],&v[i]);
    }

    int dp[105][1005] = {0};
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= T; ++j) {
            if (t[i] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - t[i]] + v[i]);
            }
        }
    }
    printf("%d",dp[M][T]);

    return 0;
}