#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i=1;
    int cnt=0;
    while(i<=n){
        int k=2;
        do{
            if(i%k==0){
                cnt++;
                break;
            }
            k++;
        }while(k<i);
    i++;
    }
    printf("%d",n-cnt);

    return 0;
}
