#include <stdio.h>

void Print(int ans[],int lens,char ch);

int main ()
{
    int n = 0;
    scanf("%d",&n);
    int ans[105] = {0};
    for (int i = 0; i <= n; ++i) {
        scanf("%d",&ans[i]);
    }
    Print(ans,n,'x');

    return 0;
}

void Print(int ans[],int lens,char ch) {
    for (int i = 0; i <= lens; i++) {
        if (ans[i] != 0) {
            if (i == 0 && lens != 0) {
                if (lens - i != 1) {
                    if (ans[i] == 1) {
                        printf("%c^%d", ch, lens - i);
                    }else if (ans[i] == -1) {
                        printf("-%c^%d", ch, lens - i);
                    } else {
                        printf("%d%c^%d", ans[i], ch, lens - i);
                    }
                } else {
                    if (ans[i] == 1 || ans[i] == -1) {
                        printf("%c", ch);
                    } else {
                        printf("%d%c", ans[i], ch);
                    }
                }
            } else if (i != lens) {
                if (lens - i != 1) {
                    if (ans[i] == 1) {
                        printf("+%c^%d", ch, lens - i);
                    } else if (ans[i] == -1) {
                        printf("-%c^%d", ch, lens - i);
                    } else if (ans[i] > 0) {
                        printf("+%d%c^%d", ans[i], ch, lens - i);
                    } else {
                        printf("%d%c^%d", ans[i], ch, lens - i);
                    }
                } else {
                    if (ans[i] == 1) {
                        printf("+%c", ch);
                    } else if (ans[i] == -1) {
                        printf("-%c", ch);
                    } else if (ans[i] > 0) {
                        printf("+%d%c", ans[i], ch);
                    } else {
                        printf("%d%c", ans[i],ch);
                    }
                }
            } else {
                if (ans[i] > 0) {
                    if (lens != 0) {
                        printf("+%d", ans[i]);
                    } else {
                        printf("%d",ans[i]);
                    }
                } else {
                    printf("%d", ans[i]);
                }
            }
        }
    }
}