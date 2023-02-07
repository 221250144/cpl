#include<stdio.h>

int main() {
    int a[9][9] = {0};
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    int true = 1;
    for (int i = 0; i < 9; ++i) {
        int cnt = 0;
        for (int k = 1; k <= 9; ++k) {
            for (int j = 0; j < 9; ++j) {
                if (a[i][j] == k) {
                    cnt++;
                    break;
                }
            }
        }
        if (cnt != 9) {
            true = 0;
            break;
        }
    }
    //列

    if (true == 1) {
        for (int j = 0; j < 9; ++j) {
            int cnt = 0;
            for (int k = 1; k <= 9; ++k) {
                for (int i = 0; i < 9; ++i) {
                    if (a[i][j] == k) {
                        cnt++;
                        break;
                    }
                }
            }
            if (cnt != 9) {
                true = 0;
                break;
            }
        }
    }
    //行

    if (true == 1) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (i % 3 == 1 && j % 3 == 1) {
                    int cnt = 0;
                    for (int k = 1; k <= 9; ++k) {
                        int t = cnt;
                        for (int p = i - 1; p <= i + 1; ++p) {
                            for (int q = j - 1; q <= j + 1; ++q) {
                                if (a[p][q] == k) {
                                    cnt++;
                                    break;
                                }
                                if(cnt != t){
                                    break;
                                }
                            }
                        }
                    }
                    if (cnt != 9) {
                        true = 0;
                        break;
                    }
                }
            }
        }
    }
    if (true == 1) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
