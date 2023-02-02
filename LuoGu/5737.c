#include <stdio.h>
#include <stdbool.h>

bool judge(int number) ;

int main ()
{
    int min = 0;
    int max = 0;
    scanf("%d%d",&min,&max);

    int cnt = 0;
    int a[100005] = {0};
    for (int i = min; i <= max; ++i) {
        if (judge(i) == true) {
            a[cnt++] = i;
        }
    }

    printf("%d\n",cnt);
    for (int i = 0; i < cnt; ++i) {
        printf("%d ",a[i]);
    }
    return 0;
}

bool judge(int number) {
    if (((number % 4 == 0) && (number % 100 != 0)) || (number % 400 == 0)) {
        return true;
    }
    return false;
}