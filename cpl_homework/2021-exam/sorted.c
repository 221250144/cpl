#include <stdio.h>

int main()
{
    int T = 0;
    scanf("%d",&T);
    int n[15] = {0};
    int m[15] = {0};
    int strn[15][1005] = {0};
    int strm[15][1005] = {0};
    for (int i = 0; i < T; ++i) {
        scanf("%d%d",&n[i],&m[i]);
        for (int j = 1; j <= n[i]; ++j) {
            scanf("%d",&strn[i][j]);
        }
        for (int j = 1; j <= m[i]; ++j) {
            scanf("%d",&strm[i][j]);
            int temp = strn[i][strm[i][j]];
            for (int p = strm[i][j]; p > 0;p--) {
                strn[i][p] = strn[i][p - 1];
            }
            strn[i][1] = temp;
        }

        int judge = 0;
        for (int q = 1; q < n[i]; ++q) {
            if (strn[i][q] < strn[i][q + 1]) {
                judge = 1;
                break;
            }
        }

        if (judge == 0) {
            printf("mayi is a good teacher\n");
        } else {
            printf("I love C programming language\n");
        }
    }

    return 0;
}