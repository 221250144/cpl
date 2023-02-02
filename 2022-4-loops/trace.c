#include<stdio.h>

int main() {
    int n = 0;
    int m = 0;
    int x = 0;
    int y = 0;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    int cnt = 0;
    char a[100][100] = {0};
    int b[100][100] = {0};
    char ch;
    char t = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%c", &t);
        for (int j = 1; j <= m; ++j) {
            ch = getchar();
            if (ch != '\n') {
                a[i][j] = ch;
                if (ch == '#') {
                    cnt++;
                }
            }
        }
    }

    printf("%d\n%d% d\n", cnt, x, y);

    b[x][y] = 1;
    int count = cnt;
    while (count > 1) {
        if (a[x - 1][y] == '#' && b[x - 1][y] != 1) {
            printf("%d %d\n", x - 1, y);
            b[x - 1][y] = 1;
            x = x - 1;
        } else if (a[x + 1][y] == '#' && b[x + 1][y] != 1) {
            printf("%d %d\n", x + 1, y);
            b[x + 1][y] = 1;
            x = x + 1;
        } else if (a[x][y - 1] == '#' && b[x][y - 1] != 1) {
            printf("%d %d\n", x, y - 1);
            b[x][y - 1] = 1;
            y = y - 1;
        } else if (a[x][y + 1] == '#' && b[x][y + 1] != 1) {
            printf("%d %d\n", x, y + 1);
            b[x][y + 1] = 1;
            y = y + 1;
        }
        count--;
    }

    return 0;
}