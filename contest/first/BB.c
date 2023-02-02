#include <stdio.h>

int a[2000005] = {0};

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int t1 = 0;
    int t2 = t1 + 1;
    int t3 = t2 + 1;
    int tem = 2;

    while (t3 < n) {
        int go = 1;
        if (a[t1] > a[t2]) {
            while (a[t2] >= a[t3]) {
                t2++;
                t3++;
                if (t3 >= n - 1) {
                    go = 0;
                    break;
                }
            }
        } else if (a[t1] < a[t2]) {
            while (a[t2] <= a[t3]) {
                t2++;
                t3++;
                if (t3 >= n - 1) {
                    go = 0;
                    break;
                }
            }
        } else {
            go = 0;
            t1++;
            t2++;
            t3++;
        }
        if (go == 1) {
            tem++;
            t1 = t2;
            t2 = t3;
            t3 = t2 + 1;
        }
    }

    printf("%d", tem);

    return 0;
}