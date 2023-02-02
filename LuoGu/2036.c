#include <stdio.h>
#include <math.h>

int min = 999999999;
int n = 0;
int s[15] = {0};
int b[15] = {0};

void dfs(int i,int x,int y) {
    if (i == n) {
        if (x == 1 && y == 0) {
            return;
        }
        min = min < abs(x - y) ? min : abs(x - y);
        return;
    }
    dfs(i + 1,x * s[i],y + b[i]);
    dfs(i + 1,x,y);
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&s[i],&b[i]);
    }
    dfs(0,1,0);
    printf("%d",min);

    return 0;
}