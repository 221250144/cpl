#include <stdio.h>
#include <math.h>

int main () {
    int n = 0;
    scanf("%d",&n);
    int h[305] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&h[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (h[j] < h[j + 1]) {
                int tmp = h[j];
                h[j] = h[j + 1];
                h[j + 1] = tmp;
            }
        }
    }
    int l = 0;
    int r = n - 1;
    long long ans = h[0] * h[0];
    while (l < r) {
        ans += pow(h[l] - h[r],2);
        l++;
        if (l >= r) {
            break;
        }
        ans += pow(h[l] - h[r],2);
        r--;
    }
    printf("%lld",ans);

    return 0;
}