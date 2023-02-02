#include <stdio.h>
#include <math.h>

void change(int n,int x,int y);

int people[1025][1025] = {0};

int main()
{
    int n = 0;
    scanf("%d",&n);

    change(n,0,0);
    for (int i = 0; i < pow(2,n); ++i) {
        for (int j = 0; j < pow(2,n); ++j) {
            printf("%d ",people[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void change(int n,int x,int y) {
    if (n == 1) {
        people[x + 1][y] = 1;
        people[x][y + 1] = 1;
        people[x + 1][y + 1] = 1;
        return;
    }
    change(n - 1, x + pow(2,n - 1),y);
    change(n - 1, x,y + pow(2,n - 1));
    change(n - 1, x + pow(2,n - 1), y + pow(2,n - 1));
}