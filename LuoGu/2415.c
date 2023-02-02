#include <stdio.h>
#include <math.h>

int main ()
{
    int s[35] = {0};
    int cnt = 0;
    while (scanf("%d",&s[cnt++]) != EOF);
    int sum[20] = {0};
    int len = 1;
    for (int i = 0; i < cnt - 1; ++i) {
        long long temp = pow(2,cnt - 2) * s[i];
        int Temp[20] = {0};
        for (int j = 0; temp > 0; ++j) {
            Temp[j] = temp % 10;
            sum[j] += Temp[j];
            if (sum[j] >= 10) {
                sum[j] %= 10;
                sum[j + 1] ++;
                if (sum[j + 1] == 1) {
                    len++;
                }
            }
            temp /= 10;
        }
    }

    int position = 0;
    for (int i = 19; i >= 0; i--) {
        if (sum[i] != 0) {
            position = i;
            break;
        }
    }

    for (int i = position; i >= 0;i--) {
        printf("%d",sum[i]);
    }

    return 0;
}