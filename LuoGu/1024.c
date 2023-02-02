#include <stdio.h>
#include <math.h>

double a,b,c,d;

double f(double x) {
    return a * pow(x,3) + b * pow(x,2) + c * x + d;
}

int main () {
    int cnt = 0;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);

    for (int i = -100; i < 100; ++i) {
        if (f(i + 1) == 0) {
            printf("%.2f ",(double)(i + 1));
            cnt++;
        } else if (f(i) * f(i + 1) < 0) {
            double l = i;
            double r = i + 1;
            while(fabs(l - r) > 0.001) {
                double mid = (l + r) / 2;
                if (f(mid) == 0) {
                    printf("%.2f ",mid);
                    break;
                } else if (f(l) * f(mid) < 0) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            printf("%.2f ",l);
            cnt++;
        }

        if (cnt == 3) {
            break;
        }
    }


    return 0;
}