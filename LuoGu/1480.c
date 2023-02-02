#include <stdio.h>
#include <string.h>

int main()
{
    char a[5005] = {0};
    long long b = 0;
    scanf("%s%lld",a,&b);

    size_t cntA = strlen(a);
    int A[5005] = {0};
    for (int i = 0; i < cntA; ++i) {
        A[i] = a[i] - '0';
    }

    long long remind = 0;
    int ans[5005] = {0};
    for (int i = 0; i < cntA; ++i) {
        remind = remind * 10 + A[i];
        ans[i] = remind / b;
        if (ans[i] != 0) {
            remind -= ans[i] * b;
        }
    }

    int i = 0;
    for (; ans[i] == 0 && i != cntA - 1; ++i) ;
    while (i < cntA) {
        printf("%d",ans[i]);
        i++;
    }

    return 0;
}