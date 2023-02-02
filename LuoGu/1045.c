#include <stdio.h>
#include <math.h>

#define N pow(2,20)
#define M 10000000000

long long sum[1000005] = {0};

int main ()
{
    int p = 0;
    scanf("%d",&p);
    int cnt = 1;
    sum[0] = pow(2,p % 20);
    for (int j = 0; j < 50; ++j) {
        if (sum[j] > M - 1) {
            sum[j + 1] += sum[j] / M;
            sum[j] %= M;
        }
        if (sum[cnt] != 0) {
            cnt++;
        }
    }
    for (int i = p % 20; i < p; i += 20) {
        for (int j = 0; j < 50; ++j) {
            sum[j] *= N;
        }
        for (int j = 0; j < 50; ++j) {
            if (sum[j] > M - 1) {
                sum[j + 1] += sum[j] / M;
                sum[j] %= M;
            }
            if (sum[cnt] != 0) {
                cnt++;
            }
        }
    }
    sum[0]--;

    int count = log10(2) * p + 1;
    printf("%d\n",count);

    for (int i = 49; i >= 0; i--) {
        printf("%.10lld",sum[i]);
        if (i % 5 == 0) {
            printf("\n");
        }
    }

    return 0;
}