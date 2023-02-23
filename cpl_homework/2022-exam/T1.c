#include <stdio.h>

int main() {
    int t = 0;
    scanf("%d", &t);

    while (t--) {
        int n = 0;
        scanf("%d", &n);
        int a[50005] = {0};
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n - i - 2; j++) {
//            if (a[j] > a[j + 1]) {
//                int tmp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = tmp;
//            }
//        }
//    }


        int judge = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > a[n - 1]) {
                printf("No\n");
                judge = 1;
                break;
            }
        }
        if (judge == 0) {
            printf("Yes\n");
        }

    }
    return 0;
}