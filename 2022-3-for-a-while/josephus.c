#include<stdio.h>

int main()
{
    int numbers[10000] = {0};
    int n = 0;
    int k = 0;
    int cnt = 0;
    scanf("%d%d",&n,&k);
    int t = n;
    for (int i = 0; i < n; ++i) {
        numbers[i] = 1;
    }
    for(int j = 0; j <= n; j++) {
        if(numbers[j] == 1){
            cnt++;
        }
        if(cnt == k){
            numbers[j] = 0;
            cnt = 0;
            t--;
        }
        if(t == 1 && numbers[j] == 1){
            printf("%d",j + 1);
            break;
        }
        if ( j == n ){
            j = -1;
        }
    }

    return 0 ;
}