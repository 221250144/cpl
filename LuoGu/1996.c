#include<stdio.h>

int main()
{
    int numbers[105] = {0};
    int n = 0;
    int k = 0;
    int cnt = 0;
    scanf("%d%d",&n,&k);
    int t = n;
    for (int i = 1; i <= n; ++i) {
        numbers[i] = 1;
    }
    for (int j = 1; j <= n; j++) {
        if (numbers[j] == 1) {
            cnt++;
        }
        if (cnt == k) {
            printf("%d ",j);
            numbers[j] = 0;
            cnt = 0;
            t--;
        }
        if (t == 0) {
            break;
        }
        if ( j == n ){
            j = 0;
        }
    }

    return 0 ;
}