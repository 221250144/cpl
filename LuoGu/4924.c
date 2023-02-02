#include <stdio.h>

int main()
{
    int old_map[505][505] = {0};
    int new_map[505][505] = {0};
    int n = 0;
    int m = 0;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; ++i) {
        old_map[i][1] = (i - 1) * n + 1;
        for (int j = 1; j <= n; ++j) {
            if (j == 1) continue;
            old_map[i][j] = old_map[i][j - 1] + 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            new_map[i][j] = old_map[i][j];
        }
    }

    int x,y,r,z;
    for (int p = 0; p < m; ++p) {

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                old_map[i][j] = new_map[i][j];
            }
        }

        scanf("%d%d%d%d", &x, &y, &r, &z);
        if (z == 1) { // 逆时针
            for (int j = x - r; j <= x + r; ++j) {
                for (int k = y - r; k <= y + r; ++k) {
                    new_map[j][k] = old_map[x + (k - y)][y - (j - x)];
                }
            }
        } else {
            for (int j = x - r; j <= x + r; ++j) {
                for (int k = y - r; k <= y + r; ++k) {
                    new_map[j][k] = old_map[x - (k - y)][y + (j - x)];
                }
            }
        }
    }

    for (int j = 1; j <=n; ++j) {
        for (int k = 1 ; k <= n; ++k) {
            printf("%d ",new_map[j][k]);
        }
        printf("\n");
    }

    return 0;
}