#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Cmp(const void *x,const void *y) {
    char *p = (char*)x;
    char *q = (char*)y;
    size_t len1 = strlen(x);
    size_t len2 = strlen(y);
    size_t max = len1 > len2 ? len1 : len2;
    size_t min = len1 < len2 ? len1 : len2;

    for (int ip = 0,iq = 0; ip < max && iq < max; ip++,iq++) {
        if (p[ip] > q[iq]) return -1;
        if (p[ip] < q[iq]) return 1;
        if (ip == len1 - 1) ip -= len1;
        if (iq == len2 - 1) iq -= len2;
    }
    return 0;
}

int main()
{
    int N = 0;
    scanf("%d",&N);
    char a[25][15] = {0};
    for (int i = 0; i < N; ++i) {
        scanf("%s",a[i]);
    }

    qsort(a,N,15,Cmp);

    char ans[205] = {0};
    for (int i = 0; i < N; ++i) {
        strcat(ans,a[i]);
    }
    printf("%s",ans);

    return 0;
}