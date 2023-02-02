//高精度A * B
#include <stdio.h>

int main()
{
    char a[2005] = {0};
    char b[2005] = {0};

    scanf("%s%s",a,b);
    int cntA = 0;
    int cntB = 0;
    for (int i = 2004;  ; i--) {
        if (a[i] != 0) {
            cntA = i;
            break;
        }
        if (i == 0) {
            cntA = 0;
            break;
        }
    }
    for (int i = 2004; ; i--) {
        if (b[i] != 0) {
            cntB = i;
            break;
        }
        if (i == 0) {
            cntB = 0;
            break;
        }
    }
    int A[2005] = {0};
    int B[2005] = {0};
    for (int i = 0; i <= cntA; ++i) {
        A[i] = a[cntA - i] - '0';
    }
    for (int i = 0; i <= cntB; ++i) {
        B[i] = b[cntB - i] - '0';
    }

    int product[5000] = {0};
    for (int i = 0; i <= cntA; ++i) {
        for (int j = 0; j <= cntB; ++j) {
            product[i + j] += ( A[i] * B[j] );
            while (product[i + j] > 9) {
                product[i + j + 1] += ( product[i + j] / 10 );
                product[i + j] %= 10;
            }
        }
    }

    int position = 0;
    for (int i = 4999; ; i--) {
        if (product[i] != 0) {
            position = i;
            break;
        }
        if (i == 0) {
            position = 0;
            break;
        }
    }

    for (int i = position; i >= 0; i--) {
        printf("%d",product[i]);
    }

    return 0;
}