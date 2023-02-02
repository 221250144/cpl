#include <stdio.h>

long long w[25][25][25] = {0};

void init() {
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 25; ++j) {
            for (int k = 0; k < 25; ++k) {
                w[i][j][k] = -1;
            }
        }
    }
}

long long W(long long a, long long b, long long c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return W(20, 20, 20);
    }
    if (w[a][b][c] != -1) {
        return w[a][b][c];
    }
    if (a < b && b < c) {
        return w[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
    }
    return w[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
}

int main() {
    init();
    while (1) {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,W(a,b,c));
    }

    return 0;
}