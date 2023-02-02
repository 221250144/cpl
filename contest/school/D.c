#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// 类型：1、variable(变量)   2、integer(整数)  3、operator(运算符)(不包括括号)  4、float(浮点数)  5、error 6、括号

bool Row[1000] = {0}; // 判断每行是否合法
int Length[1000] = {0}; // 记录每行的长度
int row = 0;
char stack[1000] = {0}; // 检查括号是否合理的栈
int top = 1;

typedef struct token { // 保存每个东西的类型和值
    int type;
    char str[32];
    int ival;
    float fval;
} Token;
Token tokens[1000][1000];

typedef struct assignment { // 变量赋值
    char name[32];
    int val;
    bool stuta; // 判断是否被赋值（true：是）
} Assignment;
Assignment F[1000];

typedef struct assignment_float { // 变量赋值
    char name[32];
    float val;
    bool stuta; // 判断是否被赋值（true：是）
} Assignment_float;
Assignment_float F_float[1000];

int cnt = 0;

int find(int l, int r, int row5); // 是否找到其他运算符 0:没有   1:加减    2:乘除
bool check_parentheses(int l, int r, int row3); // 检查是否被括号包住
int eval(int l, int r, int row2); // 递归求值（整型）
float eval_float(int l, int r, int row8); //递归求值（浮点型）
int evalAssign(char *name, int row4); // 处理赋值语句(整型）
float evalAssign_float(char *name, int row9,int a);
void judge(const char *a, int number); // 词法分析
int Row_type(int l, int r, int row7); // 判断类型

int main() {
    char ch;
    for (int i = 0; scanf("%s", tokens[row][i].str) != EOF; i++) {// 比较离谱的一个输入
        Length[row]++;
        scanf("%c", &ch);
        judge(tokens[row][i].str, i);
        if (tokens[row][i].type == 2 || tokens[row][i].type == 4) {
            tokens[row][i].ival = atoi(tokens[row][i].str);
            tokens[row][i].fval = atof(tokens[row][i].str);
        }
        if (ch == '\n') {
            row++;
            i = -1;
        }
    }

    for (int i = 0; i < row; ++i) {
        if (Row[i] == 1) {
            printf("Error\n"); // 词法错误
        } else {
            if (Row_type(0, Length[i] - 1, i) == 0) {
                int ans = eval(0, Length[i] - 1, i);
                if (Row[i] == 1) { // 表达式不符合逻辑
                    printf("Error\n");
                } else {
                    printf("%d\n", ans);
                }
            } else {
                float ans = eval_float(0, Length[i] - 1, i);
                if (Row[i] == 1) { // 表达式不符合逻辑
                    printf("Error\n");
                } else {
                    printf("%f\n", ans);
                }
            }
        }
    }

    return 0;
}

bool check_parentheses(int l, int r, int row3) {
    int status = 0;
    for (int i = l; i <= r; ++i) { // 判断括号是否合法
        if (tokens[row3][i].str[0] == '(' || tokens[row3][i].str[0] == ')') {
            stack[top++] = tokens[row3][i].str[0];
            status = 1;
        }
        if (tokens[row3][i].str[0] == ')' && stack[top - 2] == '(') {
            stack[--top] = 0;
            stack[--top] = 0;
        }
        if (stack[1] == 0 && status == 1 && i != r) {
            return false;
        }
    }
    if (stack[1] == 0) { // 合法
        if (tokens[row3][l].str[0] == '(' && tokens[row3][r].str[0] == ')') { // 表达式两边是否都为括号
            return true;
        } else {
            return false;
        }
    } else { // 括号有问题
        Row[row3] = true;
    }
    return false;
}

int Row_type(int l, int r, int row7) {
    for (int i = l; i <= r; ++i) {
        if (tokens[row7][i].type == 4 || (tokens[row7][i].type == 1 && evalAssign_float(tokens[row7][i].str,row7,0) != 0)) {
            return 1;
        }
    }
    return 0;
}

int eval(int l, int r, int row2) {
    if ((r - l) == 1 && tokens[row2][l].str[0] == '-') {
        if (tokens[row2][r].type == 2) {
            return tokens[row2][r].ival *= (-1);
        } else {
            return evalAssign(tokens[row2][r].str, row2) * (-1);
        }
    } else if (l > r) { // 有毛病
        Row[row2] = true;
    } else if (l == r) { // 递归到最后的情况
        if (tokens[row2][l].type == 3 && tokens[row2][l].str[0] != '-') {
            Row[row2] = true;
            return 1;
        } else if (tokens[row2][l].type == 1) { // 变量类型的东西
            return evalAssign(tokens[row2][l].str, row2);
        } else if (tokens[row2][l].str[0] == '-') {
            return tokens[row2][l + 1].ival * -1;
        } else {
            return tokens[row2][l].ival;
        }
    } else if (check_parentheses(l, r, row2) == true) { // 括号包着表达式
        return eval(l + 1, r - 1, row2);
    } else { // 先寻找主运算符
        int position = 0;
        for (int i = l; i < r; ++i) { // 碰到了赋值语句
            if (tokens[row2][i].type == 1 && tokens[row2][i + 1].str[0] == '=') {
                F[cnt].val = eval(i + 2, r, row2);
                strcpy(F[cnt].name, tokens[row2][i].str);
                F[cnt].stuta = true; // 状态改变
                cnt++;
                return F[cnt - 1].val;
            }
        }
        for (int i = r; i >= l; i--) {
            int cnt1 = 0;
            if (tokens[row2][i].str[0] == ')') {// 跳过括号里的运算符
                cnt1++;
                i--;
                while (cnt1 != 0) {
                    if (tokens[row2][i].str[0] == ')') {
                        cnt1++;
                    } else if (tokens[row2][i].str[0] == '(') {
                        cnt1--;
                    }
                    i--;
                    if (i == l) {
                        break;
                    }
                }
            }
            if (tokens[row2][i].str[0] == '+') { // 主运算符是'+'或'-'
                position = i;
                return eval(l, position - 1, row2) + eval(position + 1, r, row2);
            } else if (tokens[row2][i].str[0] == '-') { // 这个‘-’可能是减号也可能是负号
                if (i == l || tokens[row2][i - 1].type == 3) { // 是负号
                    position = i - 1;
                    char ch = tokens[row2][i - 1].str[0];
                    if (ch == '+' && i != l) { // i != l : 2 + - 4 * - 2的情况第一个负号
                        return eval(l, position - 1, row2) + eval(position + 1, r, row2);
                    } else if (ch == '-' || i == l) {
                        int cnt2 = 0;
                        int temp = 0;
                        for (int j = i; tokens[row2][j].str[0] == '-' && j >= l; j--) {
                            cnt2++;
                            temp = j;
                        }
                        if (temp == l) {
                            return (int) (eval(i + 1, r, row2) * pow(-1, cnt2));
                        } else {
                            if (tokens[row2][temp].type == 3) {
                                char ch1 = tokens[row2][temp].str[0];
                                if (ch1 == '+') {
                                    return eval(l, temp - 1, row2) + (int) (eval(i + 1, r, row2) * pow(-1, cnt2));
                                } else if (ch1 == '*' && find(l, temp - 1, row2) != 1) {
                                    return eval(l, temp - 1, row2) * (int) (eval(i + 1, r, row2) * pow(-1, cnt2));
                                } else if (ch1 == '/' && find(l, temp - 1, row2) != 1) {
                                    return eval(l, temp - 1, row2) / (int) (eval(i + 1, r, row2) * pow(-1, cnt2));
                                }
                            } else {
                                return eval(l, temp - 1, row2) - eval(temp + 1, r, row2);
                            }
                        }
                    } else if (ch == '*' && find(l, position - 1, row2) != 1 && find(position + 1, r, row2) != 2) {
                        return eval(l, position - 1, row2) * eval(position + 1, r, row2);
                    } else if (ch == '/' && find(l, position - 1, row2) != 1 && find(position + 1, r, row2) != 2) {
                        return eval(l, position - 1, row2) / eval(position + 1, r, row2);
                    }
                } else { // 是减号
                    position = i;
                    return eval(l, position - 1, row2) - eval(position + 1, r, row2);
                }
            }
        }
        for (int i = r; i >= l; i--) {
            int cnt1 = 0;
            if (tokens[row2][i].str[0] == ')') {// 跳过括号里的运算符
                cnt1++;
                i--;
                while (cnt1 != 0) {
                    if (tokens[row2][i].str[0] == ')') {
                        cnt1++;
                    } else if (tokens[row2][i].str[0] == '(') {
                        cnt1--;
                    }
                    i--;
                    if (i == l) {
                        break;
                    }
                }
            }
            if (tokens[row2][i].str[0] == '*') { // 主运算符是'*'或'/'
                position = i;
                return eval(l, position - 1, row2) * eval(position + 1, r, row2);
            } else if (tokens[row2][i].str[0] == '/') {
                position = i;
                int m = eval(position + 1, r, row2);
                if (m != 0) {
                    return eval(l, position - 1, row2) / m;
                } else {
                    Row[row2] = true;
                    return 1;
                }
            }
        }
    }
    Row[row2] = true;
    return 1;
}

float eval_float(int l, int r, int row8) {
    if (l > r) { // 有毛病
        Row[row8] = true;
    } else if (l == r) { // 递归到最后的情况
        if (tokens[row8][l].type == 3) {
            Row[row8] = true;
            return 0;
        } else if (tokens[row8][l].type == 1) { // 变量类型的东西
            return evalAssign_float(tokens[row8][l].str, row8,1);
        } else {
            return tokens[row8][l].fval;
        }
    } else if (check_parentheses(l, r, row8) == true) { // 括号包着表达式
        return eval_float(l + 1, r - 1, row8);
    } else { // 先寻找主运算符
        int position = 0;
        for (int i = l; i <= r; ++i) { // 碰到了赋值语句
            if (tokens[row8][i].type == 1 && tokens[row8][i + 1].str[0] == '=') {
                F_float[cnt].val = eval_float(i + 2, r, row8);
                strcpy(F_float[cnt].name, tokens[row8][i].str);
                F_float[cnt].stuta = true; // 状态改变
                cnt++;
                return F_float[cnt - 1].val;
            }
        }
        for (int i = r; i >= l; i--) {
            int cnt1 = 0;
            if (tokens[row8][i].str[0] == ')') {// 跳过括号里的运算符
                cnt1++;
                i--;
                while (cnt1 != 0) {
                    if (tokens[row8][i].str[0] == ')') {
                        cnt1++;
                    } else if (tokens[row8][i].str[0] == '(') {
                        cnt1--;
                    }
                    i--;
                    if (i == l) {
                        break;
                    }
                }
            }
            if (tokens[row8][i].str[0] == '+') { // 主运算符是'+'或'-'
                position = i;
                return eval_float(l, position - 1, row8) + eval_float(position + 1, r, row8);
            } else if (tokens[row8][i].str[0] == '-') { // 这个‘-’可能是减号也可能是负号
                position = i;
                return eval_float(l, position - 1, row8) - eval_float(position + 1, r, row8);
            }
        }
        for (int i = r; i >= l; i--) {
            int cnt1 = 0;
            if (tokens[row8][i].str[0] == ')') {// 跳过括号里的运算符
                cnt1++;
                i--;
                while (cnt1 != 0) {
                    if (tokens[row8][i].str[0] == ')') {
                        cnt1++;
                    } else if (tokens[row8][i].str[0] == '(') {
                        cnt1--;
                    }
                    i--;
                    if (i == l) {
                        break;
                    }
                }
            }
            if (tokens[row8][i].str[0] == '*') { // 主运算符是'*'或'/'
                position = i;
                return eval_float(l, position - 1, row8) * eval_float(position + 1, r, row8);
            } else if (tokens[row8][i].str[0] == '/') {
                position = i;
                float m = eval_float(position + 1, r, row8);
                if (m != 0) {
                    return eval_float(l, position - 1, row8) / m;
                } else {
                    Row[row8] = true;
                }
            }
        }
    }
    Row[row8] = true;
    return 0;
}

int find(int l, int r, int row5) {
    int position = 0;
    for (int i = r; i >= l; i--) {
        int cnt1 = 0;
        if (tokens[row5][i].str[0] == ')') {// 跳过括号里的运算符
            cnt1++;
            i--;
            while (cnt1 != 0) {
                if (tokens[row5][i].str[0] == ')') {
                    cnt1++;
                } else if (tokens[row5][i].str[0] == '(') {
                    cnt1--;
                }
                i--;
                if (i == l) {
                    break;
                }
            }
        }
        if (tokens[row5][i].str[0] == '+') { // 主运算符是'+'或'-'
            return 1;
        } else if (tokens[row5][i].str[0] == '-') { // 这个‘-’可能是减号也可能是负号
            if (i == l || tokens[row5][i - 1].type == 3) { // 是负号
                position = i - 1;
                char ch = tokens[row5][i - 1].str[0];
                if (ch == '+') {

                } else if (ch == '-' || i == l) {
                    int cnt2 = 0;
                    int temp = 0;
                    for (int j = i; tokens[row5][j].str[0] == '-' && j >= l; j--) {
                        cnt2++;
                        temp = j;
                    }
                    if (temp == l) {

                    } else {
                        if (tokens[row5][temp].type == 3) {
                            char ch1 = tokens[row5][temp].str[0];
                            if (ch1 == '+') {
                            } else if (ch1 == '*' || ch1 == '/') {
                                int t = find(l, temp - 1, row5);
                                return t;
                            }
                        }
                    }
                } else if (ch == '*' || ch == '/') {
                    int t = find(l, position - 1, row5);
                    return t;
                }
            } else { // 是减号
                return 1;
            }
        }
    }
    for (int i = r; i >= l; i--) {
        int cnt1 = 0;
        if (tokens[row5][i].str[0] == ')') {// 跳过括号里的运算符
            cnt1++;
            i--;
            while (cnt1 != 0) {
                if (tokens[row5][i].str[0] == ')') {
                    cnt1++;
                } else if (tokens[row5][i].str[0] == '(') {
                    cnt1--;
                }
                i--;
                if (i == l) {
                    break;
                }
            }
        }
        if (tokens[row5][i].str[0] == '*') { // 主运算符是'*'或'/'
            position = i;
            return 2;
        } else if (tokens[row5][i].str[0] == '/') {
            position = i;
            int m = eval(position + 1, r, row5);
            if (m != 0) {
                return 2;
            } else {
                Row[row5] = true;
                return 2;
            }
        }
    }
    return 0;
}

int evalAssign(char *name, int row4) { // 当遇到赋值语句时寻找变量的值
    for (int i = 0; i < cnt; ++i) {
        if (strcmp(name, F[i].name) == 0 && F[i].stuta == true) {
            return F[i].val;
        }
    }
    Row[row4] = true;
    return 0;
}

float evalAssign_float(char *name, int row9,int a) {
    for (int i = 0; i < cnt; ++i) {
        if (strcmp(name, F_float[i].name) == 0 && F_float[i].stuta == true) {
            return F_float[i].val;
        }
    }
    if (a == 1) {
        Row[row9] = true;
    }
    return 0;
}

void judge(const char *a, int number) {
    size_t len = strlen(a);
    char *t1 = strchr(a, '.');

    if (*a == '+' || *a == '-' || *a == '*' || *a == '/' || *a == '=') {
        tokens[row][number].type = 3; // 运算符
        return;
    } else if (*a == '(' || *a == ')') {
        tokens[row][number].type = 6;
        return;
    } else if (*a == '_' || (*a >= 'A' && *a <= 'Z') || (*a >= 'a' && *a <= 'z')) {
        if (len == 1) { // 变量
            tokens[row][number].type = 1;
            return;
        } else {
            for (int i = 1; i < len; ++i) {
                if (!(*(a + i) == '_' || (*(a + i) >= 'A' && *(a + i) <= 'Z') ||
                      (*(a + i) >= 'a' && *(a + i) <= 'z') ||
                      (*(a + i) >= '0' && *(a + i) <= '9'))) {
                    break;
                }
                if (i == len - 1) {
                    tokens[row][number].type = 1;
                    return;
                }
            }
        }
    } else if (t1 != NULL) { // 浮点型
        char *t3 = strchr(t1 + 1, '.');
        if (*a != '.' && *(a + len - 1) != '.' && t3 == NULL) { // 第一个和最后一个都不是小数点并且只有一个小数点
            for (int i = 0; i < len; ++i) {
                if (!((*(a + i) >= '0' && *(a + i) <= '9') || *(a + i) == '.')) {
                    break;
                }
                if (i == len - 1) {
                    tokens[row][number].type = 4;
                    return;
                }
            }
        } else {
            Row[row] = 1;
        }
    } else if (t1 == NULL) { // 整型
        if (len == 1 && (*a >= '0' && *a <= '9')) {
            tokens[row][number].type = 2;
            return;
        } else if (*a != '0') {
            for (int i = 0; i < len; ++i) {
                if (!((*(a + i) >= '0' && *(a + i) <= '9') || *(a + i) == '.')) {
                    break;
                }
                if (i == len - 1) {
                    tokens[row][number].type = 2;
                    return;
                }
            }
        } else {
            Row[row] = 1;
        }
    }
    Row[row] = 1;
}