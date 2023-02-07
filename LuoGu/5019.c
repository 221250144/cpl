#include <stdio.h>

int main () {
    int n = 0;
    int a[100005] = {0};
    scanf("%d%d",&n,&a[0]);
    int ans = a[0];
    for (int i = 1; i < n; ++i) {
        scanf("%d",&a[i]);
        if (a[i] > a[i - 1]) {
            ans += (a[i] - a[i - 1]);
        }
    }
    printf("%d",ans);

    return 0;
}