#include <stdio.h>

int main () {
    int n = 0;
    scanf("%d",&n);
    long long f[1005] = {0,1};
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= i / 2; ++j) {
            f[i] += f[j];
        }
        f[i]++;
    }
    printf("%lld",f[n]);

    return 0;
}