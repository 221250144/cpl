#include <stdio.h>
#include <string.h>

typedef struct {
    int size;
    char s[20];
} Hhh ;
Hhh b[20];

int main()
{
    int n = 0;
    int k = 0;
    char a[20] = {0};
    scanf("%d%d%s",&n,&k,a);

    char done[10005][20] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d%s",&b[i].size,b[i].s);
    }
    for (int i = 0; i < k; ++i) {
        scanf("%s",done[i]);
    }

    long long sum = 1;
    for (int i = 0; i < n; ++i) {
        sum *= b[i].size;
    }

    for (int j = 0; j < n; ++j) {
        if (strchr(b[j].s, a[j]) == NULL) {
            printf("-1");
            return 0;
        }
    }

    for (int i = 0; i < k; ++i) {
        int temp = 1;
        for (int j = 0; j < n; ++j) {
            if (strchr(b[j].s,done[i][j]) == NULL) {
                temp = 0;
            }
        }
        if (temp == 1) {
            sum--;
        }
    }
    printf("%lld",sum);

    return 0;
}