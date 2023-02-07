#include<stdio.h>

int main()
{
    int n = 0;
    int cnt = 0;

    scanf("%d",&n);

    int max = n;

    do{
        if(n % 2 == 0){
            n = n / 2;
            cnt++;
            if (max < n){
                max = n;
            }
        }else{
            n = 3 * n + 1;
            cnt++;
            if (max < n){
                max = n;
            }
        }
    }while(n != 1);
    printf("%d %d",cnt,max);

    return 0;
}