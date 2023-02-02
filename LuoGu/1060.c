#include <stdio.h>

long long max(long long a,long long b) {
    return a > b ? a : b;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int w[30] = {0};
    int v[30] = {0};
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d",&w[i],&v[i]);
        v[i] *= w[i];
    }
    long long d[30005] = {0};
    for (int i = 1; i <= m; ++i) {
        for (int j = n; j > w[i]; j--) {
            d[j] = max(d[j],d[j - w[i]] + v[i]);
        }
    }
    printf("%lld",d[n]);

    return 0;
}