#include<stdio.h>

int n = 0;


int Max(int str[])
{
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] > str[max]) {
            max = i;
        }
    }
    return max;
}

int main()
{

    int L = 0;
    scanf("%d%d",&n,&L);
    int a[10005] = {0};
    int b[10005] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&b[i]);
    }

    int price = 0;
    while (L > 0) {
        int t = Max(a);
        if (L >= b[t]) {
            L -= b[t];
            price += a[t] * b[t];
            a[t] = 0;
            b[t] = 0;
        } else {
            price += a[t] * L;
            L = 0;
        }
    }
    printf("%d",price);

    return 0;
}