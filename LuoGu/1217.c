#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool Is_Prime(long long int number) ;

int main()
{
    long long int min = 0;
    long long int max = 0;
    scanf("%lld%lld",&min,&max);

    for (int i = 5; i <= 9;i += 2) {
        if (i >= min && i <= max) {
            if (Is_Prime(i) == true) {
                printf("%d\n",i);
            }
        }
    }

    for (int i = 1; i <= 9; i += 2) {
        int m = i * 10 + i;
        if (m >= min && m <= max) {
            if (Is_Prime(m) == true) {
                printf("%d\n",m);
            }
        }
    }

    for (int i = 1; i <= 9; i += 2) {
        for (int j = 0; j <= 9; ++j) {
            int m = i * 100 + j * 10 + i;
            if (m >= min && m <= max) {
                if (Is_Prime(m) == true) {
                    printf("%d\n",m);
                }
            }
        }
    }

    for (int i = 1; i <= 9; i += 2) {
        for (int j = 0; j <= 9; ++j) {
            int m = i * 1000 + j * 100 + j * 10 + i;
            if (m >= min && m <= max) {
                if (Is_Prime(m) == true) {
                    printf("%d\n",m);
                }
            }
        }
    }


    for (int i = 1; i <= 9; i += 2) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                int m = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
                if (m >= min && m <= max) {
                    if (Is_Prime(m) == true) {
                        printf("%d\n",m);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 9; i += 2) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                int m = i * 100000 + j * 10000 + k * 1000 + k * 100 + j * 10 + i;
                if (m >= min && m <= max) {
                    if (Is_Prime(m) == true) {
                        printf("%d\n",m);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 9; i += 2) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                for (int l = 0; l <= 9; ++l) {
                    int m = i * 1000000 + j * 100000 + k * 10000 + l * 1000 + k * 100 + j * 10 + i;
                    if (m >= min && m <= max) {
                        if (Is_Prime(m) == true) {
                            printf("%d\n",m);
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 9; i += 2) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                for (int l = 0; l <= 9; ++l) {
                    int m = i * 10000000 + j * 1000000 + k * 100000 + l * 10000 + l * 1000 + k * 100 + j * 10 + i;
                    if (m >= min && m <= max) {
                        if (Is_Prime(m) == true) {
                            printf("%d\n",m);
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 9; i += 2) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                for (int l = 0; l <= 9; ++l) {
                    for (int m = 0; m <= 9; ++m) {
                        long long int p = i * 100000000 + j * 10000000 + k * 1000000 + l * 100000 + m * 10000 + l * 1000 + k * 100 + j * 10 + i;
                        if (p >= min && p <= max) {
                            if (Is_Prime(p) == true) {
                                printf("%lld\n",p);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

bool Is_Prime(long long int number) {
    for (int i = 2; i <= sqrt( number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}