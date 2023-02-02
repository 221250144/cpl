#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef struct {
    char name[10];
    int C;
    int M;
    int E;
    int sum;
} Student;
Student S[1005];

bool judge(Student a,Student b) ;

int main()
{
    int n = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d%d", S[i].name, &S[i].C, &S[i].M, &S[i].E);
        S[i].sum = S[i].C + S[i].M + S[i].E;
    }

    for (int i = 0,j = 1; i < n - 1;j++) {
        if (judge(S[i],S[j]) == true) {
            if (strcmp(S[i].name,S[j].name) == 1) {
                printf("%s %s\n",S[j].name,S[i].name);
            } else {
                printf("%s %s\n",S[i].name,S[j].name);
            }
        }
        if (j == n - 1) {
            i++;
            j = i;
        }
    }

    return 0;
}

bool judge(Student a,Student b) {
    if (abs(a.C - b.C) <= 5 && abs(a.M - b.M) <= 5 && abs(a.E - b.E) <= 5 && abs(a.sum - b.sum) <= 10) {
        return true;
    }
    return false;
}