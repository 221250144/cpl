#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d",&n);
    int a[255] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) {
            a[i] *= 2;
            a[i + 1] = 0;
        }
        for (int j = i + 1; j < n; ++j) {
            a[j] = a[i];
        }
        n--;
    }

    return 0;
}