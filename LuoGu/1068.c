#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int score;
} Student ;
Student a[5005];


int Cmp(const void *x,const void *y) {
    Student *p = (Student*)x;
    Student *q = (Student*)y;
    if (p->score != q->score) {
        return q->score - p->score;
    }
    return p->id - q->id;
}


int main()
{
    int n = 0;
    int m = 0;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&a[i].id,&a[i].score);
    }
    m = m * 15 / 10;

    qsort(a, n, sizeof (Student), Cmp);

    while (a[m - 1].score == a[m].score) {
        m++;
    }

    printf("%d %d\n",a[m - 1].score,m);

    for (int i = 0; i < m; ++i) {
        printf("%d %d\n",a[i].id,a[i].score);
    }

    return 0;
}