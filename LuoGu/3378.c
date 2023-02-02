#include <stdio.h>

int heap[1000005] = {0};
int size = 0;

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Min_Heap(int num) {
    if (num > size / 2) {
        return;
    }
    int l = heap[num * 2];
    int r = heap[num * 2 + 1];

    int min, k;
    if (l > r && num * 2 + 1 <= size) {
        min = r;
        k = num * 2 + 1;
    } else {
        min = l;
        k = num * 2;
    }
    if (heap[num] > min) {
        Swap(&heap[num], &heap[k]);
        Min_Heap(k);
    }
}

void maintain() {
    for (int i = size / 2; i >= 1; i--) {
        Min_Heap(i);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &heap[++size]);
            int tem = size;
            while (tem != 1 && heap[tem / 2] > heap[tem]) {
                Swap(&heap[tem / 2], &heap[tem]);
                tem /= 2;
            }
        } else if (op == 2) {
            printf("%d\n", heap[1]);
        } else {
            heap[1] = heap[size];
            heap[size] = 0;
            size--;
            maintain();
        }
    }

    return 0;
}