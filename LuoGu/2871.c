#include <stdio.h>

int max(int a,int b) {
    return a > b ? a: b;
}

int main()
{
    int M,N;
    scanf("%d%d", &N, &M);
    int w[3405] = {0};
    int v[3405] = {0};
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &w[i], &v[i]);
    }

    int dp[12885] = {0};
    for (int i = 1; i <= N; ++i) {
        for (int j = M; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    printf("%d",dp[M]);

    return 0;
}