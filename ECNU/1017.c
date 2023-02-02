#include <stdio.h>

int main()
{
    typedef struct {
        long long num;
        int grade;
    } Student ;
    Student a[105];

    int n = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%d",&a[i].num,&a[i].grade);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (a[j].grade < a[j + 1].grade) {
                Student temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int begin = i;
        while (a[i].grade == a[i + 1].grade) {
            i++;
        }
        for (int j = begin; j <= i; ++j) {
            for (int k = begin; k <= i - 1; ++k) {
                if (a[k].num > a[k + 1].num) {
                        Student temp;
                        temp = a[k];
                        a[k] = a[k + 1];
                        a[k + 1] = temp;
                    }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i].grade >= 60) {
            printf("%lld %d\n", a[i].num, a[i].grade);
        } else {
            break;
        }
    }

    return 0;
}