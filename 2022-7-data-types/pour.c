#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int k, VA, VB, VC, a, b, c, a0, b0, c0;

void Pour(int *begin, int *end, int *V) {
    *end += *begin;
    *begin = 0;
    if (*end > *V) {
        *end = *V;
    }
}

bool M() {
    if (a == a0 && b == b0 && c == c0) {
        return true;
    } else {
        return false;
    }
}

bool H(int cnt) {
    if (cnt == 0) {
        return false;
    }
    int a1 = a,b1 = b,c1 = c;

    Pour(&a, &b, &VB);
    if (M()) {
        printf("Yes");
        exit(0);
    } else {
        H(cnt - 1);
    }
    a = a1,b = b1,c = c1;

    Pour(&b, &a, &VA);
    if (M()) {
        printf("Yes");
        exit(0);
    } else {
        H(cnt - 1);
    }
    a = a1,b = b1,c = c1;

    Pour(&a, &c, &VC);
    if (M()) {
        printf("Yes");
        exit(0);
    } else {
        H(cnt - 1);
    }
    a = a1,b = b1,c = c1;

    Pour(&c, &a, &VA);
    if (M()) {
        printf("Yes");
        exit(0);
    } else {
        H(cnt - 1);
    }
    a = a1,b = b1,c = c1;

    Pour(&b, &c, &VC);
    if (M()) {
        printf("Yes");
        exit(0);
    } else {
        H(cnt - 1);
    }
    a = a1,b = b1,c = c1;

    Pour(&c, &b, &VB);
    if (M()) {
        printf("Yes");
        exit(0);
    } else {
        H(cnt - 1);
    }
    a = a1,b = b1,c = c1;

    return false;
}

int main() {
    scanf("%d%d%d%d%d%d%d%d%d%d", &k, &VA, &VB, &VC, &a, &b, &c, &a0, &b0, &c0);

    if (a == a0 && b == b0 && c == c0) {
        printf("Yes");
        exit(0);
    }
    H(k);
    printf("No");

    return 0;
}