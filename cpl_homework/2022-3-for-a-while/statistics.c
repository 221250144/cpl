#include<stdio.h>

int main() {
    int n = 0;
    char s[100000] = {0};
    scanf("%d%s", &n, s);
    /*读入*/
    int b[100000] = {0};
    for (int i = 0; i < n; i++) {
        b[s[i]]++;
    }
    int a[100000] = {0};
    for (int i = 65; i < 123; ++i) {
        a[i] = b[i];
    }

    /*计数*/
    int cnt = 0;/*列数*/
    int max = 0;/*行数*/
    for (int i = 65; i <= 122; ++i) {
        if (b[i] > max) {
            max = b[i];
        }
    }
    for (int i = 65; i < 91; ++i) {
        if (b[i] > 0 && b[i + 32] > 0) {
            cnt += 3;
        } else if (b[i] > 0 || b[i + 32] > 0) {
            cnt += 2;
        }
    }
    /*计算行数与列数*/
    int t = max;
    for (int i = 0; i < t; ++i) {
        while (max > 0) {
            for (int j = 65; j < 91; ++j) {
                if (b[j + 32] == max && b[j] == max) {
                    printf("== ");
                    b[j + 32]--;
                    b[j]--;
                } else if (b[j + 32] == max && b[j] != max && b[j] > 0) {
                    printf("=  ");
                    b[j + 32]--;
                } else if (b[j + 32] != max && b[j] == max && b[j + 32] > 0) {
                    printf(" = ");
                    b[j]--;
                } else if (b[j + 32] != max && b[j] != max && b[j + 32] > 0 && b[j] > 0) {
                    printf("   ");
                } else if (b[j + 32] == max && b[j] == 0) {
                    printf("= ");
                    b[j + 32]--;
                } else if (b[j] == max && b[j + 32] == 0) {
                    printf("= ");
                    b[j]--;
                } else if (b[j + 32] != max && b[j] == 0 && b[j + 32] > 0) {
                    printf("  ");
                } else if (b[j] != max && b[j + 32] == 0 && b[j] > 0) {
                    printf("  ");
                }
            }
            max--;
            printf("\n");
        }
    }
    /*输出=和空格*/
    for (int i = 1; i < cnt;) {
        printf("-");
        cnt--;
        if (cnt == 1) {
            printf("\n");
        }
    }
    /*输出横线*/
    for (int j = 65; j < 91; ++j) {
        if (a[j + 32] != 0 && a[j] != 0) {
            printf("%c%c ", j + 32, j);
        } else if (a[j + 32] != 0 && a[j] == 0) {
            printf("%c ", j + 32);
        } else if (a[j] != 0 && a[j + 32] == 0) {
            printf("%c ", j);
        }
    }

    return 0;
}