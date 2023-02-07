#include <stdio.h>
#include <string.h>

#define MAX 255

int main () {
    int k = 0;
    char a[MAX] = {0};
    int b[MAX] = {0};
    scanf("%s%d",a,&k);
    int len = strlen(a);
    for (int i = 0; i < len; ++i) {
        b[i] = a[i] - '0';
    }
    while (k--) {
        for (int i = 0; i < len; ++i) {
            if (b[i] > b[i + 1]) {
                for (int j = i; j < len; ++j) {
                    b[j] = b[j + 1];
                }
                len--;
                break;
            }
        }
    }
    int print = 0;
    for (int l = 0; l < len; ++l) {
        if (b[l] != 0 || print == 1) {
            print = 1;
            printf("%d",b[l]);
        }
    }
    if (print == 0) {
        printf("0");
    }

    return 0;
}