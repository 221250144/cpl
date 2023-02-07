#include<stdio.h>

int find(int x,const int b[]) ;

int main()
{
    int n = 0;
    scanf("%d",&n);

    int a[100005];
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
    }

    int f[10005] = {0};
    for (int i = 1; i <= n; ++i) {
        f[i] = find(i,a);
        printf("%d ",f[i]);
    }

    return 0;
}

int find(int x,const int b[])
{
    if (x == b[x]) {
        return x;
    } else {
        return find(b[x],b);
    }
}