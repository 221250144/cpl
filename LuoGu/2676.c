#include <stdio.h>
#include <stdlib.h>

int Cmp(const void *a,const void *b) {
    return *(int*)b - *(int*)a;
}

int main()
{
    int n = 0;
    long long b = 0;
    scanf("%d%lld",&n,&b);
    int save[20005] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&save[i]);
    }

    qsort(save,n,sizeof (int),Cmp);

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += save[i];
        if (sum >= b) {
            printf("%d",i + 1);
            break;
        }
    }

    return 0;
}