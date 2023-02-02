#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N1 23333
#define N2 233333

int cnt = 0;

int a[23335][233335] = {0};

bool hash(char *str) {
    size_t lens = strlen(str);
    int ret1 = 0;
    int ret2 = 0;
    for (int i = 0; i < lens; i++) {
        ret1 = (ret1 * 31 + str[i] * (i + 1)) % N1;
        ret2 = (ret2 * 331 + str[i] * (i + 2)) % N2;
    }
    if (a[ret1][ret2] == 1) {
        return true;
    }
    a[ret1][ret2] = 1;
    return false;
}

int main()
{
    int n;
    scanf("%d",&n);
    char str[1505] = {0};
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s",str);
        if (hash(str) == false) {
            ans++;
        }
    }
    printf("%d",ans);

    return 0;
}