#include <stdio.h>

typedef struct {
    int status;
    char name[15];
} Toy ;
Toy a[100005];

typedef struct {
    int diction;
    int number;
} Order ;
Order b[100005];

int main()
{
    int n = 0;
    int m = 0;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%s",&a[i].status,a[i].name);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&b[i].diction,&b[i].number);
    }

    int position = 0;
    for (int i = 0; i < m; ++i) {
        if (a[position].status != b[i].diction) {
            position += b[i].number;
            while (position >= n) {
                position -= n;
            }
        } else {
            position -= b[i].number;
            while (position < 0) {
                position += n;
            }
        }
    }

    printf("%s",a[position].name);

    return 0;
}