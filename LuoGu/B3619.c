#include <stdio.h>

int main () {
    int n = 0;
    int x = 0;
    scanf("%d%d",&n,&x);
    char ans[1005] = {0};
    int cnt = 0;
    int d = 0;
    while (n) {
        d = n % x;
        if (d >= 10) {
            ans[cnt++] = 65 + d - 10;
        } else {
            ans[cnt++] = d + 48;
        }
        n /= x;
    }
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%c",ans[i]);
    }

    return 0;
}