#include <stdio.h>

#define N 19971107

int main()
{
    long long n,k;
    scanf("%lld%lld",&n,&k);
    if (n == 0) {
        printf("0");
        return 0;
    }
    long long ans = 1;
    long long a = k - 1;
    long long b = n - 1;
    while (b > 0) {
        if (b % 2 == 1) {
            ans = ans * a % N;
        }
        b /= 2;
        a = a * a % N;
    }
    ans = ans * k % N;

    printf("%lld",ans);

    return 0;
}