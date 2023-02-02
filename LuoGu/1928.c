#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *unpack() {
    int n = 0;
    char ch = 0;
    char *ans = malloc(2000 * sizeof(char));
    char *s = malloc(2000 * sizeof(char));
    memset(s,0,2000);
    memset(ans,0,2000);
    while (scanf("%c",&ch) != EOF) {
        if (ch == '[') {
            scanf("%d",&n);
            *s = *unpack();
            while (n--) {
                strcat(ans,s);
            }
        } else if (ch == ']') {
            return ans;
        } else {
            *(ans++) = ch;
        }
    }
    return ans;
}

int main () {
    printf("%s",unpack());
    return 0;
}