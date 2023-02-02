#include <stdio.h>

int main()
{
    int m = 0;
    int n = 0;
    scanf("%d%d",&m,&n);
    char map[105][105] = {0};
    char x = 0;
    for (int i = 1; i <= m; ++i) {
        scanf("%c",&x);
        for (int j = 1; j <= n; ++j) {
            scanf("%c",&map[i][j]);
        }
    }
    int b[105][105] = {0};
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cnt = 0;
            if (map[i][j] == '?') {
                for (int p = i - 1; p <= i + 1; ++p) {
                    for (int q = j - 1; q <= j + 1; ++q) {
                        if (map[p][q] == '*') {
                            cnt++;
                        }
                    }
                }
                b[i][j] = cnt;
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] != '*') {
                printf("%d",b[i][j]);
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}