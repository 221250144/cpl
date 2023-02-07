#include <stdio.h>

#define MAX 100005

int main () {
    int n = 0;
    int x = 0;
    int a[MAX] = {0};
    scanf("%d%d%d",&n,&x,&a[0]);
    long long ans = 0;
    for (int i = 01; i < n; ++i) {
        scanf("%d",&a[i]);
        int tmp = a[i - 1] + a[i] - x;
        if (tmp > 0) {
            a[i] -= tmp;
            ans += tmp;
        }
    }
    printf("%lld",ans);

    return 0;
}