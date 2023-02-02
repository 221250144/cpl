#include <stdio.h>
#include <math.h>

int main()
{
    long long n = 0;
    scanf("%lld",&n);
    long long n1 = 0;
    long long n2 = 0;
    for (int i = 2;i <= sqrt(n); ++i) {
        if (n % i == 0) {
            n1 = i;
            n2 = n / i;
        }
    }
    printf("%lld",n1 > n2 ? n1 : n2);

    return 0;
}