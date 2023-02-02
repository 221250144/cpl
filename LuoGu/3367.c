#include <stdio.h>

int f[10005] = {0};
int dep[10005] = {0};

int find(int i) {
    if (f[i] == i) {
        return i;
    }
    return f[i] = find(f[i]);
}

void merge(int a,int b) {
    int x = find(a);
    int y = find(b);
    if (dep[x] >= dep[y]) {
        f[y] = f[x];
    } else {
        f[x] = f[y];
    }
    if (dep[x] == dep[y]) {
        dep[x]++;
    }
}

void init(int n) {
    for (int i = 0; i < n; ++i) {
        f[i] = i;
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    for (int i = 0; i < m; ++i) {
        int z,x,y;
        scanf("%d%d%d",&z,&x,&y);
        if (z == 1) {
            merge(x,y);
        } else {
            if (find(x) == find(y)) {
                printf("Y\n");
            } else {
                printf("N\n");
            }
        }
    }

    return 0;
}