#include<stdio.h>
#include<math.h>

int main()
{
    int year=0,month=0,day=0;
    scanf("%d%d%d",&year,&month,&day);
    int JDN;
    double a,y,m;
    a=floor((14-month)/12);
    y=year+4800-a;
    m= month+ 12 * a - 3;
    JDN= day + floor((153 * m + 2) / 5) + 365 * y + floor(y / 4) - floor(y / 100) + floor(y / 400) - 32045;
    printf("%d",JDN);

    return 0;
}