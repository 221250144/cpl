#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool judge(const int a[],const int b[],int lens) ;

int main()
{
    char a[10090] = {0};
    char b[10090] = {0};
    scanf("%s%s",a,b);
    int len_a = strlen(a);
    int len_b = strlen(b);

    int max = len_a > len_b ? len_a :len_b;
    int A[50005] = {0};
    int B[50005] = {0};
    for (int i = max - len_a,j = 0; j < len_a; i++,j++) {
        A[i] = a[j] - '0';
    }
    for (int i = max - len_b,j = 0; j < len_b; i++,j++) {
        B[i] = b[j] - '0';
    }

    int sub[10090] = {0};
    for (int i = 0; i < max; ++i) {
        sub[i] = A[i] - B[i];
    }

    bool temp = judge(A,B,max);
    if (temp == true) {
        for (int i = max - 1; i > 0; i--) {
            if (sub[i] < 0) {
                sub[i] += 10;
                sub[i - 1]--;
            }
        }
    } else {
        for (int i = max - 1; i > 0; i--) {
            if (sub[i] > 0) {
                sub[i] -= 10;
                sub[i - 1]++;
            }
        }
    }

    int i = 0;
    for (; sub[i] == 0 && i != max - 1; ++i) ;
    if (temp == true) {
        while (i < max) {
            printf("%d", sub[i]);
            i++;
        }
    } else {
        printf("-");
        while (i < max) {
            printf("%d", -sub[i]);
            i++;
        }
    }

    return 0;
}

bool judge(const int a[],const int b[],int lens) {
    for (int i = 0; i < lens; ++i) {
        if (a[i] > b[i]) return true;
        if (a[i] < b[i]) return false;
    }
    return true;
}
