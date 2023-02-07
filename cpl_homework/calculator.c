#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// 类型：1、variable(变量)   2、integer(整数)  3、operator(运算符)(不包括括号)  4、float(浮点数)  5、error 6、括号

bool Row[100] = {0}; // 判断每行是否符合词法
int Length[100] = {0}; // 记录每行的长度
int row = 0;
char stack[50] = {0}; // 检查括号是否合理的栈
int top = 1;
int cnt = 0;

typedef struct token { // 保存每个东西的类型和值
    int type;
    char str[32];
    int ival;
    double fval;
    bool status;
} Token ;
Token tokens[100][100]; // 保存输入
Token F[1000]; // 保存变量类型

Token v; // 所有函数共用的一个临时结构体

bool check_parentheses(int l,int r,int row3) ; // 检查是否被括号包住
bool check_minus(int l,int r,int row5) ; // 检查有无负号
Token eval(int l,int r,int row2) ; // 递归求值
Token evalAssign(int l,int r,int row4) ; // 处理赋值语句
Token meetValue(Token v1,Token v2,char op) ; // 进行对不同类型的算式的计算
Token find (char *name) ; // 需要变量发值时进行寻找
void judge(const char *a,int number) ; // 词法分析
void printValue(Token v1) ;  //最后进行输出


int main()
{
    char ch;
    for (int i = 0; scanf("%s",tokens[row][i].str) != EOF;i++) {// 比较离谱的一个输入
        Length[row]++;
        scanf("%c",&ch);
        judge(tokens[row][i].str,i);
        if (tokens[row][i].type == 2) {
            tokens[row][i].ival = atoi(tokens[row][i].str);
        }
        if (tokens[row][i].type == 4) {
            tokens[row][i].fval = atof(tokens[row][i].str);
        }
        if (ch == '\n') {
            row++; // 读到下一行里
            i = -1; // 下一行开始的位置
        }
    }

    for (int i = 0; i < row; ++i) {
        if (Row[i] == 1) {
            printf("Error\n");
        } else {
            printValue(evalAssign(0,Length[i] - 1,i));
        }
    }
    return 0;
}

bool check_parentheses(int l, int r, int row3) { // 利用类似栈的结构进行判断
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

bool check_minus(int l,int r,int row5) { // 判断是否是一个负数   思路：检查是否存在主运算符  是：不是负数
    int find_minus = 0; // 是否有“-”
    for (int i = r; i >= l; i--) {
        int cnt1 = 0;
        if (tokens[row5][i].str[0] == ')') { // 跳过括号里的运算符
            cnt1++;
            i--;
            while (cnt1 != 0) {
                if (tokens[row5][i].str[0] == ')') {
                    cnt1++;
                } else if (tokens[row5][i].str[0] == '(') {
                    cnt1--;
                }
                i--;
                if (i == r) {
                    break;
                }
            }
        }
        if (tokens[row5][i].str[0] == '+' || tokens[row5][i].str[0] == '*' ||tokens[row5][i].str[0] == '/') { // + / * 一定是主运算符
            return false;
        } else if (tokens[row5][i].str[0] == '-') { // 减号和负号的区分 ： 减号前面有东西（即不在最前面）且前面不是运算符
            find_minus = 1;
            if (i != l && tokens[row5][i - 1].str[0] != '-') {
                return false;
            }
        }
    }
    if (find_minus == 1) {
        return true;
    }
    return false;
}

Token find (char *name) { // 根据变量的名字来查找
    for (int i = 0; i < cnt; ++i) {
        if (strcmp(name,F[i].str) == 0 && F[i].status == true) {
            return F[i];
        }
    }
    v.type = 5; // 没找到
    return v;
}

Token eval(int l,int r,int row2) {
    if (l > r) { // 有毛病
        v.type = 5;
    } else if (l == r) { // 递归到最后的情况
        if (tokens[row2][l].type == 2 || tokens[row2][l].type == 4) {
            v = tokens[row2][l];
        } else if (tokens[row2][l].type == 1) {
            v = find(tokens[row2][l].str);
        } else {
            v.type = 5; // 留到最后的不是值和变量（可能是运算符
        }
    } else if (check_parentheses(l,r,row2) == true) { // 检查算式是否被括号包围
        return eval(l + 1,r - 1,row2); // 去掉括号
    } else if (check_minus(l,r,row2) == true) { // 检查是否是负数
        int position = 0; // n多个负号后的位置
        for (int i = l; i <= r; ++i) {
            if (tokens[row2][i].str[0] != '-') {
                position = i;
                break;
            }
        }
        v = eval(position,r,row2); // n多个负号后的值
        v.ival *= pow(-1,position - l); // 计算是正是负
        v.fval *= pow(-1,position - l); // 同上
    } else {
        int position = 0; // 主运算符的位置
        for (int i = r; i > l; i--) { //先找+ -
            int cnt1 = 0;
            if (tokens[row2][i].str[0] == ')') { // 跳过括号里的运算符
                cnt1++;
                i--;
                while (cnt1 != 0) {
                    if (tokens[row2][i].str[0] == ')') {
                        cnt1++;
                    } else if (tokens[row2][i].str[0] == '(') {
                        cnt1--;
                    }
                    i--;
                    if (i == r) {
                        break;
                    }
                }
            }
            if (tokens[row2][i].str[0] == '+') {
                position = i;
                Token v1 = eval(l,position - 1,row2);
                Token v2 = eval(position + 1,r,row2);
                return meetValue(v1,v2,tokens[row2][position].str[0]);
            } else if (tokens[row2][i].str[0] == '-') {
                if (i != l && tokens[row2][i - 1].type != 3) { // 不是负号
                    position = i;
                    Token v1 = eval(l,position - 1,row2);
                    Token v2 = eval(position + 1,r,row2);
                    return meetValue(v1,v2,tokens[row2][position].str[0]);
                }
            }
        }
        for (int i = r; i > l; i--) { //再找 / *
            int cnt1 = 0;
            if (tokens[row2][i].str[0] == ')') { // 跳过括号里的运算符
                cnt1++;
                i--;
                while (cnt1 != 0) {
                    if (tokens[row2][i].str[0] == ')') {
                        cnt1++;
                    } else if (tokens[row2][i].str[0] == '(') {
                        cnt1--;
                    }
                    i--;
                    if (i == r) {
                        break;
                    }
                }
            }
            if (tokens[row2][i].str[0] == '*' || tokens[row2][i].str[0] == '/') {
                position = i;
                Token v1 = eval(l,position - 1,row2);
                Token v2 = eval(position + 1,r,row2);
                return meetValue(v1,v2,tokens[row2][position].str[0]);
            }
        }
        v.type = 5; // 没找到主运算符
    }
    return v;
}

Token evalAssign(int l, int r, int row4) { // 处理赋值语句
    Token ret;
    int find = 0; // 是否存在‘=’
    for (int i = l; i <= r; ++i) {
        if (tokens[row4][i + 1].str[0] == '=' && (i == l || tokens[row4][i - 1].str[0] == '=')) { // ‘&&’后的条件是为了处理“a = b  +c = 1"的情况
            find = 1;
            if (tokens[row4][i].type == 1) { // 对变量进行赋值
                Token temp = evalAssign(i + 2, r, row4);
                for (int j = 0; j < cnt; ++j) { // 检查是否是对已赋值的变量再次赋值
                    if (strcmp(tokens[row4][i].str, F[j].str) == 0) {
                        F[j].status = true;
                        if (temp.type != 5) { // 正确的赋值
                            F[j].type = temp.type;
                            F[j].ival = temp.ival;
                            F[j].fval = temp.fval;
                            return F[j];
                        } else {
                            return temp;
                        }
                    }
                }
                F[cnt].status = true; // 对新变量进行赋值
                strcpy(F[cnt].str, tokens[row4][i].str);
                F[cnt].type = temp.type;
                F[cnt].ival = temp.ival;
                F[cnt++].fval = temp.fval;
                return F[cnt - 1];
            } else { // 对不知道什么玩意进行赋值
                ret.type = 5;
            }
        }
    }
    if (find == 0) { // 不是一个赋值语句
        return eval(l,r,row4);
    }
    return ret;
}

Token meetValue(Token v1,Token v2,char op) {
    Token ret;
    if (v1.type == 5 || v2.type == 5) {
        ret.type = 5;
    } else if ((v1.type != v2.type) || (v1.type == 4 && v2.type == 4)) { // 有浮点型
        ret.type = 4;
        if (v1.type == 2) {
            v1.fval = (float) v1.ival;
        }
        if (v2.type == 2) {
            v2.fval = (float) v2.ival;
        }
        if (op == '+') ret.fval = v1.fval + v2.fval;
        if (op == '-') ret.fval = v1.fval - v2.fval;
        if (op == '*') ret.fval = v1.fval * v2.fval;
        if (op == '/') ret.fval = v1.fval / v2.fval;
    } else {
        ret.type = 2;
        if (op == '+') ret.ival = v1.ival + v2.ival;
        if (op == '-') ret.ival = v1.ival - v2.ival;
        if (op == '*') ret.ival = v1.ival * v2.ival;
        if (op == '/') ret.ival = v1.ival / v2.ival;
    }
    return ret;
}

void printValue(Token v1) { // 输出函数
    switch (v1.type) {
        case 5: printf("Error\n");
            break;
        case 2: printf("%d\n", v1.ival);
            break;
        case 4: printf("%f\n", v1.fval);
            break;
    }
}

void judge(const char *a,int number) {
    size_t len = strlen(a);
    char *t1 = strchr(a,'.');

    if (*a == '+' || *a == '-' || *a == '*' || *a == '/' || *a == '=') {
        tokens[row][number].type = 3; // 运算符
    } else if (*a == '(' || *a == ')') {
        tokens[row][number].type = 6;
        return;
    } else if (*a == '_' || (*a >= 'A' && *a <= 'Z') || (*a >= 'a' && *a <= 'z')) {
        if (len == 1) { // 变量
            tokens[row][number].type = 1;
        } else {
            for (int i = 1; i < len; ++i) {
                if (!(*(a + i) == '_' || (*(a + i) >= 'A' && *(a + i) <= 'Z') ||
                      (*(a + i) >= 'a' && *(a + i) <= 'z') ||
                      (*(a + i) >= '0' && *(a + i) <= '9'))) {
                    break;
                }
                if (i == len - 1) {
                    tokens[row][number].type = 1;
                }
            }
        }
    } else if (t1 != NULL) { // 浮点型
        char *t3 = strchr(t1 + 1, '.');
        if (*a == '0' && *(a + 1) == '0') {
            Row[row] = 1;
        } else if (*a != '.' && *(a + len - 1) != '.' && t3 == NULL) { // 第一个和最后一个都不是小数点并且只有一个小数点
            for (int i = 0; i < len; ++i) {
                if (!((*(a + i) >= '0' && *(a + i) <= '9') || *(a + i) == '.')) {
                    break;
                }
                if (i == len - 1) {
                    tokens[row][number].type = 4;
                }
            }
        } else {
            Row[row] = 1;
        }
    } else if (t1 == NULL) { // 整型
        if (*a != '0') {
            for (int i = 0; i < len; ++i) {
                if (!((*(a + i) >= '0' && *(a + i) <= '9') || *(a + i) == '.')) {
                    break;
                }
                if (i == len - 1) {
                    tokens[row][number].type = 2;
                }
            }
        } else {
            Row[row] = 1;
        }
    }
}