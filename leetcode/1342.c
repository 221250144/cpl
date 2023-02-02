#include<stdio.h>

int main()
{
    int num=0;
    scanf("%d",&num);
    int cnt=0;
    while(num>0){
        if(num%2==1){
            num-=1;
            cnt++;
        }else{
            num/=2;
            cnt++;
        }
    }
    printf("%d",cnt);

    return 0;
}