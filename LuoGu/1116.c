#include <stdio.h>

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int N = 0;
    scanf("%d",&N);
    int a[100005] = {0};
    for (int i = 0; i < N; ++i) {
        scanf("%d",&a[i]);
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 1 - i; ++j) {
            if (a[j] > a[j + 1]) {
                swap(&a[j],&a[j + 1]);
                cnt++;
            }
        }
    }

    printf("%d",cnt);

    return 0;
}