#include<stdio.h>

int main()
{
    int s = 0;
    int v = 0;
    int t = 0;
    scanf("%d%d",&s,&v);
    if (s % v == 0) {
        t = s / v + 10;
    } else {
        t = s / v + 11;
    }
    int time = 8 * 60 - t;
    if (time < 0) {
        time += 24 * 60;
    }
    int hour = time / 60;
    int minute = time % 60;

    printf("%.2d:%.2d",hour,minute);

    return 0;
}