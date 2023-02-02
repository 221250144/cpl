#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d",&n);
    char a[33] = {0};

    for(int i = 0;i < 32;i++){
        a[i] = n % 2;
        n /= 2;
    }

    for(int j = 31;j >= 0;j--){
        printf("%d",a[j]);
    }

    return 0;
}