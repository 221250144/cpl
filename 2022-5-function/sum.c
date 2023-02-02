#include<stdio.h>

int main()
{
    int n = 0;
    int t = 0;
    scanf("%d%d",&n,&t);

    int sum = 0;
    int d = t;
    for (int i = 1; i <= n; ++i) {
        sum += d;
        d = d * 10 + t;
    }

    printf("%d",sum);

    return 0;
}