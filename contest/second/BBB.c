#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[20] = {0};
    scanf("%s",str);
    while (1) {
        char *loc = strchr(str, '.');
        char string[5] = {0};
        if (loc != NULL) {
            strncpy(string, str, loc - str);
        } else {
            strcpy(string,str);
        }
        int temp = atoi(string);
        int ans[10] = {0};

        int cnt = 0;
        while (temp > 0) {
            ans[cnt++] = temp % 2;
            temp /= 2;
        }

        for (int j = 7; j >= 0; j--) {
            printf("%d", ans[j]);
        }
        if (loc == NULL) break;
        strcpy(str,loc + 1);
    }

    return 0;
}