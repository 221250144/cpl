#include <stdio.h>

int n, k, len = 0;
int l[100005] = {0};

int f(int x) {
    int num = 0;
    for (int i = 0; i < n; ++i) {
        num += l[i] / x;
    }
    return num;
}

int main() {


    scanf("%d%d", &n, &k);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &l[i]);
        sum += l[i];
    }
    if (sum < k) {
        printf("0");
        return 0;
    }

    int mid;
    int left = 1;
    int right = 100000001;
    while (left + 1 < right) {
        mid = (left + right) / 2;
        if (f(mid) >= k) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%d",left);

    return 0;
}