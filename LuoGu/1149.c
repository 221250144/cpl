#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d",&n);
    int a[10000] = {6,2,5,5,4,5,6,3,7,6};
    for (int i = 10; i < 10000; ++i) {
        int temp = i;
        while (temp != 0) {
            a[i] += a[temp % 10];
            temp /= 10;
        }
    }
    long long ans = 0;
    long long temp = 0;
    for (int i = 0; i < 10000; ++i) {
        for (int j = i; j < 10000; ++j) {
            if (i + j < 10000) {
                if (a[i] + a[j] + a[i + j] == n - 4) {
                    ans++;
                    if (i == j) {
                        temp++;
                    }
                }
            }
        }
    }
    printf("%lld",ans * 2 - temp);

    return 0;
}