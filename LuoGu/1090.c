#include <stdio.h>
#include <stdlib.h>

int Cmp (const void *a,const void *b) {
    return *(int*)a - *(int*)b;
}

int main () {
    int n = 0;
    int a[10005] = {0};
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof (int),Cmp);
    long long sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum += a[i] + a[i + 1];
        a[i + 1] += a[i];
        a[i] = 0;
        int tmp = i + 1;
        int save = a[tmp];
        while (save > a[tmp + 1] && tmp < n - 1) {
            a[tmp] = a[tmp + 1];
            tmp++;
        }
        a[tmp] = save;
    }
    printf("%lld",sum);

    return 0;
}