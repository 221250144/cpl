#include<stdio.h>
#include<math.h>

char triangle[100000][100000];

void paint(int n, int x, int y)
{
    if (n == 1) {
        triangle[x][y] = '/';
        triangle[x + 1][y] = '\\';
        triangle[x - 1][y + 1] = '/';
        triangle[x][y + 1] = '_';
        triangle[x + 1][y + 1] = '_';
        triangle[x + 2][y + 1] = '\\';
    } else {
        paint(n - 1,x,y);
        paint(n - 1,x - pow(2,n - 1),y + pow(2,n - 1));
        paint(n - 1,x + pow(2,n - 1),y + pow(2,n - 1));
    }
}
int main()
{
    int n = 0;
    scanf("%d",&n);

    for (int j = 1; j <= pow(2,n); ++j) {
        for (int i = 1; i <= pow(2,n + 1); ++i) {
            triangle[i][j] = ' ';
        }
    }
    paint(n,pow(2,n),1);
    for (int j = 1; j <= pow(2,n); ++j) {
        for (int i = 1; i <= pow(2,n + 1); ++i) {
            printf("%c",triangle[i][j]);
        }
        printf("\n");
    }
    return 0;
}