#include<stdio.h>

int c[50][3] = {0};
char paint[50][100][100] = {0};

void DrawA(int cnt) //画+-
{
    int i = 1;
    for (int j = 2 * c[cnt][1] + 1, count = 0; count <= 2 * c[cnt][0] + 1; ++j) {
        count++;
        if (j % 2 == 1) {
            paint[cnt][i][j] = '+';
        } else {
            paint[cnt][i][j] = '-';
        }
        if ((count == 2 * c[cnt][0] + 1) && j != count) {
            j = j - count - 2;
            count = 0;
            i += 2;
        }
        if ((count == 2 * c[cnt][0] + 1) && j == count) {
            j = 0;
            count = 0;
            i += 2;
        }
        if (i == 2 * c[cnt][1] + 2 * c[cnt][2] + 3) {
            break;
        }
    }
}

void DrawB(int cnt)     //画”/“
{
    int i = 2;
    for (int j = 2 * c[cnt][1],count = 0; count <= 2 * c[cnt][0] + 1; j++) {
        count++;
        if (j % 2 != 1) {
            paint[cnt][i][j] = '/';
        }
        if ((count == 2 * c[cnt][0] + 1) && j != count) {
            j = j - count - 2;
            count = 0;
            i += 2;
        }
        if ((count == 2 * c[cnt][0] + 1) && j == count) {
            j = 0;
            count = 0;
            i += 2;
        }
        if (i == 2 * c[cnt][1] + 2) {
            break;
        }
    }
}

void DrawC(int cnt)   //画”|“
{
    int i = 2 * c[cnt][1] + 2;
    for (int j = 1,count = 0; count <= 2 * c[cnt][0] + 1; j++) {
        count++;
        if (j % 2 == 1) {
            paint[cnt][i][j] = '|';
        }
        if (count == 2 * c[cnt][0] + 1) {
            j = 0;
            i += 2;
            count = 0;
        }
        if (i == 2 * c[cnt][1] + 2 * c[cnt][2] + 4) {
            break;
        }
    }
}

void DrawD(int cnt)  //画右边的”|“
{
    int i = 1;
    for (int j = 2 * c[cnt][0] + 2 * c[cnt][1] + 1,count = 0;;i++) {
        count++;
        if (i % 2 == 1) {
            paint[cnt][i][j] = '+';
        } else {
            paint[cnt][i][j] = '|';
        }
        if (i == 2 * c[cnt][1] + 2 * c[cnt][2] - 1) {
            break;
        }
        if (count == 2 * c[cnt][2] + 1) {
            i = i - count + 2;
            j -= 2;
            count = 0;
        }
    }
}

void DrawE(int cnt)      //画”|“后面的”\“
{
    int i = 2;
    for (int j = 2 * c[cnt][0] + 2 * c[cnt][1],count = 0;;i++) {
        count++;
        if (i % 2 != 1) {
            paint[cnt][i][j] = '/';
        }
        if (i == 2 * c[cnt][1] + 2 * c[cnt][2]) {
            break;
        }
        if (count == 2 * c[cnt][2] + 1) {
            i = i - count + 2;
            j -= 2;
            count = 0;
        }
    }
}
int main()
{
    int T = 0;
    scanf("%d",&T);

    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d",&c[i][j]);
        }
    }

    for (int i = 0; i < T; ++i) {
        DrawA(i);
        DrawB(i);
        DrawC(i);
        DrawD(i);
        DrawE(i);

        for (int j = 1; j <= 2 * c[i][1] + 2 * c[i][2] + 1; ++j) {
            for (int k = 1; k <= 2 * c[i][0] + 2 * c[i][1] + 1; ++k) {
                if (paint[i][j][k] != '\0') {
                    printf("%c",paint[i][j][k]);
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}