#include <stdio.h>

int a[1000005] = {0};

int search(int key,int l,int r) {
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] == key) {
            return mid;
        } else if (a[mid] > key) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (a[l] == key) {
        return l;
    }
    return -1;
}

int main () {
    int n = 0;
    int q = 0;
    scanf("%d%d",&n,&q);

    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    while (q--) {
        int t = 0;
        scanf("%d",&t);
        printf("%d\n",search(t,0,n - 1));
    }

    return 0;
}