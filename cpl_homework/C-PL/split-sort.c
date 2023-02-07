#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Length 105

int main()
{
    char *a = malloc(100005 * sizeof (*a));
    char *b = malloc(105 * Length * sizeof (*b));
    memset(b,0,105 * Length);
    char ch;
    scanf("%s%c%c",a,&ch,&ch);
    char *temp = strtok(a,&ch);
    int i = 0;
    for (;temp != NULL; ++i) {
        strcpy((b + Length * i),temp);
        temp = strtok(NULL,&ch);
    }
    char *t = malloc(105 * sizeof (*b));
    for (int j = 0; j <= i - 2; ++j) {
        for (int k = 0; k <= i - 1; ++k) {
            if (strcmp((b + Length * k),(b + Length * (k + 1))) > 0) {
                strcpy(t,(b + Length * k));
                strcpy((b + Length * k),(b + Length * (k + 1)));
                strcpy((b + Length * (k + 1)),t);
            }
        }
    }
    for (int j = 0; j <= i; ++j) {
        printf("%s\n",(b + Length *  j));
    }

    free(a);
    free(b);
    free(t);
    return 0;
}