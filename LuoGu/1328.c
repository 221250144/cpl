#include <stdio.h>

int main()
{
    int N = 0;
    int T1 = 0;
    int T2 = 0;
    scanf("%d%d%d",&N,&T1,&T2);

    int a[205] = {0};
    int b[205] = {0};
    for (int i = 0; i < T1; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < T2; ++i) {
        scanf("%d",&b[i]);
    }

    int score_a = 0;
    int score_b = 0;
    int cnt_a = -1;
    int cnt_b = -1;
    for (int i = 0; i < N; ++i) {
        cnt_a++;
        cnt_b++;
        if (cnt_a == T1) {
            cnt_a = 0;
        }
        if (cnt_b == T2) {
            cnt_b = 0;
        }
        if (a[cnt_a] == b[cnt_b]) {
            continue;
        } else if (a[cnt_a] == 0) {
            if (b[cnt_b] == 1 || b[cnt_b] == 4) {
                score_b++;
            } else {
                score_a++;
            }
        } else if (a[cnt_a] == 1) {
            if (b[cnt_b] == 2 || b[cnt_b] == 4) {
                score_b++;
            } else {
                score_a++;
            }
        } else if (a[cnt_a] == 2) {
            if (b[cnt_b] == 3 || b[cnt_b] == 0) {
                score_b++;
            } else {
                score_a++;
            }
        } else if (a[cnt_a] == 3) {
            if (b[cnt_b] == 0 || b[cnt_b] == 1) {
                score_b++;
            } else {
                score_a++;
            }
        } else {
            if (b[cnt_b] == 2 || b[cnt_b] == 3) {
                score_b++;
            } else {
                score_a++;
            }
        }
    }
    printf("%d %d",score_a,score_b);

    return 0;
}