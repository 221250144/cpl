#include<stdio.h>

int main()
{
    int n = 0;

    scanf("%d",&n);

    int sum = 0;
    int d = 1;
    for (int i = 1;i <= n;i++){
        d = d * i % 10007;
        sum = (sum + d) % 10007;
    }
    printf("%d",sum);

    return 0;
}