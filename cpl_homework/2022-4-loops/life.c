#include<stdio.h>
#include<string.h>

int main()
{
    int n = 0;
    scanf("%d",&n);

    char begin[10001] = {0};
    scanf("%s",begin);
    int lens = strlen(begin);

    char extend[10001];
    memset(extend,'.',1000);

    for (int i = 0; i < lens; ++i) {
        extend[i + 3] = begin[i];
    }

    char end[10001] = {0};
    for (int i = 0; i < 10000; ++i) {
        end[i] = extend[i];
    }

    for (int round = 0; round < n; ++round) {
        for (int i = 3; i < lens + 3; ++i) {
            int cnt[1000] = {0};
            if (extend[i] == '.') {
                for (int j = i - 3; j <= i + 3; ++j) {
                    if (j == i) {
                        continue;
                    } else {
                        cnt[extend[j]]++;
                    }
                }
                if (cnt[65] >= 2 && cnt[65] <= 4 && cnt[66] == 0) {
                    end[i] = 'A';
                } else if (cnt[66] >= 2 && cnt[66] <= 4 && cnt[65] == 0) {
                    end[i] = 'B';
                }
            } else if (extend[i] == 'A') {
                for (int j = i - 3; j <= i + 3; ++j) {
                    if (j == i) {
                        continue;
                    } else {
                        cnt[extend[j]]++;
                    }
                }
                if (cnt[66] >= 1 || cnt[65] >= 5 || cnt[65] <= 1) {
                    end[i] = '.';
                }
            } else {
                for (int j = i - 3; j <= i + 3; ++j) {
                    if (j == i) {
                        continue;
                    } else {
                        cnt[extend[j]]++;
                    }
                }
                if (cnt[65] >= 1 || cnt[66] >= 5 || cnt[66] <= 1) {
                    end[i] = '.';
                }
            }
        }

        for (int i = 0; i < 10000; ++i) {
            extend[i] = end[i];
        }
    }

    for (int i = 3; i < lens + 3; ++i) {
        printf("%c",end[i]);
    }
    return 0;
}