#include <stdio.h>

void Combine(int n, int k, int step);

int a[25] = {0};
int used[25] = {0};

int main()
{
    int n = 0;
    int k = 0;
    scanf("%d%d", &n, &k);

    Combine(n, k, 1);

    return 0;
}

void Combine(int n, int k, int step) {
    if (step > k) {
        for (int i = 1; i <= k; ++i) {
            printf("%3d", a[i]);
        }
        printf("\n");
        return;
    }
    for (int i = a[step - 1] + 1; i <= n; ++i) {
        if (used[i] == 0) {
            used[i] = 1;
            a[step] = i;
            Combine(n, k, step + 1);
            used[i] = 0;
        }
    }
}