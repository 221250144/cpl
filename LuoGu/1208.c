#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;
    int a;
} Cow;
Cow t[5005];

int Cmp(const void *a,const void *b) {
    Cow *p = (Cow*)a;
    Cow *q = (Cow*)b;
    return p->p - q->p;
}

int main () {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&t[i].p,&t[i].a);
    }
    qsort(t,m,sizeof (Cow),Cmp);
    int sum = 0;
    int money = 0;
    for (int i = 0; i < m; ++i) {
        if (sum + t[i].a <= n) {
            sum += t[i].a;
            money += t[i].p * t[i].a;
        } else {
            money += (n - sum) * t[i].p;
            break;
        }
    }
    printf("%d",money);

    return 0;
}