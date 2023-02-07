#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool IsPrime(int number) ;

int main()
{
    int n = 0;
    scanf("%d",&n);

    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (IsPrime(i)) {
            int end = 0;
            int temp = i;
            while(temp > 0) {
                end = end * 10 + temp % 10;
                temp /= 10;
            }
            if (IsPrime(end)) {
                cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}

bool IsPrime(int number) {
        int flag = 1;
        for (int i = 2; i <= sqrt(number + 0.5); i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
}