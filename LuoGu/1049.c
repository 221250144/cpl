#include <stdio.h>

int max(int a,int b) {
    return a > b ? a : b;
}

int main()
{
    int V,n;
    scanf("%d%d",&V,&n);
    int v[35] = {0};
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&v[i]);
    }
    int d[20005] = {0};
    for (int i = 1; i <= n; ++i) {
        for (int j = V; j >= v[i];j--) {
            d[j] = max(d[j],d[j - v[i]] + v[i]);
        }
    }
    printf("%d",V - d[V]);

    return 0;
}