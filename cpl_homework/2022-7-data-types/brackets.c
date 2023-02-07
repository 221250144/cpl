#include<stdio.h>

int main()
{
    int top = 1;
    char stack[100005] = {0};
    char a[35][100005] = {0};
    int T = 0;
    scanf("%d",&T);
    char ch;
    scanf("%c",&ch);
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < 10005; ++j) {
            if ((ch = getchar()) != '\n') {
                a[i][j] = ch;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < T; ++i) {
        if (a[i][0] == ']' || a[i][0] == '}' || a[i][0] == ')') {
            printf("False\n");
            continue;
        }
        for (int j = 0; j < 100005; ++j) {
            stack[top++] = a[i][j];
            if (a[i][j] == ']' && stack[top - 2] == '[') {
                stack[--top] = 0;
                stack[--top] = 0;
            }
            if (a[i][j] == '}' && stack[top - 2] == '{') {
                stack[--top] = 0;
                stack[--top] = 0;
            }
            if (a[i][j] == ')' && stack[top - 2] == '(') {
                stack[--top] = 0;
                stack[--top] = 0;
            }
        }
        if (stack[1] == 0) {
            printf("True\n");
        } else {
            printf("False\n");
        }
        top = 1;
        for (int k = 0; k < 100005; ++k) {
            stack[k] = 0;
        }
    }

    return 0;
}