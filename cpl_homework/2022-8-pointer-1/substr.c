#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *S1 = malloc(100005 * sizeof(*S1));
    memset(S1 , 0 , 100005 * sizeof(*S1));
    char *S2 = malloc(100005 * sizeof(*S2));
    memset(S2 , 0 , 100005 * sizeof(*S2));
    int *T1 = malloc(100005 * sizeof(*T1));
    memset(T1 , 0 , 100005 * sizeof(*T1));
    char *T2 = malloc(100005 * sizeof(*T2));
    memset(T2 , 0 , 100005 * sizeof(*T2));

    char ch = 0;
    int cntS = 0;
    int cntT = 0;
    for (int i = 0; ; ++i) {
        scanf("%c",&ch);
        if (ch != '\n') {
            cntS++;
            if (ch >= 48 && ch <= 57) {
                *(S1 + i) = ch - 48;
            } else {
                *(S2 + i) = ch;
            }
        } else {
            break;
        }
    }
    for (int i = 0; ; ++i) {
        scanf("%c",&ch);
        if (ch != '\n') {
            cntT++;
            if (ch >= 48 && ch <= 57) {
                *(T1 + i) = ch - 48;
            } else {
                *(T2 + i) = ch;
            }
        } else {
            break;
        }
    }


    for (int k = 0; k <= cntS - cntT; k++) {
        int true = 1;
        int temp = k;
        for (int i = k,j = 0; j < cntT; i++,j++) {
            if (*(S1 + i) != *(T1 + j) || *(S2 + i) != *(T2 + j)) {
                true = 0;
                break;
            }
        }
        if (true == 1) {
            printf("%d ",temp);
        }
    }

    free(S1);
    free(S2);
    free(T1);
    free(T2);
    return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//    char *Student = malloc(100005 * sizeof(*Student));
//    char *T = malloc(100005 * sizeof(*T));
//    gets(Student);
//    gets(T);
//    int cntS = strlen(Student);
//    int cntT = strlen(T);
//    for (int k = 0; k <= cntS - cntT; k++) {
//        int true = 1;
//        int temp = k;
//        for (int i = k,j = 0; i < cntT + k; i++,j++) {
//            if (*(Student + i) != *(T + j)) {
//                true = 0;
//                break;
//            }
//        }
//        if (true == 1) {
//            printf("%d ",temp);
//        }
//    }
//
//    free(Student);
//    free(T);
//    return 0;
//}