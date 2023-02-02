#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool judge(const int a[],const int b[],int lens) ;
void Do(int a[], const int b[], int lens_B) ;
void plus(char *a,char *b) ;
void sub(char *a,char *b) ;
void mul(char *a,char *b) ;
void div(char *a,char *b) ;

int main()
{
    char a[10005] = {0};
    char b[10005] = {0};
    scanf("%s%s",a,b);

    plus(a,b);
    sub(a,b);
    mul(a,b);
    div(a,b);

    return 0;
}

bool judge(const int a[],const int b[],int lens) {
    for (int i = 0; i < lens; ++i) {
        if (a[i] > b[i]) return true;
        if (a[i] < b[i]) return false;
    }
    return true;
}

void Do(int a[], const int b[], int lens_B) {
    for (int i = 0; i < lens_B; ++i) {
        a[i] -= b[i];
    }
    for (int i = lens_B - 1; i > 0; i--) {
        if (a[i] < 0) {
            a[i] += 10;
            a[i - 1]--;
        }
    }

}

void sub(char *a,char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);

    int max = len_a > len_b ? len_a :len_b;
    int A[10005] = {0};
    int B[10005] = {0};
    for (int i = max - len_a,j = 0; j < len_a; i++,j++) {
        A[i] = a[j] - '0';
    }
    for (int i = max - len_b,j = 0; j < len_b; i++,j++) {
        B[i] = b[j] - '0';
    }

    int ans[10005] = {0};
    for (int i = 0; i < max; ++i) {
        ans[i] = A[i] - B[i];
    }

    bool temp = judge(A,B,max);
    if (temp == true) {
        for (int i = max - 1; i > 0; i--) {
            if (ans[i] < 0) {
                ans[i] += 10;
                ans[i - 1]--;
            }
        }
    } else {
        for (int i = max - 1; i > 0; i--) {
            if (ans[i] > 0) {
                ans[i] -= 10;
                ans[i - 1]++;
            }
        }
    }

    int i = 0;
    for (; ans[i] == 0 && i != max - 1; ++i) ;
    if (temp == true) {
        while (i < max) {
            printf("%d", ans[i]);
            i++;
        }
    } else {
        printf("-");
        while (i < max) {
            printf("%d", -ans[i]);
            i++;
        }
    }
    printf("\n");
}

void plus(char *a,char *b) {
    int cntA = strlen(a);
    int cntB = strlen(b);
    int A[505] = {0};
    int B[505] = {0};
    for (int i = 0; i < cntA; ++i) {
        A[i] = a[cntA - i - 1] - '0';
    }
    for (int i = 0; i < cntB; ++i) {
        B[i] = b[cntB - i - 1] - '0';
    }
    int max = cntA > cntB ? cntA : cntB;
    int sum[505] = {0};
    for (int i = 0; i <= max; ++i) {
        sum[i] += ( A[i] + B[i] );
        if (sum[i] > 9) {
            sum[i + 1]++;
            sum[i] %= 10;
        }
    }
    for (int i = 504;  ; i--) {
        if (sum[i] != 0) {
            max = i;
            break;
        }
        if (i == 0) {
            max = 0;
            break;
        }
    }
    for (int i = max; i >= 0; i--) {
        printf("%d",sum[i]);
    }
    printf("\n");
}

void mul(char *a,char *b) {
    int cntA = 0;
    int cntB = 0;
    for (int i = 2004;  ; i--) {
        if (a[i] != 0) {
            cntA = i;
            break;
        }
        if (i == 0) {
            cntA = 0;
            break;
        }
    }
    for (int i = 2004; ; i--) {
        if (b[i] != 0) {
            cntB = i;
            break;
        }
        if (i == 0) {
            cntB = 0;
            break;
        }
    }
    int A[2005] = {0};
    int B[2005] = {0};
    for (int i = 0; i <= cntA; ++i) {
        A[i] = a[cntA - i] - '0';
    }
    for (int i = 0; i <= cntB; ++i) {
        B[i] = b[cntB - i] - '0';
    }

    int product[5000] = {0};
    for (int i = 0; i <= cntA; ++i) {
        for (int j = 0; j <= cntB; ++j) {
            product[i + j] += ( A[i] * B[j] );
            while (product[i + j] > 9) {
                product[i + j + 1] += ( product[i + j] / 10 );
                product[i + j] %= 10;
            }
        }
    }

    int position = 0;
    for (int i = 4999; ; i--) {
        if (product[i] != 0) {
            position = i;
            break;
        }
        if (i == 0) {
            position = 0;
            break;
        }
    }

    for (int i = position; i >= 0; i--) {
        printf("%d",product[i]);
    }
    printf("\n");
}

void div(char *a,char *b) {
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

    int ans[10005] = {0};
    for (int i = 0; i <= cntA - cntB; ++i) {
        while (judge(A + i,B,cntB) == 1) {
            Do(A + i,B,cntB);
            ans[i + cntB - 1]++;
        }
        A[i + 1] += A[i] * 10;
    }

    int i = 0;
    for (; ans[i] == 0 && i != cntA - 1; ++i) ;
    while (i < cntA) {
        printf("%d",ans[i]);
        i++;
    }
    printf("\n");

    i = 0;
    for (; A[i] == 0 && i != cntA - 1; ++i) ;
    while (i < cntA) {
        printf("%d",A[i]);
        i++;
    }
}