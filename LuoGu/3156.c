#include <stdio.h>

long long int a[2000005] = {0};
long long int b[2000005] = {0};

int main()
{
    int n = 0;
    int m = 0;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%lld",&a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%lld",&b[i]);
        printf("%lld\n",a[b[i] - 1]);
    }

    return 0;
}