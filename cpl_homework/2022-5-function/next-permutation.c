#include<stdio.h>

int main()
{
    int n = 0;
    int p[10000] = {0};
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&p[i]);
    }

    int cnt = 0;
    int t = 0;
    for (int j = n; j > 0 ; j--) {
        if (p[j] > p[j - 1]) {
            t = j - 1;
            break;
        }
        cnt++;
    }

    int temp = 0;
    for (int j = n; j > 0 ; j--) {
        if (p[j] > p[t]) {
            temp = p[t];
            p[t] = p[j];
            p[j] = temp;
            break;
        }
    }

    for (int i = 1; i < n - cnt; ++i) {
        printf("%d ",p[i]);
    }
    for (int i = n; i >= n - cnt; i--) {
        printf("%d ",p[i]);
    }

    return 0;
}