#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Apple;
Apple t[5005];

int Cmp (const void *a,const void *b) {
    Apple *p = (Apple*)a;
    Apple *q = (Apple*)b;
    return p->y - q->y;
}

int main () {
    int n = 0;
    int s = 0;
    int a = 0;
    int b = 0;
    scanf("%d%d%d%d",&n,&s,&a,&b);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&t[i].x,&t[i].y);
        if (t[i].x > a + b) {
            i--;
            n--;
        }
    }
    qsort(t,n,sizeof (Apple),Cmp);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s >= t[i].y) {
            s -= t[i].y;
            ans++;
        }
    }
    printf("%d",ans);

    return 0;
}