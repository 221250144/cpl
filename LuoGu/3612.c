#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {
    char s[65] = {0};
    long long n = 0;
    scanf("%s%lld",s,&n);
    size_t l = strlen(s);
    for (int i = 0; i < l; ++i) {
        s[2 * l - i - 1] = s[i];
    }
    long long t = n % (2 * l);

    return 0;
}