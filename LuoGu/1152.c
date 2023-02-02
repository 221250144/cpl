#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int Cmp(const void *a,const void *b) {
    return *(int*)b - *(int*)a;
}

int b[500005] = {0};

int main()
{
    int n = 0;
    scanf("%d",&n);
    int a[1005] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        b[cnt++] = abs(a[i] - a[i + 1]);
    }

    qsort(b,500005, sizeof(int),Cmp);

    int temp = n - 1;
    for (int i = 0; i < n - 1; i++) {
        if (b[i] != temp--) {
            printf("Not jolly");
            break;
        }
        if (i == n - 2) {
            printf("Jolly");
        }
    }

    return 0;
}