#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int plus[100005] = {0};
    int sum[100005] = {1};
    int c = 1;

    for (int k = 1; k <= n; k++) {
        for (int j = 0; j < c; j++) {
            sum[j] *= k;
        }

        for (int j = 0; j < c; ++j) {
            if (sum[j] > 9) {
                sum[j + 1] += sum[j] / 10;
                sum[j] %= 10;
            }
            if (sum[c] != 0) {
                c++;
            }
        }

        for (int i = 0; i < c; ++i) {
            plus[i] += sum[i];
            if (plus[i] > 9) {
                plus[i + 1] += plus[i] / 10;
                plus[i] %= 10;
            }
        }
    }

    for (int i = c - 1; i >= 0; i--) {
        printf("%d",plus[i]);
    }

    return 0;
}