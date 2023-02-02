#include<stdio.h>

int num[15], book[15], n;

void print() {
    int i;
    for (i = 1; i <= n; i++)
        printf("%5d", num[i]);
    printf("\n");
}

void search(int step) {
    int i;
    if (step > n)
        print();
    for (i = 1; i <= n; i++) {
        if (book[i] == 0) {
            book[i] = 1;
            num[step] = i;
            search(step + 1);
            book[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    int step = 1;
    search(step);
    return 0;
}