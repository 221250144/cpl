#include<stdio.h>

int main()
{
    int a[11] = {1,9,6,3,4,85,94,63,21,65};

    for (int i = 1; i < 10; ++i) {
        int temp = a[i];
        int j = 0;
        for (j = i - 1; a[j] > temp && j >= 0; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
    for (int i = 0; i < 10; ++i) {
       printf("%d ",a[i]);
    }

    return 0;
}