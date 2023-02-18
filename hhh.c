#include <stdio.h>
#include <stdlib.h>

int a[100] = {0};

void merge(int l,int r,int mid) {
    int size = r - l + 1;
    int *b = (int*) malloc(size * sizeof (int));
    for (int i = 0,j = l; i < size; i++,j++) {
        b[i] = a[j];
    }

    int ll = l;
    int rr = mid + 1;
    int cnt = 0;
    while (ll <= mid && rr <= r) {
        if (a[ll] < a[rr]) {
            b[cnt++] = a[ll++];
        } else {
            b[cnt++] = a[rr++];
        }
    }

    while (ll <= mid) {
        b[cnt++] = a[ll++];
    }

    while (rr <= r) {
        b[cnt++] = a[rr++];
    }

    for (int i = 0,j = l; i < size; i++,j++) {
        a[j] = b[i];
    }

    free(b);
}

void mergesort(int l,int r) {
    if (l >= r) {
        return;
    }

    int mid = (l + r) / 2;
    mergesort(l,mid);
    mergesort(mid + 1,r);

    merge(l,r,mid);
}

int main () {
    int i = 0;
    while (scanf("%d",&a[i++]) != EOF);

    mergesort(0,i - 2);

    for (int j = 0; j < i - 1; ++j) {
        printf("%d ",a[j]);
    }

    return 0;
}