#include <stdio.h>

void Swap (int *a,int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Merge(int *arr, int l,int mid,int r) { // 归并排序
    int size = r - l + 1;
    int copy[size];
    for (int i = l,j = 0; i <= r; i++,j++) {
        copy[j] = arr[i];
    }

    int left_index = l;
    int right_index = mid + 1;
    int copy_index = 0;

    while (left_index <= mid && right_index <= r) {
        if (arr[left_index] < arr[right_index]) {
            copy[copy_index++] = arr[left_index++];
        } else {
            copy[copy_index++] = arr[right_index++];
        }
    }

    while (left_index < mid) {
        copy[copy_index++] = arr[left_index++];
    }
    while (right_index < r) {
        copy[copy_index++] = arr[right_index++];
    }

    for (int i = l,j = 0; i <= r; i++,j++) {
        arr[i] = copy[j];
    }
}

void Print(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void StraightSort(int *arr, int len) { // 插入排序
    int tmp,j;
    for (int i = 1; i < len; i++) {
        tmp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > tmp; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;
    }
}

void MergeSort(int *arr,int l,int r) {
    if (l == r) {
        return;
    }

    int mid = (l + r) / 2;
    MergeSort(arr,l,mid);
    MergeSort(arr,mid + 1,r);

    Merge(arr,l,mid,r);
}

void BubbleSort (int *arr,int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                Swap(&arr[j],&arr[j + 1]);
            }
        }
    }
}

void SelectSort (int *arr,int len) {
    for (int i = 0; i < len - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        Swap(&arr[i],&arr[min]);
    }
}

int main () {
    int a[10] = {9,5,7,3,5,6,1,4,7,65};
    //StraightSort(a,10);
    MergeSort(a,0,9);
    //BubbleSort(a,10);
    //SelectSort(a,10);

    Print(a,10);

    return 0;
}
