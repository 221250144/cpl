#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d%d%d",&a,&b,&c);
    for (int i = 2; i <= a ; ++i) {
        if (a % i == 0 && b % i == 0 && c % i ==0) {
            a /= i;
            b /= i;
            c /= i;
        }
    }
    int find = 0;

    int t1,t2,t3;
    for (int i = 1; i < 1000; ++i) {
        t1 = i * a;
        t2 = i * b;
        t3 = i * c;
        if (t1 < 100 || t3 > 1000) {
            continue;
        }
        int x1 = t1;
        int x2 = t2;
        int x3 = t3;

        int num[10] = {0};
        for (int j = 0; j < 3; ++j) {
            num[t1 % 10]++;
            num[t2 % 10]++;
            num[t3 % 10]++;
            t1 /= 10;
            t2 /= 10;
            t3 /= 10;
        }
        if (num[0] != 0) {
            continue;
        }
        int judge = 1;
        for (int j = 1; j < 10; ++j) {
            if (num[j] != 1) {
                judge = 0;
                break;
            }
        }
        if (judge == 1) {
            printf("%d %d %d\n",x1,x2,x3);
            find = 1;
        }
    }
    if (find == 0) {
        printf("No!!!");
    }

    return 0;
}