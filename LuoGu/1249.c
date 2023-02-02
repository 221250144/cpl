#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d",&n);
    int a[10005] = {0};
    int plus = 0;
    for (int i = 2; ; ++i) {
        plus += i;
        a[i] = i;
        if (plus > n) {
            if (plus - n == 1) {
                a[2] = 0;
                a[i]++;
            } else {
                a[plus - n] = 0;
            }
            break;
        }
    }
    int b[10005] = {0};
    int cnt = 0;
    for (int i = 0; i < 10005; ++i) {
        if (a[i] != 0) {
            b[cnt++] = a[i];
            printf("%d ",a[i]);
        }
    }

    printf("\n");

    int sum[10005] = {1};
    int count = 1;
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < count; ++j) {
            sum[j] *= b[i];
        }
        for (int j = 0; j < count; ++j) {
            if (sum[j] > 9) {
                sum[j + 1] += sum[j] / 10;
                sum[j] %= 10;
            }
            if (sum[count] != 0) {
                count++;
            }
        }
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%d",sum[i]);
    }


    return 0;
}