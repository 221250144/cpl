#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[35];
    char post[20];
    long long score;
    int level;
    int ip;
} Person;
Person a[115];

int Cmp(const void *x, const void *y);

int Cmp2(const void *x, const void *y);

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%s%lld%d", a[i].name, a[i].post, &a[i].score, &a[i].level);
        a[i].ip = i;
    }

    qsort(a + 3, 111, sizeof(a[0]), Cmp);

    for (int i = 0; i < n; ++i) {
        if (i < 1) {
            strcpy(a[i].post, "BangZhu");
        } else if (i < 3) {
            strcpy(a[i].post, "FuBangZhu");
        } else if (i < 5) {
            strcpy(a[i].post, "HuFa");
        } else if (i < 9) {
            strcpy(a[i].post, "ZhangLao");
        } else if (i < 16) {
            strcpy(a[i].post, "TangZhu");
        } else if (i < 41) {
            strcpy(a[i].post, "JingYing");
        } else {
            strcpy(a[i].post, "BangZhong");
        }
    }

    qsort(a + 3, 2, sizeof(a[0]), Cmp2);
    qsort(a + 5, 4, sizeof(a[0]), Cmp2);
    qsort(a + 9, 25, sizeof(a[0]), Cmp2);
    qsort(a + 41, 25, sizeof(a[0]), Cmp2);
    qsort(a + 66, 48, sizeof(a[0]), Cmp2);

    for (int i = 0; i < n; ++i) {
        printf("%s %s %d\n", a[i].name, a[i].post, a[i].level);
    }

    return 0;
}

int Cmp(const void *x, const void *y) {
    Person *p = (Person *) x;
    Person *q = (Person *) y;
    if (p->score == q->score) {
        return p->ip - q->ip;
    }
    return q->score - p->score;
}

int Cmp2(const void *x, const void *y) {
    Person *p = (Person *) x;
    Person *q = (Person *) y;
    if (p->level == q->level) {
        return p->ip - q->ip;
    }
    return p->level <= q->level;
}