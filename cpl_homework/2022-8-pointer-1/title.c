#include<stdio.h>
#include<stdlib.h>

int main()
{
    char *T = malloc(5000 * sizeof(*T));
    *(T + 0) = ' ';

    char temp = 0;
    int cnt = 1;
    for (int i = 1; ; ++i) {
        scanf("%c",&temp);
        cnt++;
        if (temp != '\n') {
            *(T + i) = temp;
        } else {
            *(T + i) = ' ';
            break;
        }
    }
    for (int i = 1;i <= cnt; ++i) {
        if (*(T + i) >= 65 && *(T + i) <= 90 && *(T + i - 1) != ' ') {
            *(T + i) += 32;
        }
        if (*(T + i) >= 97 && *(T + i) <= 122  && *(T + i - 1) == ' ') {
            *(T + i) -= 32;
        }
    }

    for (int i = 1; i < cnt - 1; ++i) {
        printf("%c",*(T + i));
    }

    return 0;
}