#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int ans[50005] = {0};

bool judge(const int a[],const int b[],int lens_B) ;
void sub(int a[],const int b[],int lens_B,int position) ;

int main()
{
    char a[50005] = {0};
    char b[50005] = {0};
    scanf("%s%s",a,b);

    size_t cntA = strlen(a);
    size_t cntB = strlen(b);

    int A[50005] = {0};
    int B[50005] = {0};
    for (int i = 0; i < cntA; ++i) {
        A[i] = a[i] - '0';
    }
    for (int i = 0; i < cntB; ++i) {
        B[i] = b[i] - '0';
    }

    for (int i = 0; i <= cntA - cntB; ++i) {
        while (judge(A + i,B,cntB) == 1) {
            sub(A + i,B,cntB,i + cntB - 1);
        }
        A[i + 1] += A[i] * 10;
    }

    int i = 0;
    for (; ans[i] == 0 && i != cntA - 1; ++i) ;
    while (i < cntA) {
        printf("%d",ans[i]);
        i++;
    }

    return 0;
}

bool judge(const int a[],const int b[],int lens_B) {
    for (int i = 0; i < lens_B; ++i) {
        if (a[i] > b[i]) return true;
        if (a[i] < b[i]) return false;
    }
    return true;
}

void sub(int a[], const int b[], int lens_B, int position) {
    for (int i = 0; i < lens_B; ++i) {
        a[i] -= b[i];
    }
    for (int i = lens_B - 1; i > 0; i--) {
        if (a[i] < 0) {
            a[i] += 10;
            a[i - 1]--;
        }
    }
    ans[position]++;
}