#include <stdio.h>

int n = 0;
int m = 0;
int a[1000005] = {0};

int search(int key) {
    int l = 1;
    int r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] >= key) {
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
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
    }

    int key = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d",&key);
        printf("%d ", search(key));
    }

    return 0;
}