#include <stdio.h>

int a[5000005] = {0};

int Qsort(int l, int r) {
    int i = l;
    int j = r;
    int key = a[i];
    while (i < j) {
        while (a[j] >= key && i < j) {
            j--;
        }
        a[i] = a[j];
        while (a[i] <= key && i < j) {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = key;
    return i;
}

int find(int l,int r,int k) {
    int temp = Qsort(l,r);
    if (temp == k) {
        return a[k];
    }
    if (temp > k) {
        return find(l,temp - 1,k);
    } else {
        return find(temp + 1,r,k);
    }
}

int main()
{
    int n = 0;
    int m = 0;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }

    printf("%d", find(0,n - 1,m));

    return 0;
}