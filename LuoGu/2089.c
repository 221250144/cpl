#include <stdio.h>

int main()
{
    int a = 0;
    scanf("%d",&a);
    if (a < 10 || a > 30) {
        printf("0");
        return 0;
    }

    long long cnt = 0;
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            for (int k = 1; k < 4; ++k) {
                for (int l = 1; l < 4; ++l) {
                    for (int m = 1; m < 4; ++m) {
                        for (int n = 1; n < 4; ++n) {
                            for (int o = 1; o < 4; ++o) {
                                for (int p = 1; p < 4; ++p) {
                                    for (int q = 1; q < 4; ++q) {
                                        for (int r = 1; r < 4; ++r) {
                                            if (i + j + k + l + m + n + o + p + q + r == a) {
                                                cnt++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%lld\n",cnt);

    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            for (int k = 1; k < 4; ++k) {
                for (int l = 1; l < 4; ++l) {
                    for (int m = 1; m < 4; ++m) {
                        for (int n = 1; n < 4; ++n) {
                            for (int o = 1; o < 4; ++o) {
                                for (int p = 1; p < 4; ++p) {
                                    for (int q = 1; q < 4; ++q) {
                                        for (int r = 1; r < 4; ++r) {
                                            if (i + j + k + l + m + n + o + p + q + r == a) {
                                                printf("%d %d %d %d %d %d %d %d %d %d\n",i,j,k,l,m,n,o,p,q,r);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}