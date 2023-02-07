#include <stdio.h>
#include <stdlib.h>

int Cmp (const void *a,const void *b) {
    return *(int*)a - *(int*)b;
}

typedef struct {
    int val;
    int num;
} F;
F b[100005] = {0};

int main () {
    int n = 0;
    scanf("%d",&n);
    int a[100005] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof (int),Cmp);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        b[cnt].val = a[i];
        b[cnt].num++;
        while (a[i] == a[i + 1]) {
            b[cnt].num++;
            i++;
        }
        cnt++;
    }
    int max = 0;




    return 0;
}