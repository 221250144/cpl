#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double m;
    double v;
    double s;
} f;
f money[105];

int Cmp(const void *a,const void *b) {
    f *x = (f*)a;
    f *y = (f*)b;
    return x->s < y->s;
}

int main () {
    int n = 0;
    int t = 0;
    scanf("%d%d",&n,&t);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf",&money[i].m,&money[i].v);
        money[i].s = money[i].v / money[i].m;
    }
    qsort(money,n,sizeof (f),Cmp);

    double ans = 0;
    for (int i = 0; i < n && t > 0; ++i) {
        if (t >= money[i].m) {
            t -= (int)money[i].m;
            ans += money[i].v;
        } else {
            ans += t * money[i].s;
            t = 0;
        }
    }
    printf("%.2f",ans);

    return 0;
}