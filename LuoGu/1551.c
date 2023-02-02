#include <stdio.h>

#define N 5005

int fa[N],depth[N];

void init(int n) ;
int find(int num) ;
void merge(int i,int j) ;

int main()
{
    int n = 0;
    int m = 0;
    int p = 0;
    scanf("%d%d%d",&n,&m,&p);
    init(n);
    int m1 = 0;
    int m2 = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&m1,&m2);
        merge(m1,m2);
    }
    for (int i = 0; i < p; ++i) {
        scanf("%d%d",&m1,&m2);
        if (find(m1) == find(m2)) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}

void init(int n) {
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
        depth[i] = 0;
    }
}

int find(int num) {
    if (fa[num] == num) {
        return num;
    }
    fa[num] = find(fa[num]);
    return fa[num];
}

void merge(int i,int j) {
    int x = find(i);
    int y = find(j);
    if (depth[x] >= depth[y]) {
        fa[y] = fa[x];
    } else {
        fa[x] = fa[y];
    }
    if (depth[x] == depth[y]) {
        depth[y]++;
    }
}