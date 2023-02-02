#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    int z;
} Student ;
Student a[50005];

int Cmp(const void *x,const void *y) {
    Student *p = (Student*)x;
    Student *q = (Student*)y;
    return p->z - q->z;
}

double Distance(Student *aa, Student *bb) {
    return sqrt(pow((aa->x - bb->x),2) + pow((aa->y - bb->y),2) + pow((aa->z - bb->z),2));
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    }

    qsort(a, n, sizeof (Student), Cmp);

    double sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum += Distance(&a[i],&a[i + 1]);
    }

    printf("%.3f",sum);

    return 0;
}