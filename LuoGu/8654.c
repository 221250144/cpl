#include <stdio.h>

#define N 1000005

int fa[N];

void init(int n) ;
int find(int num) ;
void merge(int i,int j) ;

int main()
{
    int m,n,k;
    scanf("%d%d%d",&m,&n,&k);
    init(n * m);
    int x,y;
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &x, &y);
        merge(x,y);
    }
    int cnt = 0;
    for (int i = 0; i < n * m; ++i) {
        if (fa[i] == i) cnt++;
    }

    printf("%d",cnt);

    return 0;
}

void init(int n) {
    for (int i = 0; i < n ;++i) {
        fa[i] = i;
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
    fa[x] = fa[y];
}