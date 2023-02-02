#include <stdio.h>

int main()
{
    int r,c,k;
    scanf("%d%d%d",&r,&c,&k);
    char map[105][105] = {0};
    for (int i = 0; i < r; ++i) {
        scanf("%s",map[i]);
    }

    long long ans = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int step = 0;
            while (map[i][j + step] == '.') {
                step++;
            }
            if (step >= k) {
                ans++;
            }
            if (k != 1) {
                step = 0;
                while (map[i + step][j] == '.') {
                    step++;
                }
                if (step >= k) {
                    ans++;
                }
            }
        }
    }
    printf("%lld",ans);

    return 0;
}