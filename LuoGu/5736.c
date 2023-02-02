#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool judge(int number) ;

int main()
{
    int n = 0;
    scanf("%d",&n);
    int a[100005] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
        if (judge(a[i]) == true) {
            printf("%d ",a[i]);
        }
    }

    return 0;
}

bool judge (int number) {
    if (number == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(number); ++i) {
        if ((number % i) == 0) {
            return false;
        }
    }
    return true;
}