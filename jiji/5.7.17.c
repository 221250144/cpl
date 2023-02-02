#include<stdio.h>

int main()
{
    int s0 = 0;
    int i = 0;
    int n = 0;
    int t = 0;
    int o = 0;

    scanf("%d%d%d%d%d",&s0,&i,&n,&t,&o);

    if (s0 == 0) {
        if (o == i) {
            printf("1");
        } else {
            printf("0");
        }
    }

    if (s0 == 1) {
        if (o == n) {
            printf("2");
        } else if (o == i) {
            printf("1");
        } else {
            printf("0");
        }
    }

    if (s0 == 2) {
        if (o == i) {
            printf("1");
        } else if (o == t) {
            printf("3");
        } else {
            printf("0");
        }
    }

    if (s0 == 3) {
        if (o == i) {
            printf("1");
        } else {
            printf("0");
        }
    }

    return 0;
}