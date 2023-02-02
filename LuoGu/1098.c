#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str[105] = {0};
    int p1,p2,p3;
    scanf("%d%d%d%s",&p1,&p2,&p3,str);

    size_t len = strlen(str);
    for (int i = 0; i < len;) {
        if (str[i] == '-' && isdigit(str[i - 1]) && isdigit(str[i + 1]) && str[i - 1] < str[i + 1]) {
            if (p1 == 3) {
                for (int j = 0; j < p2 * (str[i + 1] - str[i - 1] - 1); ++j) {
                    printf("*");
                }
            } else {
                if (p3 == 1) {
                    for (int j = str[i - 1] + 1; j <= str[i + 1] - 1; ++j) {
                        for (int k = 0; k < p2; ++k) {
                            printf("%c", j);
                        }
                    }
                } else {
                    for (int j = str[i + 1] - 1; j >= str[i - 1] + 1; j--) {
                        for (int k = 0; k < p2; ++k) {
                            printf("%c", j);
                        }
                    }
                }
            }
        } else if (str[i] == '-' && islower(str[i - 1]) && islower(str[i + 1]) && str[i - 1] < str[i + 1]) {
            if (p1 == 3) {
                for (int j = 0; j < p2 * (str[i + 1] - str[i - 1] - 1); ++j) {
                    printf("*");
                }
            } else {
                if (p3 == 1) {
                    for (int j = str[i - 1] + 1; j <= str[i + 1] - 1; ++j) {
                        j = (p1 == 1 ? j : j - 32);
                        for (int k = 0; k < p2; ++k) {
                            printf("%c", j);
                        }
                        j = (p1 == 1 ? j : j + 32);
                    }
                } else {
                    for (int j = str[i + 1] - 1; j >= str[i - 1] + 1; j--) {
                        j = (p1 == 1 ? j : j - 32);
                        for (int k = 0; k < p2; ++k) {
                            printf("%c", j);
                        }
                        j = (p1 == 1 ? j : j + 32);
                    }
                }
            }
        } else {
            printf("%c",str[i]);
        }
        i++;
    }

    return 0;
}