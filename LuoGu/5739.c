#include <stdio.h>

int jc(int number) ;
int main()
{
    int n = 0;
    scanf("%d",&n);
    printf("%d", jc(n));

    return 0;
}

int jc(int number) {
    if (number == 1) {
        return 1;
    }
    return number * jc(number - 1);
}