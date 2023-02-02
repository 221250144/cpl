#include <stdio.h>

int main()
{
    int n = 0;
    int m = 0;
    scanf("%d%d",&n,&m);
    long long p = n * (n + 1) / 2;
    long long q = m * (m + 1) / 2;

    long long cnt1 = 0;
    while (n > 0 && m > 0) {
        cnt1 += (n--) * (m--);
    }

    long long cnt2 = p * q - cnt1;

    printf("%lld %lld",cnt1,cnt2);

    return 0;
}