#include <stdio.h>

typedef struct {
    int number;
    int g1;
    int g2;
    int sum;
    int sum1;
} Student;
Student S[1005];

int main()
{
    int n = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d",&S[i].number,&S[i].g1,&S[i].g2);
        S[i].sum1 = S[i].g1 * 7 + S[i].g2 * 3;
        S[i].sum = S[i].g1 + S[i].g2;
        if (S[i].sum > 140 && S[i].sum1 >= 800) {
            printf("Excellent\n");
        } else {
            printf("Not excellent\n");
        }
    }

    return 0;
}
