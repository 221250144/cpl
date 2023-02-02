#include <stdio.h>

#define N 1000000007

int C(int m) {
    if (m < 2) {
        return 0;
    }
    return m * (m - 1) / 2;
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    int a;
    int cnt[5005] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a);
        cnt[a]++;
    }
    long long ans = 0;
    for (int i = 1; i <= 5000; ++i) {
        for (int j = i; j <= 5000; ++j) {
            if (cnt[i] && cnt[j] && i + j <= 5000) {
                if (i != j) {
                    ans += cnt[i] * cnt[j] * C(cnt[i + j]);
                    ans %= N;
                } else {
                    ans += C(cnt[i]) * C(cnt[i + j]);
                    ans %= N;
                }
            }
        }
    }
    printf("%lld",ans);

    return 0;
}