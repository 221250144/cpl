#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[25];
    int y;
    int m;
    int d;
    int id;
} Student ;
Student a[105];

int Cmp(const void *x,const void *y) {
    Student *p = (Student*)x;
    Student *q = (Student*)y;
    if (p->y != q->y) return p->y - q->y;
    if (p->m != q->m) return p->m - q->m;
    if (p->d != q->d) return p->d - q->d;
    return q->id - p->id;
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d%d",a[i].name,&a[i].y,&a[i].m,&a[i].d);
        a[i].id = i + 1;
    }

    qsort(a, n, sizeof (Student), Cmp);

    for (int i = 0; i < n; ++i) {
        printf("%s\n",a[i].name);
    }

    return 0;
}