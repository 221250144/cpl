#include <stdio.h>

int ans1[10005] = {0};
int ans2[10005] = {0};
int ans3[100000005] = {0};

void Print(int ans[],int lens,char ch[]);

int main()
{
    int p1 = 0;
    int p2 = 0;
    char ch[11] = {0};
    scanf("%d%d%s",&p1,&p2,ch);

    int max = p1 > p2 ? p1 : p2;
    int a1[10005] = {0};
    int a2[10005] = {0};
    for (int i = max - p1; i <= max; i++) {
        scanf("%d",&a1[i]);
    }
    for (int i = max - p2; i <= max; i++) {
        scanf("%d",&a2[i]);
    }

    for (int i = 0; i <= max; ++i) {
        ans1[i] = a1[i] + a2[i];
        ans2[i] = a1[i] - a2[i];
    }

    int a3[10005] = {0};
    int a4[10005] = {0};
    for (int i = max,j = 0; i >= 0;i--,j++) {
        a3[i] = a1[j];
        a4[i] = a2[j];
    }
    for (int i = 0; i <= p1 + p2; ++i) {
        int pow = p1 + p2 - i;
        for (int j = pow,p = 0; j >= 0; j--,p++) {
            ans3[i] += (a3[j] * a4[p]);
        }
    }
    Print(ans1,max,ch);
    printf("\n");
    Print(ans2,max,ch);
    printf("\n");
    Print(ans3,p1 + p2,ch);

    return 0;
}

void Print(int ans[],int lens,char ch[]) {
    for (int i = 0; i <= lens; i++) {
        if (ans[i] != 0) {
            if (i == 0) {
                if (lens - i != 1) {
                    if (ans[i] == 1 || ans[i] == -1) {
                        printf("%s^%d", ch, lens - i);
                    } else {
                        printf("%d%s^%d", ans[i], ch, lens - i);
                    }
                } else {
                    if (ans[i] == 1 || ans[i] == -1) {
                        printf("%s", ch);
                    } else {
                        printf("%d%s", ans[i], ch);
                    }
                }
            } else if (i != lens) {
                if (lens - i != 1) {
                    if (ans[i] == 1) {
                        printf("+%s^%d", ch, lens - i);
                    } else if (ans[i] == -1) {
                        printf("-%s^%d", ch, lens - i);
                    } else if (ans[i] > 0) {
                        printf("+%d%s^%d", ans[i], ch, lens - i);
                    } else {
                        printf("%d%s^%d", ans[i], ch, lens - i);
                    }
                } else {
                    if (ans[i] == 1) {
                        printf("+%s", ch);
                    } else if (ans[i] == -1) {
                        printf("-%s", ch);
                    } else if (ans[i] > 0) {
                        printf("+%d%s", ans[i], ch);
                    } else {
                        printf("%d%s", ans[i],ch);
                    }
                }
            } else {
                if (ans[i] > 0) {
                    printf("+%d", ans[i]);
                } else {
                    printf("%d", ans[i]);
                }
            }
        }
    }
}