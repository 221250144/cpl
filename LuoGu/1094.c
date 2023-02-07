#include <stdio.h>
#include <stdlib.h>

int Cmp (const void *a,const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int m = 0;
    int n = 0;
    scanf("%d%d",&m,&n);
    int a[30005] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof (int),Cmp);
    int ans = 0;
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        if (l == r) {
            ans++;
            break;
        }
        if (a[l] + a[r] <= m) {
            l++;
            r--;
            ans++;
        } else {
            r--;
            ans++;
        }
    }
    printf("%d",ans);

    return 0;
}