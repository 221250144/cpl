#include <stdio.h>

int statue[100005] = {0};
int number = 0;
int cnt = 0;
int ans[10005] = {0};

int find(int end, int b[],int begin) {
    if (b[end] == begin) {
        statue[end] = 1;
        number++;
        ans[cnt++]++;
        return 0;
    }
    statue[end] = 1;
    ans[cnt]++;
    find(b[end],b,begin);
}
int main()
{
    int n = 0;
    char type[10] = {0};
    scanf("%d%s",&n,type);
    int a[100005] = {0};
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        if (statue[i] == 0) {
            find(i,a,i);
        }
    }

    for (int i = 0; i < cnt - 2; ++i) {
        for (int j = 0; j < cnt - 2; ++j) {
            int temp = 0;
            if (ans[j] < ans[j + 1]) {
                temp = ans[j + 1];
                ans[j + 1] = ans[j];
                ans[j] = temp;
            }
        }
    }

    if (type[0] == 'o' && type[1] == 'r' && type[2] == 'd' && type[3] == 'e' && type[4] == 'r') {
        for (int i = 0; i < cnt; ++i) {
            printf("%d ",ans[i]);
        }
    } else {
        printf("%d",number);
    }

    return 0;
}