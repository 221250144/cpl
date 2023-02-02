#include <stdio.h>

int fa[10005] = {0};
int d[10005] = {0};

void init(int num) {
    for (int i = 1; i <= num; ++i) {
        fa[i] = i;
    }
}

int find(int num) {
    if (num == fa[num]) {
        return num;
    }
    return fa[num] = find(fa[num]);
}

void merge(int a,int b) {
    fa[find(a)] = find(b);
}

int max(int a,int b) {
    return a > b ? a : b;
}

void dfs(int sum,int num,const int w[],const int v[]) {
    for (int i = 1; i <= num; ++i) {
        for (int j = sum; j >= w[i]; j--) {
            d[j] = max(d[j],d[j - w[i]] + v[i]);
        }
    }
}

int main()
{
    int n,m,w;
    scanf("%d%d%d",&n,&m,&w);

    int W[10005] = {0};
    int V[10005] = {0};
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d",&W[i],&V[i]);
    }

    init(n);
    for (int i = 0; i < m; ++i) {
        int x,y;
        scanf("%d%d",&x,&y);
        merge(x,y);
    }

    for (int i = 1; i <= n; ++i) {
        int tem = find(i);
        if (tem != i) {
            W[tem] += W[i];
            V[tem] += V[i];
            W[i] = 0;
            V[i] = 0;
        }
    }

    int end_w[10005] = {0};
    int end_v[10005] = {0};
    int cnt = 1;
    for (int i = 1; i <= n; ++i) {
        if (W[i] != 0) {
            end_w[cnt] = W[i];
            end_v[cnt] = V[i];
            cnt++;
        }
    }

    dfs(w,cnt - 1,end_w,end_v);
    printf("%d",d[w]);

    return 0;
}