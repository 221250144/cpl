#include<stdio.h>
#include<string.h>

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    char go[1005] = {0};

    scanf("%s",go);
    int x1 = 0,x2 = a,y1 = 0,y2 = b;
    int temp = 0;
    for (int i = 0; i < strlen(go); ++i) {
        if (go[i] == 'W') {
            if (x2 > x1) {
                x2 = x2 - a - c;
            } else {
                x1 = x1 - a - c;
            }
            temp = a;
            a = c;
            c = temp;
        }
        if (go[i] == 'S') {
            if (x2 < x1) {
                x2 = x2 + a + c;
            } else {
                x1 = x1 + a + c;
            }
            temp = a;
            a = c;
            c = temp;
        }
        if (go[i] == 'D') {
            if (y2 < y1) {
                y2 = y2 + b + c;
            } else {
                y1 = y1 + b + c;
            }
            temp = b;
            b = c;
            c = temp;
        }
        if (go[i] == 'A') {
            if (y2 > y1) {
                y2 = y2 - b - c;
            } else {
                y1 = y1 - b - c;
            }
            temp = b;
            b = c;
            c = temp;
        }
    }

    if (x1 < x2) {
        printf("%d %d ",x1,x2);
    } else {
        printf("%d %d ",x2,x1);
    }
    if (y1 < y2) {
        printf("%d %d",y1,y2);
    } else {
        printf("%d %d",y2,y1);
    }
    return 0;
}