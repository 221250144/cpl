#include<stdio.h>

int main()
{
    int n = 0;
    int k = 0;
    char x[1000000];

    scanf("%d%s%d",&n,x,&k);

    for (int i = (k - 1);i >= 0;i--){
        printf("%c",x[i]);
    }
    for (int j = n - 1;j >= k;j--){
        printf("%c",x[j]);
    }

    return 0;

}