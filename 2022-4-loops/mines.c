#include<stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    char a[101][101] = {0};
    char ch;
    char x = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%c",&x);
        for (int j = 1; j <= n; ++j) {
            ch = getchar();
            if (ch != '\n') {
                a[i][j] = ch;
            }
        }
    }

    int b[101][101] = {0};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cnt = 0;
            for (int p = i - 1; p <= i + 1; ++p) {
                for (int q = j - 1; q <= j + 1; ++q) {
                    if (a[p][q] == '*') {
                        cnt++;
                    }
                }
            }
            b[i][j] = cnt;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] != '*') {
                printf("%d",b[i][j]);
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}