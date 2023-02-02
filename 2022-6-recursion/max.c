#include<stdio.h>

int ans[100005][2] = {0};
int begin[100005] = {0};

int max(int a[],int l,int r)
{
    int max = l;
    for (int i = l; i <= r; ++i) {
        if(a[i] > a[max]) {
            max = i;
        }
    }
    return max;
}

void maxseg(int a[],int answer[][2],int l,int r)
{
    if (l <= r) {
        int q = max(a, l, r);
        answer[q][0] = l;
        answer[q][1] = r;

        maxseg(begin, ans, l, q - 1);
        maxseg(begin, ans, q + 1, r);
    }
}

int main()
{
    int n = 0;
    scanf("%d",&n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d",&begin[i]);
    }

    maxseg(begin,ans,1,n);

    for (int i = 1; i <= n; ++i) {
        printf("%d %d\n",ans[i][0],ans[i][1]);
    }

    return 0;
}