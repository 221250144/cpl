#include <stdio.h>

int main()
{
    long long a = 0;
    long long b = 0;
    long long p = 0;
    scanf("%lld%lld%lld",&a,&b,&p);

    printf("%lld^%lld mod %lld=",a,b,p);
    a %= p;
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = result * a % p;
        }
        b /= 2;
        a = a * a % p;
    }

    printf("%lld",result);

    return 0;
}