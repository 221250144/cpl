#include <stdio.h>

int a[1000005] = {0};
int ans[1000005] = {0};

int main ()
{
    int n = 0;
    scanf("%d",&n);

    int position = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
        if (a[i] == 2) {
            position = i;
        }
    }
    ans[position] = 1;
    if (a[position + 1] == 0) {
        ans[position + 1] = 1;
    }
    if (a[position - 1] == 0) {
        ans[position - 1] = 1;
    }
    for (int i = position + 1; i < n - 1;) {
        if (a[i] == 1 && a[i + 1] == 0) {
            ans[i + 1] = 1;
            i += 2;
        } else {
            break;
        }
    }
    for (int i = position - 1; i > 0;) {
        if (a[i] == 1 && a[i - 1] == 0) {
            ans[i - 1] = 1;
            i -= 2;
        } else {
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ",ans[i]);
    }

    return 0;
}