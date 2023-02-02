#include <stdio.h>

int main()
{
    int t = 0;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        int n = 0;
        int a = 0;
        scanf("%d%d",&n,&a);
        int jc[100005] = {1};
        int cnt = 1;
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k < cnt; ++k) {
                jc[k] *= j;
            }
            for (int k = 0; k < cnt; ++k) {
                if (jc[k] > 9) {
                    jc[k + 1] += jc[k] / 10;
                    jc[k] %= 10;
                }
                if (jc[cnt] != 0) {
                    cnt++;
                }
            }
        }

        int count = 0;
        for (int j = 0; j < cnt; ++j) {
            if (jc[j] == a) {
                count++;
            }
        }
        printf("%d\n",count);
    }

    return 0;
}