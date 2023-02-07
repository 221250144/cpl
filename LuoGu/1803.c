#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool occupy[1000005] = {false};

typedef struct {
    int begin;
    int end;
} Contest;
Contest a[1000005];

int Cmp (const void *x,const void *y) {
    Contest *p = (Contest*)x;
    Contest *q = (Contest*)y;
    return p->end - q->end;
}

int main () {
    int n = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&a[i].begin,&a[i].end);
    }

    qsort(a,n,sizeof (Contest),Cmp);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool judge = false;
        for (int j = a[i].begin; j < a[i].end; ++j) {
            if (occupy[j] == true) {
                judge = true;
                break;
            }
        }
        if (judge != true) {
            ans++;
            for (int j = a[i].begin; j < a[i].end; ++j) {
                occupy[j] = true;
            }
        }
    }
    printf("%d",ans);

    return 0;
}