#include <stdio.h>

int max(int a,int b) {
    return a > b ? a : b;
}

int main()
{
    int v,n,c;
    scanf("%d%d%d",&v,&n,&c);
    int k[10005] = {0};
    int m[10005] = {0};;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d",&k[i],&m[i]);
    }

    int d[10005] = {0};
    for (int i = 1; i <= n; ++i) {
        for (int j = c; j >= m[i]; j--) {
            d[j] = max(d[j], d[j - m[i]] + k[i]);
        }
    }

    if (d[c] >= v) {
        int t = c;
        while (d[t] >= v) t--;
        printf("%d",c - t - 1);
    } else printf("Impossible");

    return 0;
}