#include<stdio.h>
#include<stdlib.h>

void GoX (int xa,int xb) {
    while (xa != xb) {
        if (xa > xb) {
            printf("L");
            xa--;
        } else {
            printf("R");
            xa++;
        }
    }
}
void GoY (int ya,int yb) {
    while (ya != yb) {
        if (ya > yb) {
            printf("D");
            ya--;
        } else {
            printf("U");
            ya++;
        }
    }
}
int main() {
    int xa, ya, xb, yb, xc, yc;
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
    int cnt = 0;
    int i = xa - xb;
    int j = ya - yb;
    if ((xa != xb || xa != xc) && (ya != yb || ya != yc)) {
        cnt = abs(i) + abs(j);
        printf("%d\n", cnt);
        if (xa != xc && ya != yc && xb != xc && yb != yc) {
           GoX(xa,xb);
            GoY(ya,yb);
        }
        if (yb == yc || xa == xc) {
            GoX(xa,xb);
            GoY(ya,yb);
        }
        if (ya == yc || xb == xc) {
            GoY(ya,yb);
            GoX(xa,xb);
        }
    } else if (ya == yb && ya == yc) {
        if ((xa < xc && xb < xc) || (xa > xc && xb > xc)) {
            cnt = abs(i) + abs(j);
            printf("%d\n", cnt);
            GoX(xa,xb);
        } else {
            cnt = abs(i) + abs(j) + 2;
            printf("%d\n", cnt);
            printf("U");
            GoX(xa,xb);
            printf("D");
        }
    }
        //A B C同行
    else if (xa == xb && xa == xc) {
        if ((ya < yc && yb < yc) || (ya > yc && yb > yc)) {
            cnt = abs(i) + abs(j);
            printf("%d\n", cnt);
            GoY(ya,yb);
        } else {
            cnt = abs(i) + abs(j) + 2;
            printf("%d\n", cnt);
            printf("L");
            GoY(ya,yb);
            printf("R");
        }
    }
    return 0;
}