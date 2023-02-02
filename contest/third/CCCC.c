#include <stdio.h>

#define N 998244353

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long a[200005] = {0};
    for (int i = 1; i <= n; ++i) {
        a[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int type = 0;
        scanf("%d",&type);
        if (type == 1) {
            int l,r,K,D;
            scanf("%d%d%d%d",&l,&r,&K,&D);
            for (int j = l; j <= r; ++j) {
                a[i] = a[i] * K % N;
                long long ans = 1;

            }
        } else {

        }
    }

    return 0;
}