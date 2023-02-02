#include <stdio.h>

typedef struct {
    char name[10];
    int Chinese;
    int Math;
    int English;
    int sum;
} Student;
Student S[1005];

int main()
{
    int n = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d%d", S[i].name, &S[i].C, &S[i].M, &S[i].E);
        S[i].sum = S[i].C + S[i].M + S[i].E;
    }
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (S[max].sum < S[i].sum) {
            max = i;
        }
    }

    printf("%s %d %d %d", S[max].name, S[max].C, S[max].M, S[max].E);

    return 0;
}