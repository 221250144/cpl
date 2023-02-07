#include<stdio.h>
#include<math.h>

int main()
{
    int n = 0;
    double x = 0.0;

    scanf("%lf%d",&x,&n);

    double y = 0;
    double d = 0;
    for (int i = 0;i <= n;i++){
        d = 4.0 * (pow ((-1),i) * pow (x,(2 * i + 1)))/(2 * i + 1);
        y += d;
    }
    printf("%.10f",y);

    return 0;
}