#include <stdio.h>

typedef struct {
    int w;
    int b;
    int r;
} F;
F a[55];

int main() {
    int n = 0;
    int m = 0;
    scanf("%d%d", &n, &m);
    char map[55][55] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == 'W') {
                a[i].w++;
            } else if (map[i][j] == 'B') {
                a[i].b++;
            } else {
                a[i].r++;
            }
        }
    }

    int min = 2500;
    int j = 1;
    int k = 2;
    while (1) {
        int ans = 0;
        for (int l = 0; l < j; ++l) {
            ans += (a[l].b + a[l].r);
        }
        for (int l = j; l < k; ++l) {
            ans += (a[l].r + a[l].w);
        }
        for (int l = k; l < n; ++l) {
            ans += (a[l].w + a[l].b);
        }

        if (ans < min) {
            min = ans;
        }

        if (j == n - 2 && k == n - 1) {
            break;
        } else if (k == n - 1) {
            j++;
            k = j + 1;
        } else {
            k++;
        }
    }
    printf("%d", min);

    return 0;
}