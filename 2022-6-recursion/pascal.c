#include<stdio.h>

int Pascal(int x, int y);

int main() {
    int a = 0;
    int b = 0;
    scanf("%d%d", &a, &b);

    printf("%d", Pascal(a - 1, b - 1));
}

int Pascal(int x, int y) {
    if (x == 0 || x == y) {
        return 1;
    } else {
        return Pascal(x - 1, y - 1) + Pascal(x - 1, y);
    }
}

//#include<stdio.h>
//
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d%d",&a,&b);
//
//    int triangle[40][40] = {{},
//                            {0,1},
//                            {0,1,1}};
//
//    for (int i = 3; i < 40; ++i) {
//        for (int j = 1; j < i + 1; ++j) {
//            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
//        }
//    }
//
//    printf("%d",triangle[a][b]);
//
//    return 0;
//}