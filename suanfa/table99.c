#include<stdio.h>

int main()
{
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            if(j <= i){
                printf("%d * %d = %-4d",i,j,i * j);
//                if(i * j < 10){
//                    printf(" ");
//                }
            }
        }
        printf("\n");
    }

    return 0;
}
