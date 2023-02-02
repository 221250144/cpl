#include <stdio.h>

int main()
{
    int n = 0 ;
    scanf("%d",&n);
    int t = 1;
    for (int i = 0; i < n - 1; ++i) {
        t = ( t + 1 ) * 2;
    }
    printf("%d",t);


    return 0;
}