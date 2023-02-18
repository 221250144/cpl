#include <stdio.h>
#include <stdlib.h>

int Cmp (const void *a,const void *b) {
    return *(int*)a - *(int*)b;
}

typedef struct {
    int val;
    long long num;
} T;
T a[200005] = {0};

int search(int key,int l,int r) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid].val == key) {
            return mid;
        }
        if (a[mid].val > key) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main () {
    int n = 0;
    int c = 0;
    scanf("%d%d",&n,&c);
    int b[200005] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&b[i]);
    }
    qsort(b,n,sizeof (int),Cmp);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        a[cnt].val = b[i];
        a[cnt].num++;
        while (b[i] == b[i + 1]) {
            a[cnt].num++;
            i++;
        }
        cnt++;
    }
    long long ans = 0;
    for (int i = 0; i < cnt; ++i) {
        int t = search(a[i].val + c,i,cnt - 1);
        if (t != -1) {
            ans += a[i].num * a[t].num;
        }
    }
    printf("%lld",ans);

    return 0;
}