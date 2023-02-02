#include <stdio.h>
#include <stdlib.h>

int Cmp(const void *a,const void *b) {
    int *left = (int *)a;
    int *right = (int *)b;
    return *left - *right;
}

int a[2000005] = {0};
int main()
{
    int n = 0;
    int m = 0;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&a[i]);
    }
    qsort(a, m, sizeof (int), Cmp);

    for (int i = 0; i < m; ++i) {
        printf("%d ", a[i]);
    }

    return 0;
}