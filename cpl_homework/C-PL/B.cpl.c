#include <stdio.h>

char a[10000005] = {0};

int main ()
{
    long long sum = 0;
    char ch = 0;
    int len = 0;
    for (int i = 0;; ++i) {
        scanf("%c",&ch);
        a[i] = ch;
        len++;
        if (ch == '\n') {
            break;
        }
    }
    for (int i = 0; i < len - 1; ++i) {
        sum += a[i] - '0';
    }

    printf("%lld",sum % 9);
    return 0;
}