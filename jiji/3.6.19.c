#include<stdio.h>
#include<string.h>

int main()
{
    char a[100] = {0};
    gets(a);
    int len;
    len = strlen(a);

    for (int i = 0; i < len; ++i) {
        if(a[i] >= 97 && a[i] <= 122){
            a[i] -= 32;
        }
    }

    printf("%s",a);

    return 0;
}