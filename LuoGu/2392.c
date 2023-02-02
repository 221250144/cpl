#include <stdio.h>

int max(int a,int b) {
    return a > b ? a : b;
}

int Time(const int a[],int lens) {
    int sum = 0;
    for (int i = 1; i <= lens; ++i) {
        sum += a[i];
    }
    int d[2500] = {0};
    for (int i = 1; i <= lens; ++i) {
        for (int j = sum / 2; j >= a[i]; j--) {
            d[j] = max(d[j],d[j - a[i]] + a[i]);
        }
    }
    return sum - d[sum / 2];
}

int main()
{
    int s1,s2,s3,s4;
    scanf("%d%d%d%d",&s1,&s2,&s3,&s4);
    long long sum = 0;
    int a[25] = {0};
    for (int i = 1; i <= s1; ++i) {
        scanf("%d",&a[i]);
    }
    sum += Time(a,s1);

    int b[25] = {0};
    for (int i = 1; i <= s2; ++i) {
        scanf("%d",&b[i]);
    }
    sum += Time(b,s2);

    int c[25] = {0};
    for (int i = 1; i <= s3; ++i) {
        scanf("%d",&c[i]);
    }
    sum += Time(c,s3);

    int d[25] = {0};
    for (int i = 1; i <= s4; ++i) {
        scanf("%d",&d[i]);
    }
    sum += Time(d,s4);

    printf("%lld",sum);

    return 0;
}