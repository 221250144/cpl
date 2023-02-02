#include <stdio.h>
#include <string.h>
#include <math.h>

int main () {
    int x = 0;
    char s[1005] = {0};
    scanf("%d%s",&x,s);

    int ans = 0;
    int tem = 0;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        tem = s[i] > 57 ? s[i] - 'A' + 10 : s[i] - '0';
        ans += pow(x,len - i - 1) * tem;
    }
    printf("%d",ans);

    return 0;
}