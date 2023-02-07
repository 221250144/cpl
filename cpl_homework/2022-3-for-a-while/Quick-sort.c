#include<stdio.h>
int a[1000000] = {0};

int main()
{
    int n = 0;
    int k = 0;

    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
    }

    int t = 0;
    int mid = a[k];
    for (int l = 1,r = n;l < r;) {
        if(a[l] < mid){
            l++;
        }
        if(a[l] >= mid && a[r] >= mid) {
            r--;
        }
        if(a[l] >= mid && a[r] < mid) {
            t = a[l];
            a[l] = a[r];
            a[r] = t;
            l++;
            r--;
        }
    }
    int cnt = 0;
    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if(a[i] == mid){
            p = i;
            break;
        }
    }
    for (int i = p - 1;i > 0;i--) {
        if(a[i] > mid){
            cnt++;
        }
    }
    t = a[p];
    a[p] = a[p - cnt];
    a[p - cnt] = t;

    for (int i = 1; i <= n; ++i) {
        printf("%d ",a[i]);
    }

    return 0;
}