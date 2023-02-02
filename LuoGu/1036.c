#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    bool state;
    int val;
} mmm ;
mmm a[25];

bool is_prime(long long number) {
    if (number == 1 || number == 0) {
        return false;
    }
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 0;
    int k = 0;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i].val);
    }

    for (int i = 0; i < k; ++i) {
        a[i].state = true;
    }

    int num = 0;
    long long sum1 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].state) {
            sum1 += a[i].val;
        }
    }
    if (is_prime(sum1)) {
        num++;
    }

    while (1) {
        for (int i = 0; i < n - 1; ++i) {
            if (a[i].state == true && a[i + 1].state == false) {
                a[i].state = false;
                a[i + 1].state = true;
                int cnt = 0;
                for (int j = 0; j < i; ++j) {
                    if (a[j].state == true) {
                        cnt++;
                        a[j].state = false;
                    }
                }
                for (int j = 0; j < cnt; ++j) {
                    a[j].state = true;
                }
                break;
            }
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i].state) {
                sum += a[i].val;
            }
        }
        if (is_prime(sum)) {
            num++;
        }

        int judge = 1;
        for (int i = n - 1; i >= n - k; i--) {
            if (a[i].state == false) {
                judge = 0;
                break;
            }
        }
        if (judge == 1) break;
    }
    printf("%d",num);

    return 0;
}