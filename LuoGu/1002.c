#include<stdio.h>

#define MOVE 3

int main()
{
    int xb = 0,yb = 0,x = 0,y = 0;
    scanf("%d%d%d%d",&xb,&yb,&x,&y);
    xb += MOVE;
    yb += MOVE;
    x += MOVE;
    y += MOVE;
    int map[30][30] = {0};
    map[x][y] = 1;
    map[x - 1][y - 2] = 1;
    map[x - 2][y - 1] = 1;
    map[x - 2][y + 1] = 1;
    map[x - 1][y + 2] = 1;
    map[x + 1][y - 2] = 1;
    map[x + 2][y - 1] = 1;
    map[x + 2][y + 1] = 1;
    map[x + 1][y + 2] = 1;

    long long int f[35][35] = {0};
    f[MOVE][MOVE - 1] = 1;

    for (int i = MOVE; i <= xb; ++i) {
        for (int j = MOVE; j <= yb; ++j) {
            if (map[i][j] == 1) {
                continue;
            }
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }

    printf("%lld",f[xb][yb]);

    return 0;
}
