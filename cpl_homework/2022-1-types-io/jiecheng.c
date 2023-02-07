#include<stdio.h>
// i! = (i - 1)! * i
// (x + y) % P = (x % P + y % P) % P
// x * y % P = (x % P) * (x % P) % P
int main()
{
    const int P = 1e9 + 7;
    int n;
    scanf("%d",&n);
    int i=1;
    int sum = 0, fac = 1;
    do{
//        int d=1;
//        int t=1;
//        do{
//            d*=t;
//            t++;
//        }while(t<=i);
        fac = 1LL * fac * i % P;
        sum = (sum + fac) % P;
        i++;
    }while(i<=n);
    printf("%d", sum);

    return 0;
}
