#include<stdio.h>

int main()
{
    double G=6.674e-11;
    double M=77.15;
    double m,R;
    double x;
    scanf("%lf %lf",&m,&R);
    x=(G*M*m)/(R*R);
    printf("%.3e",x);

    return 0;
}
