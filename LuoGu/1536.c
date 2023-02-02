#include <stdio.h>

int fa[1005] = {0};
int dep[1005] = {0};

void init(int num) {
    for (int i = 1; i <= num; ++i) {
        fa[i] = i;
        dep[i] = 0;
    }
}

int find(int i) {
    if (fa[i] == i) {
        return i;
    }
    return fa[i] = find(fa[i]);
}

void merge(int a,int b) {
    int x = find(a);
    int y = find(b);
    if (dep[x] >= dep[y]) {
        fa[y] = fa[x];
    } else {
        fa[x] = fa[y];
    }
    if(dep[x] == dep[y]) {
        dep[x]++;
        dep[y]++;
    }
}

int main()
{
    int n,m;
    while (1) {
        scanf("%d",&n);
        if (n == 0) {
            break;
        }
        scanf("%d",&m);
        init(n);
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            int x,y;
            scanf("%d%d",&x,&y);
            merge(x,y);
        }
        for (int i = 1; i <= n; ++i) {
            if (fa[i] == i) {
                ans++;
            }
        }
        printf("%d\n",ans - 1);
    }

    return 0;
}