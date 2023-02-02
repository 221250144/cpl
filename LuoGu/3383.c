#include <stdio.h>
#include <stdbool.h>

bool judge[100000005] = {false};
int prime[100000005] = {0};
int cnt = 0;

int main()
{
    int n = 0;
    scanf("%d",&n);
    for (int i = 2; i <= n; ++i) {
        if (judge[i] == false) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && prime[j] * i <= n; ++j) {
            judge[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    int q = 0;
    scanf("%d",&q);
    for (int i = 0; i < q; ++i) {
        int k = 0;
        scanf("%d",&k);
        printf("%d\n",prime[k - 1]);
    }

    return 0;
}