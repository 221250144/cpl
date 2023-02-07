#include<stdio.h>
#include<math.h>

int n,p;
int a[25] = {0};
double l,r;

double F(double x)
{
    double sum = 0;
    for (int i = 0; i < n + 1; ++i) {
        sum += a[i] * pow(x,i);
    }
    return pow(sum,p);
}

double SUM(double left,double right)
{
    return ((4 * F((left + right) / 2) + F(left) + F(right)) / 6) * (right - left);
}

double SA(double left,double right,double e)
{
    double mid = (left + right) / 2;
    double S = SUM(left,right);
    double SL = SUM(left,mid);
    double SR = SUM(mid,right);

    if (fabs(SL + SR - S) <= 15 * e) {
        return SL +SR + (SL + SR - S) / 15;
    }

    return SA(left,mid,e / 2) + SA(mid,right,e / 2);
}

int main()
{
    double e = 1e-3;
    scanf("%d%d",&n,&p);
    for (int i = 0; i < n + 1; ++i) {
        scanf("%d",&a[i]);
    }
    scanf("%lf%lf",&l,&r);

    printf("%f",SA(l,r,e));

    return 0;
}