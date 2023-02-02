#include <stdio.h>

int main()
{
    char map[15][15] = {0};
    char ch;
    int xc = 0; // 牛的位置
    int yc = 0;
    int xf = 0; // 人的位置
    int yf = 0;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            scanf("%c",&map[i][j]);
            if (map[i][j] == 'C') {
                xc = i;
                yc = j;
            }
            if (map[i][j] == 'F') {
                xf = i;
                yf = j;
            }
        }
        scanf("%c",&ch);
    }
    for (int i = 0; i <= 11; ++i) { // 在周围加一圈 ‘*’
        map[i][0] = '*';
        map[0][i] = '*';
        map[i][11] = '*';
        map[11][i] = '*';
    }

    int pass[100005]; // 保存每一步的状态（牛的位置、人的位置、牛的方向、人的方向）
    int cnt = 0; // 走了多少步

    int dc = 0; // 牛的方向   0:向上 1:向右 2:向下 3:向左
    int df = 0; // 人的方向
    while (1) {
        for (int i = 0; i <= cnt; ++i) { // 寻找是否存在相同的状态 （存在 ： 死循环 -> 抓不到
            if (xc + yc * 10 + xf * 100 + yf * 1000 + dc * 10000 + df * 100000 == pass[i]) {
                printf("0");
                return 0;
            }
        }
        pass[cnt++] = xc + yc * 10 + xf * 100 + yf * 1000 + dc * 10000 + df * 100000;
        switch (dc) { // 牛走
            case 0: if (map[xc - 1][yc] == '*') { // 碰到障碍
                dc++; // 转向
            } else {
                xc--;
            }
                break;
            case 1: if (map[xc][yc + 1] == '*') {
                dc++;
            } else {
                yc++;
            }
                break;
            case 2: if (map[xc + 1][yc] == '*') {
                dc++;
            } else {
                xc++;
            }
                break;
            case 3: if (map[xc][yc - 1] == '*') {
                dc = 0;
            } else {
                yc--;
            }
                break;
        }

        switch (df) { // 人走
            case 0: if (map[xf - 1][yf] == '*') {
                    df++;
                } else {
                    xf--;
                }
                break;
            case 1: if (map[xf][yf + 1] == '*') {
                    df++;
                } else {
                    yf++;
                }
                break;
            case 2: if (map[xf + 1][yf] == '*') {
                    df++;
                } else {
                    xf++;
                }
                break;
            case 3: if (map[xf][yf - 1] == '*') {
                    df = 0;
                } else {
                    yf--;
                }
                break;
        }

        if (xc == xf && yc == yf) { // 是否相遇
            printf("%d",cnt);
            return 0;
        }
    }
}