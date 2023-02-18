#include <stdio.h>

int main()
{
    int T = 0;
    scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        int n = 0;
        int m = 0;
        int strn[1005] = {0};
        int strm[1005] = {0};
        scanf("%d%d",&n,&m);
        for (int j = 1; j <= n; ++j) {
            scanf("%d",&strn[j]);
        }

        for (int j = 1; j <= m; ++j) {
            scanf("%d",&strm[j]);
            int temp = strn[strm[j]];
            for (int p = strm[j]; p > 0;p--) {
                strn[p] = strn[p - 1];
            }
            strn[1] = temp;
        }

        int judge = 0;
        for (int q = 1; q < n; ++q) {
            if (strn[q] > strn[q + 1]) {
                judge = 1;
                break;
            }
        }

        if (judge == 1) {
            printf("mayi is a good teacher\n");
        } else {
            printf("I love C programming language\n");
        }
    }

    return 0;
}