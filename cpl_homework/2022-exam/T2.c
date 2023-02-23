#include <stdio.h>
#include <string.h>

int main() {
    int t = 0;
    scanf("%d", &t);

    while (t--) {
        int n = 0;
        char str[100005] = {0};
        char ans[200005] = {0};
        scanf("%d%s%s", &n, str, ans);
        int len = strlen(ans);
        int judge = 0;
        int a[100] = {0};

        for (int i = 0; i < len; ++i) {
            if (ans[i] != ans[len - i - 1]) {
                printf("Wrong Answer!\n");
                judge = 1;
                break;
            }
        }

        if (judge == 0) {
            for (int i = 0, j = 0; i < n; i++, j++) {
                int d1 = 0;
                int d2 = 0;
                if (str[i] == '?' && str[n - i - 1] == '?' && i <= n / 2) {
                    d1 = (ans[j] - '0') * 10 + (ans[j + 1] - '0');
                    d2 = (ans[j + 1] - '0') * 10 + (ans[j] - '0');
                    j++;
                    if (a[d1] == 0) {
                        a[d1] = 1;
                    } else if (a[d2] == 0) {
                        a[d2] = 1;
                    } else {
                        printf("Wrong Answer!\n");
                        judge = 1;
                        break;
                    }
                } else if (str[i] == '?' && str[n - i - 1] != '?') {
                    if (ans[j] != ans[len - j - 1]) {
                        printf("Wrong Answer!\n");
                        judge = 1;
                        break;
                    }
                } else if (str[i] != ans[j]) {
                    if (str[i] == '?' && str[n - i - 1] == '?') {
                        j++;
                    } else if (str[i] != '?') {
                        printf("Wrong Answer!\n");
                        judge = 1;
                        break;
                    }
                }
            }
        }

        if (judge == 0) {
            printf("Correct.\n");
        }
    }

    return 0;
}