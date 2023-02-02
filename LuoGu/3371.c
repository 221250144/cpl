#include <stdio.h>
#include <stdbool.h>

#define INF 2147483647

typedef struct {
    bool state;
    int dist;
} DOT;
DOT dot[10005];

typedef struct {
    int start;
    int end;
    int val;
} EDGE;
EDGE edge[500005];

int main() {
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);

    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d",&edge[i].start,&edge[i].end,&edge[i].val);
    }

    int S[10005] = {0};
    int U[10005] = {0};

    for (int i = 1; i <= n; ++i) {
        S[i] = -1;
        U[i] = INF;
    }

    S[s] = 0;
    int temp = m;
    while (temp--) {
        U[s] = -1;
        int min = INF;
        int k = s;
        int t[10005] = {0};
        for (int i = 1; i <= m; ++i) {
            if (edge[i].start == k) {
                if (U[edge[i].end] != INF) {
                    t[edge[i].end] = U[edge[i].end];
                }
                U[edge[i].end] = edge[i].val;
                if (min > edge[i].val) {
                    min = edge[i].val;
                    s = edge[i].end;
                }
            }
        }
        S[s] = (U[s] + S[k]) < t[s] ? (U[s] + S[k]) : t[s];
        U[s] = -1;
        for (int i = 1; i <= n; ++i) {
            int tem = (U[i] == INF ? INF : U[i] + min);
            if (i != s && U[i] != -1) {
                U[i] = tem;
            }
        }
        if (min == INF) {
            for (int i = 1; i <= n; ++i) {
                printf("%d ",U[i] == -1 ? S[i] : U[i]);
            }
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ",S[i]);
    }

    return 0;
}