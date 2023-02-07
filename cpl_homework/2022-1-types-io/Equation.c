#include<stdio.h>
#include<math.h>

int main()
{
    int p,q;
    scanf("%d %d",&p,&q);
    double x;
    x=cbrt(-q*1.0/2+sqrt((q*1.0/2)*(q*1.0/2)+pow(p*1.0/3,3)))+
            cbrt(-q*1.0/2-sqrt((q*1.0/2)*(q*1.0/2)+pow(p*1.0/3,3)));
    printf("%.3f",x);
}
