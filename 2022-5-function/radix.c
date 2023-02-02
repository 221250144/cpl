#include <stdio.h>

int Change(int number, int x[], int m);

int main() {
    int p = 0,q = 0,r = 0;
    scanf("%d%d%d", &p, &q, &r);

    int a[2] = {0},b[2] = {0},c[2] = {0};
    for (int B = 2; B <= 41; B++) {

        int pro = Change(r,c,B);
        int num1 = Change(p,a,B);
        int num2 = Change(q,b,B);

        if ((num1 * num2) == pro && a[0] < B && a[1] < B && b[0] < B && b[1] < B && c[0] < B && c[1] < B) {
            printf("%d", B);
            break;
        }
        if (B == 41) {
            printf("0");
        }
    }

    return 0;
}
int Change(int number, int x[], int m) {
    x[0] = number / 10;
    x[1] = number % 10;

    return x[0] * m + x[1];
}