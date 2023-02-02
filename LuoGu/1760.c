#include <stdio.h>

int ans[1000005] = {1};
int cnt = 1;

int main()
{
    int n = 0;
    scanf("%d",&n);
    if (n == 0) {
        printf("0");
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < cnt; ++j) {
            ans[j] *= 2;
        }
        for (int j = 0; j < cnt; ++j) {
            if (ans[j] > 9) {
                ans[j + 1] += ans[j] / 10;
                ans[j] %= 10;
            }
            if (ans[cnt] != 0) cnt++;
        }
        ans[0]++;
    }
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%d",ans[i]);
    }

    return 0;
}