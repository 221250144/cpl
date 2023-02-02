#include<stdio.h>

int main()
{
    int cnt = 0;
    int b = 0;
    int a[100] = {0};
    for (int i = 0; i < 100; ++i) {
        scanf("%d",&b);
        if (b != 0) {
           a[i] = b;
           cnt++;
        } else {
            break;
        }
    }
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%d ",a[i]);
    }

    return 0;
}