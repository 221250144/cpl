#include<stdio.h>

int main()
{
    int f[10000] = {0};
    for (int i = 2; i <= 10000; ++i) {
        int t = i;
        int cnt = 0;
        for (int j = 1; j < i; ++j) {
            if(i % j == 0){
                t -= j;
                f[cnt] = j;
                cnt++;
            }
        }
        if(t == 0){
            printf("%d = %d",i,f[0]);
            for (int j = 1; j < cnt; ++j) {
            printf(" + %d",f[j]);
        }
            printf("\n");
        }
    }


    return 0;
}
