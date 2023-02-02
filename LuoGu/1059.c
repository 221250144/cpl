#include <stdio.h>
#include <stdlib.h>

int Cmp(const void *a,const void *b) {
    return *(int*)a - *(int*)b;
}

int main()
{
    int N = 0;
    scanf("%d",&N);
    int a[105] = {0};
    for (int i = 0; i < N; ++i) {
        scanf("%d",&a[i]);
    }

    qsort(a,N,sizeof (int),Cmp);
    int cnt = N;
    for (int i = 0; i < N - 1; ++i) {
        if (a[i] == a[i + 1]) {
            a[i] = 0;
            cnt--;
        }
    }
    printf("%d\n",cnt);
    for (int i = 0; i < N; ++i) {
        if (a[i]) printf("%d ",a[i]);
    }

    return 0;
}