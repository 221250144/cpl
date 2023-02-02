#include <stdio.h>

int n = 0;
int k = 0;
int count = 0;

int small_find(const int x[],const int y[],const int z[]) {
    for (int i = 0; i < k; ++i) {
        if (!((x[i] == y[i] && y[i] == z[i]) || (x[i] != y[i] && y[i] != z[i] && x[i] != z[i]))) {
            return 0;
        }
    }
    return 1;
}

void find(int a[],int b[],int c[],int d[],int e[]) {
    int x1 = small_find(a,b,c);
    int x2 = small_find(a,b,d);
    int x3 = small_find(a,b,e);
    int x4 = small_find(a,c,d);
    int x5 = small_find(a,c,e);
    int x6 = small_find(a,d,e);
    int x7 = small_find(b,c,d);
    int x8 = small_find(b,c,e);
    int x9 = small_find(b,d,e);
    int x10 = small_find(c,d,e);

    if ((x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10) >= 2) {
        count++;
    }
}



int main()
{
    scanf("%d%d",&n,&k);
    int a[75][7] = {0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i = 0,j = 1,l = 2,m = 3, p = 4;;) {
        find(a[i],a[j],a[l],a[m],a[p]);
        if (p == n - 1 && m == n - 2 && l == n - 3 && j == n - 4 && i == n - 5) {
            break;
        } else if (p == n - 1 && m == n - 2 && l == n - 3 && j == n - 4) {
            i++;
            j = i + 1;
            l = j + 1;
            m = l + 1;
            p = m + 1;
        } else if (p == n - 1 && m == n - 2 && l == n - 3) {
            j++;
            l = j + 1;
            m = l + 1;
            p = m + 1;
        } else if (p == n - 1 && m == n - 2) {
            l++;
            m = l + 1;
            p = m + 1;
        } else if (p == n - 1) {
            m++;
            p = m + 1;
        } else {
            p++;
        }
    }

    printf("%d",count);

    return 0;
}