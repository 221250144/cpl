#include<stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    int a,b,c,d,e;
    a=x/50;
    x=x-50*a;
    b=x/20;
    x=x-20*b;
    c=x/10;
    x=x-10*c;
    d=x/5;
    x=x-5*d;
    e=x/1;
    printf("%d\n%d\n%d\n%d\n%d\n",a,b,c,d,e);

    return 0;
}
