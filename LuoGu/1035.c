#include<stdio.h>

int main()
{
    double S = 0;
    int k = 0;
    scanf("%d",&k);
    for (int i = 1;; ++i) {
        S = 1.0 / i + S;
        if (S > k) {
            printf("%d",i);
            break;
        }
    }

    return 0;

}