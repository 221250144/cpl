#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d",&n);

    int a[2000] = {0};

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ( j % i == 0){
                if (a[j] == 0){
                    a[j] = 1;
                } else {
                    a[j] = 0;
                }
            }
            //翻转
        }
    }
    for (int i = 0; i <= n; ++i) {
        if(a[i] == 1){
            printf("%d ",i);
        }
    }

    return 0;
}