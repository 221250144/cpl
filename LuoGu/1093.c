#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chinese;
    int math;
    int english;
    int sum;
    int id;
} Student ;
Student a[305];

int Cmp(const void *x,const void *y) {
    Student *p = (Student *)x;
    Student *q = (Student *)y;
    if (p->sum != q->sum) {
        return q->sum - p->sum;
    }
    if (p->chinese != q->chinese) {
        return q->chinese - p->chinese;
    }
    return p->id - q->id;
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d",&a[i].chinese,&a[i].math,&a[i].english);
        a[i].sum = a[i].chinese + a[i].math + a[i].english;
        a[i].id = i;
    }

    qsort(a + 1,n,sizeof (Student),Cmp);

    for (int i = 1; i <= 5; ++i) {
        printf("%d %d\n",a[i].id,a[i].sum);
    }

    return 0;
}