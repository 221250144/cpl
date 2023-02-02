#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Mystrcat (char *a,char *b) ;

int main()
{
    int T = 0;
    scanf("%d",&T);
    char *s1 = malloc(1005 * sizeof (*s1));
    char *s2 = malloc(1005 * sizeof (*s2));

    for (int i = 0; i < T; ++i) {
        scanf("%s%s",s1,s2);
        Mystrcat(s1,s2);
    }

    return 0;
}

void Mystrcat (char *a,char *b)
{
    char *ans = malloc(2005 * sizeof (*ans));
    strcpy(ans,a);
    int len1 = strlen(a);
    int len2 = strlen(b);
    int temp = 0;
    for (int i = 0,j = 0; i < len1; i++ ) {
        if (*(a + i) == *(b + j)) {
            j++;
            if (i == len1 - 1) {
                temp = j;
            }
        } else {
            i -= j;
            j = 0;
        }
    }
    for (int i = len1, k = temp; i < len1 + len2 - temp; i++,k++) {
        *(ans + i) = *(b + k);
    }
    for (int i = 0; i < len1 + len2 - temp; ++i) {
        printf("%c",*(ans + i));
    }
    printf("\n");
}