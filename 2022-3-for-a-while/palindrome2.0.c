#include<stdio.h>

int main()
{
    int f[100000] = {0};
    int n = 0;
    char string[100000] = {0};
    scanf("%d%s",&n,string);

    /*读入字符串*/
    for (int i = 0; i < n; ++i) {
        if (string[i] == '?' && string[n -1 - i] != '?'){
            string[i] = string[n -1 - i];
        }
    }
    /*一个问号的情况*/
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(string[i] != '?'){
            printf("%c",string[i]);
        } else {
            if (i < n / 2) {
                f[i] = cnt;
                cnt++;
                printf("%d%d", f[i] / 10, f[i] % 10);
            } else {
                printf("%d%d", f[n - i - 1] % 10, f[n - i - 1] / 10);
            }
        }
    }

    return 0;
}