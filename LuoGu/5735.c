#include <stdio.h>
#include <math.h>

double Dis(double x1,double y1,double x2,double y2) ;

int main()
{
    double ax = 0;
    double ay = 0;
    double bx = 0;
    double by = 0;
    double cx = 0;
    double cy = 0;
    scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy);
    double dis = Dis(ax,ay,bx,by) + Dis(bx,by,cx,cy) + Dis(ax,ay,cx,cy);
    printf("%.2f",dis);

    return 0;
}

double Dis(double x1,double y1,double x2,double y2) {
    return sqrt(pow(x2 - x1,2) + pow(y1 - y2,2));
}