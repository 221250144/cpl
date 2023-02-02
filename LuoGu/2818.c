#include <stdio.h>
#include <string.h>

int main() {
    int n = 0;
    char m[1005] = {0};
    scanf("%d%s",&n,m);

    int len = strlen(m);
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        ans = (ans * 10 + m[i] - '0') % n;
    }
    printf("%d",ans == 0 ? n : ans);

    return 0;
}