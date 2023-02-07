#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int id;
} Person;
Person a[1005];

int Cmp(const void *x,const void *y) {
    Person *p = (Person*)x;
    Person *q = (Person*)y;
//    if (p->val == q->val) {
//        return 1;
//    }
    return p->val - q->val;
}


int main () {
    int n = 0;
    scanf("%d",&n);
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i].val);
        a[i].id = i;

    }

    qsort(a + 1,n,sizeof (Person),Cmp);

    for (int i = 1; i <= n; ++i) {
        printf("%d ",a[i].id);
        sum += (n - i) * a[i].val;
    }
    printf("\n");
    double ans = sum / n;
    printf("%.2f",ans);

    return 0;
}