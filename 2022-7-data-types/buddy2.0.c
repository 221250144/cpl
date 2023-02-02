#include<stdio.h>
#include<math.h>

long long Link[100000000] = {0};
long long ans[100000000] = {0};
int Number_of_link = 1;

int Tow(int number) {
    for (int i = 0; i <= 30; ++i) {
        if (number <= pow(2,i) && number > pow(2,i - 1)) {
            return pow(2,i);
        }
    }
}

int Find(int id, int m) {
    int temp = Tow(m);
    for (int i = 0; i < Number_of_link; ++i) {
        if (Link[i] == temp && ans[i] == 0) {
            ans[i] = id;
            return 0;
        }
    }

    for (int i = 0; i < Number_of_link; ++i) {
        if (Link[i] > temp && ans[i] == 0) {
            for (int j = Number_of_link; j > i; j--) {
                if (j - i > 1) {
                    Link[j] = Link[j - 1];
                    ans[j] = ans[j - 1];
                } else {
                    Link[j] = Link[i] / 2;
                    ans[j] = 0;
                    Link[j - 1] = Link[i] / 2;
                }
            }
            Number_of_link++;
            break;
        }
    }
    Find(id, m);
    return 0;
}

int main(void) {
    int n = 0;
    int q = 0;
    scanf("%d%d", &n, &q);
    Link[0] = pow(2, n);
    char Read1[30005] = {0};
    int Read2[30005] = {0};
    char ch;
    int cnt = q;
    for (int i = 0; i < cnt; ++i) {
        scanf("%s",&ch);
        if (ch == 'A' || ch == 'Q') {
            Read1[i] = ch;
            if (ch == 'A') {
                scanf("%d%d", &Read2[i + 1], &Read2[i + 2]);
                i += 2;
                cnt += 2;
            }
        }
    }
    for (int i = 0; i < cnt; ++i) {
        if (Read1[i] == 'A') {
            Find(Read2[i + 1],Read2[i + 2]);
        }
        if (Read1[i] == 'Q') {
            printf("%d\n",Number_of_link);
            for (int j = 0; j < Number_of_link; ++j) {
                printf("%lld ",ans[j]);
            }
            printf("\n");
        }
    }

    return 0;
}