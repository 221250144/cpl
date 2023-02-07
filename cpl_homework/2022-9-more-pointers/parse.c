#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Length 15
int cnt = 0;
char *ans;

int main()
{
    ans = malloc(1300 * Length * sizeof (*ans));
    char *rule = malloc(130 * sizeof (*rule));
    char *a = malloc(1300 * Length * sizeof (*a));
    char *m = malloc(1300 * sizeof (*m));
    char *name = malloc(1300 * sizeof (*name));
    scanf("%s%s",rule,name);

    while (scanf("%s",a) != EOF) {
        char *t1 = strchr(a, '-');
        if (t1 != NULL) { //a里面有-
            char *t2 = strchr(rule, *(a + 1));
            if (t2 != NULL) { //规则里有这个参数
                if (*(t2 + 1) == ':') { //参数后面需要一个值
                    char *next = malloc(1000 * sizeof (*next));
                    if (scanf("%s",next) == EOF) { //需要值但是没有
                        printf("%s: option requires an argument -- '%c'",name,*(a + 1));
                        exit(0);
                    } else { // 需要值并且有
                        *(ans + Length * cnt) = *(a + 1);
                        *(ans + Length * cnt + 1) = '=';
                        for (int i = 0,j = 2; i <= strlen(next); ++i,j++) {
                            *(ans + Length * cnt + j) = *(next + i);
                        }
                        cnt++;
                    }
                    free(next);
                } else { // 后面不需要值
                    *(ans + Length * cnt) = *(a + 1);
                    cnt++;
                }
            } else { //规则里没有这个参数
                printf("%s: invalid option -- '%c'",name,*(a + 1));
                exit(0);
            }
        }
    }

    printf("%s\n",name);
    for (int i = 0; i < cnt; ++i) {
        printf("%s\n",(ans + Length * i));
    }

    free(rule);
    free(a);
    free(m);
    free(name);
    return 0;
}