#include<stdio.h>

int main()
{
    double A,B,C;
    scanf("%lf%lf%lf",&A,&B,&C);
    double n = A * 0.2 + B * 0.3 + C * 0.5;
    printf("%.0f",n);

    return 0;
}