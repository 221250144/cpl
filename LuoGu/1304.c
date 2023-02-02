#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int sum;
    int n1;
    int n2;
    bool status;
} Jia;
Jia a[10005] ;

void find(int v) ;
bool Is_Prime(int number) ;

int main ()
{
    int N = 0;
    scanf("%d",&N);
    for (int i = 4; i <= N; ++i) {
        if (i % 2 == 0) {
            a[i].sum = i;
            find(i);
            if (a[i].status == 1) {
                printf("%d=%d+%d\n", a[i].sum, a[i].n1, a[i].n2);
            }
        }
    }
    return 0;
}

bool Is_Prime(int number) {
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void find(int v) {
    for (int i = 2; i <= a[v].sum / 2; ++i) {
        a[v].n1 = i;
        a[v].n2 = a[v].sum - i;
        if (Is_Prime(a[v].n1) == true && Is_Prime(a[v].n2) == true) {
            a[v].status = true;
            break;
        }
    }
}