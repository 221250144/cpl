#include <stdio.h>
#include <string.h>

int main()
{
    char a[505] = {0};
    char b[505] = {0};

    scanf("%s%s",a,b);
    int cntA = strlen(a);
    int cntB = strlen(b);
    int A[505] = {0};
    int B[505] = {0};
    for (int i = 0; i < cntA; ++i) {
        A[i] = a[cntA - i - 1] - '0';
    }
    for (int i = 0; i < cntB; ++i) {
        B[i] = b[cntB - i - 1] - '0';
    }
    int max = cntA > cntB ? cntA : cntB;
    int sum[505] = {0};
    for (int i = 0; i <= max; ++i) {
        sum[i] += ( A[i] + B[i] );
        if (sum[i] > 9) {
            sum[i + 1]++;
            sum[i] %= 10;
        }
    }
    for (int i = 504;  ; i--) {
        if (sum[i] != 0) {
            max = i;
            break;
        }
        if (i == 0) {
            max = 0;
            break;
        }
    }
    for (int i = max; i >= 0; i--) {
        printf("%d",sum[i]);
    }

    return 0;
}