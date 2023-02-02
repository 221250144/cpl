#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a, b;
    a = n / 100;
    b = n % 100;
    int cnt = 10;
    if (a > +100) {
        do {
            int i;
            i = a % cnt;
            printf("%d", i);
            a /= cnt;
        } while (a > 0);
    } else if (a > 9) {
        do {
            int i;
            i = a % cnt;
            printf("%d", i);
            a /= cnt;
        } while (a > 0);
        printf("0");
    } else {
        printf("%d00", a);
    }
    if (b > 9) {
        do {
            int j;
            j = b % cnt;
            printf("%d", j);
            b /= cnt;
        } while (b > 0);
    } else {
        printf("%d0", b);
    }

    return 0;
}