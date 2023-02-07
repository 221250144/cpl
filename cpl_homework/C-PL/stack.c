#include<stdio.h>
#include<stdbool.h>

int top = 0;
int n = 0;
char stack[100005] = {0};

bool is_empty (void) {
    return top == 0;
}

bool is_full (void) {
    return top == n;
}

void Push (char ch) {
    if (is_full()) {

    } else {
        stack[top++] = ch;
    }
}

void Pop (void) {
    if (is_empty()) {
        printf("Empty\n");
    } else {
        stack[--top] = 0;
    }
}

char Top (void) {
    if (is_empty()) {
        printf("Empty\n");
    } else {
        printf("%c\n",stack[top - 1]);
    }
}

int main()
{
    scanf("%d",&n);
    char r[100005][10] = {0};
    int t = n;
    for (int i = 0; i < t; ++i) {
        scanf("%s",r[i]);
        if (r[i][0] == 'p' && r[i][1] == 'u' && r[i][2] == 's' && r[i][3] == 'h') {
            t++;
        }
    }
    for (int i = 0; i < t; ++i) {
        if (r[i][0] == 'p' && r[i][1] == 'u' && r[i][2] == 's' && r[i][3] == 'h') {
            Push(r[i + 1][0]);
        }
        if (r[i][0] == 'p' && r[i][1] == 'o' && r[i][2] == 'p') {
            Pop();
        }
        if (r[i][0] == 't' && r[i][1] == 'o' && r[i][2] == 'p') {
            Top();
        }
        if (r[i][0] == 'p' && r[i][1] == 'r' && r[i][2] == 'i' && r[i][3] == 'n' && r[i][4] == 't') {
            if (top > 0) {
                int temp = top;
                while (temp > 0) {
                    printf("| %c |\n",stack[temp - 1]);
                    temp--;
                }
                printf("|===|\n");
            } else {
                printf("Empty\n");
            }
        }
    }

    return 0;
}