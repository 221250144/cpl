#include <stdio.h>

int main() {
    int m = 0;
    scanf("%d",&m);
    long long f1 = 0;
    long long f2 = 1;
    long long f = 0;
    for (int i = 2;  ; ++i) {
        f = f1 % m + f2 % m;
        if (f % m == 1 && f2 % m == 0) {
            printf("%d",i - 1);
            break;
        }
        f1 = f2;
        f2 = f % m;
    }

    return 0;
}