#include <stdio.h>

int main()
{
    int word[100005][3] = {0};
    int N = 0;
    int K = 0;
    scanf("%d%d",&N,&K);

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d",&word[i][j]);
        }
    }

    int cnt = 0;
    for (int i = 0; i < K; ++i) {
        if (word[i][1] > N || word[i][2] > N || word[i][1] == word[i][2]) {
            cnt++;
        } else {

        }
    }

    return 0;
}