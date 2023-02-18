#include <stdio.h>

int main () {
    int t = 0;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i) {
        char map[21][21] = {0};
        for (int j = 0; j < 20; ++j) {
            scanf("%s",map[j]);
        }

        int cnt_white = 0;
        int cnt_bleak = 0;
        for (int j = 0; j < 20; ++j) {
            for (int k = 0; k < 20; ++k) {
                if (map[j][k] == '_') {

                    int l1 = 0;
                    for (int l = j + 1; l <= j + 4; ++l) {
                        if (l < 20 && l >= 0 && map[l][k] == '#') {
                            l1++;
                        } else {
                            break;
                        }
                    }
                    int l2 = 0;
                    for (int l = j - 1; l >= j - 4; l--) {
                        if (l < 20 && l >= 0 && map[l][k] == '#') {
                            l2++;
                        } else {
                            break;
                        }
                    }
                    if (l1 + l2 >= 4) {
                        cnt_white++;
                    }


                    int l3 = 0;
                    for (int l = k + 1; l <= k + 4; ++l) {
                        if (l < 20 && l >= 0 && map[j][l] == '#') {
                            l3++;
                        } else {
                            break;
                        }
                    }
                    int l4 = 0;
                    for (int l = k - 1; l >= k - 4; l--) {
                        if (l < 20 && l >= 0 && map[j][l] == '#') {
                            l4++;
                        } else {
                            break;
                        }
                    }
                    if (l3 + l4 >= 4) {
                        cnt_white++;
                    }


                    int l5 = 0;
                    for (int l = j + 1,m = k + 1; l <= j + 4; ++l,m++) {
                        if (l < 20 && l >= 0 && m < 20 && m >= 0 && map[l][m] == '#') {
                            l5++;
                        } else {
                            break;
                        }
                    }
                    int l6 = 0;
                    for (int l = j - 1,m = k - 1; l >= j - 4; l--,m--) {
                        if (l < 20 && l >= 0 && m >= 0 && m < 20 && map[l][m] == '#') {
                            l6++;
                        } else {
                            break;
                        }
                    }
                    if (l5 + l6 >= 4) {
                        cnt_white++;
                    }



                    int l7 = 0;
                    for (int l = j + 1,m = k - 1; l <= j + 4; ++l,m--) {
                        if (l < 20 && l >= 0 && m < 20 && m >= 0 && map[l][m] == '#') {
                            l7++;
                        } else {
                            break;
                        }
                    }
                    int l8 = 0;
                    for (int l = j - 1,m = k + 1; l >= j - 4; l--,m++) {
                        if (l < 20 && l >= 0 && m >= 0 && m < 20 && map[l][m] == '#') {
                            l8++;
                        } else {
                            break;
                        }
                    }
                    if (l7 + l8 >= 4) {
                        cnt_white++;
                    }

                    l1 = 0;
                    for (int l = j + 1; l <= j + 4; ++l) {
                        if (l < 20 && l >= 0 && map[l][k] == '*') {
                            l1++;
                        } else {
                            break;
                        }
                    }
                    l2 = 0;
                    for (int l = j - 1; l >= j - 4; l--) {
                        if (l < 20 && l >= 0 && map[l][k] == '*') {
                            l2++;
                        } else {
                            break;
                        }
                    }
                    if (l1 + l2 >= 4) {
                        cnt_bleak++;
                    }


                    l3 = 0;
                    for (int l = k + 1; l <= k + 4; ++l) {
                        if (l < 20 && l >= 0 && map[j][l] == '*') {
                            l3++;
                        } else {
                            break;
                        }
                    }
                    l4 = 0;
                    for (int l = k - 1; l >= k - 4; l--) {
                        if (l < 20 && l >= 0 && map[j][l] == '*') {
                            l4++;
                        } else {
                            break;
                        }
                    }
                    if (l3 + l4 >= 4) {
                        cnt_bleak++;
                    }


                    l5 = 0;
                    for (int l = j + 1,m = k + 1; l <= j + 4; ++l,m++) {
                        if (l < 20 && l >= 0 && m < 20 && m >= 0 && map[l][m] == '*') {
                            l5++;
                        } else {
                            break;
                        }
                    }
                    l6 = 0;
                    for (int l = j - 1,m = k - 1; l >= j - 4; l--,m--) {
                        if (l < 20 && l >= 0 && m >= 0 && m < 20 && map[l][m] == '*') {
                            l6++;
                        } else {
                            break;
                        }
                    }
                    if (l5 + l6 >= 4) {
                        cnt_bleak++;
                    }



                    l7 = 0;
                    for (int l = j + 1,m = k - 1; l <= j + 4; ++l,m--) {
                        if (l < 20 && l >= 0 && m < 20 && m >= 0 && map[l][m] == '*') {
                            l7++;
                        } else {
                            break;
                        }
                    }
                    l8 = 0;
                    for (int l = j - 1,m = k + 1; l >= j - 4; l--,m++) {
                        if (l < 20 && l >= 0 && m >= 0 && m < 20&& map[l][m] == '*') {
                            l8++;
                        } else {
                            break;
                        }
                    }
                    if (l7 + l8 >= 4) {
                        cnt_bleak++;
                    }
                }
            }
        }

        if (cnt_bleak >= 1) {
            printf("Lose\n");
        } else if (cnt_white >= 2) {
            printf("Win\n");
        } else {
            printf("Not Sure\n");
        }
    }

    return 0;
}