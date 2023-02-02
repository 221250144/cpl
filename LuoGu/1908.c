#include <stdio.h>

long long a[500005] = {0};
long long ans = 0;

void merge_sort(int l, int r) ;
void Merge(int l,int r,int mid) ;

int main()
{
    int n = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld",&a[i]);
    }

    merge_sort(0,n - 1);
    printf("%lld",ans);
    return 0;
}

void merge_sort(int l, int r) {
    int mid = (l + r) / 2;
    if (l == r) {
        return;
    }

    merge_sort(l,mid);
    merge_sort(mid + 1,r);

    Merge(l,r,mid);
}

void Merge(int l,int r,int mid) {
    int size = r - l + 1;
    long long copy[size];
    for (int i = 0,j = l; i < size; i++,j++) {
        copy[i] = a[j];
    }
    int l_index = l;
    int r_index = mid + 1;
    int copy_index = 0;
    while (l_index <= mid && r_index <= r) {
        if (a[l_index] <= a[r_index]) {
            copy[copy_index++] = a[l_index++];
        } else {
            copy[copy_index++] = a[r_index++];
            ans += mid - l_index + 1;
        }
    }

    while (l_index <= mid) {
        copy[copy_index++] = a[l_index++];
    }
    while (r_index <= r) {
        copy[copy_index++] = a[r_index++];
    }

    for (int i = 0,j = l; i < size; ++i,j++) {
        a[j] = copy[i];
    }
}