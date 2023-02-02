#include<stdio.h>

int main()
{
    char str[100] = {0};
    char a[100] = {0};
    gets(str);
    int cnt = 0;
    for (int i = 0; i < 100; ++i) {
        if(str[i] != '\0'){
            cnt++;
        }
    }
    for (int i = 0; i < cnt; ++i) {
        if (str[i] != ' ') {
            printf("%c", str[i]);
        }
    }

    return 0;
}