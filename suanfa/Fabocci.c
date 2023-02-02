#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d",&n);

    long long int a[100000] = {0};
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; ++i) {
        a[i] = a[i - 1] + a[i - 2];
    }

    for (int i = 0; i < n; ++i) {
        printf("%10lld",a[i]);
        if((i + 1) % 4 == 0){
            printf("\n");
        }
    }


    return 0;
}
