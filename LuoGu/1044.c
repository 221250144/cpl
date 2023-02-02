#include <stdio.h>

int main () {
    int n = 0;
    scanf("%d",&n);
    long long f[20] = {1,1};
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            f[i] += f[j] * f[i - j - 1];
        }
    }
    printf("%lld",f[n]);

    return 0;
}