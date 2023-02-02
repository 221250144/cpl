#include<stdio.h>
#define NUM 1000005

int main() {
    int n = 0;
    int a[NUM] = {0};
    int b[NUM] = {0};

    scanf("%d", &n);
    for (int j = 0; j < 2 * n - 1; j++) {
        scanf("%d", &a[j]);
    }

    for ( int i = 0; i < 2 * n - 1; i++) {
        b[a[i]]++;
    }
    int k = 0;
    do {
        if (b[k] == 1) {
            printf("%d", k);
        }
        k++;
    }while(k <= 10*n);

    return 0;
}
