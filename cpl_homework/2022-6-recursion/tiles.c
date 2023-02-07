#include<stdio.h>

int F(int n)
{
    if (n == 2) {
        return 2;
    }
    if (n == 1) {
        return 1;
    }
    return F(n - 1) + F(n - 2);
}
int main()
{
    int n = 0;
    scanf("%d",&n);

    printf("%d",F(n));

    return 0;
}