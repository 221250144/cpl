#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char num[200];
} Student ;
Student a[21];

int Cmp(const void *aa,const void *bb) {
    Student *x = (Student *)aa;
    Student *y = (Student *)bb;
    size_t len1 = strlen(x->num);
    size_t len2 = strlen(y->num);
    if (len1 != len2) {
        return len2 - len1;
    }
    return strcmp(y->num,x->num);
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s",a[i].num);
        a[i].id = i + 1;
    }

    qsort(a, n, sizeof (Student), Cmp);

    printf("%d\n%s",a[0].id,a[0].num);

    return 0;
}