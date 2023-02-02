#include <stdio.h>

int n = 0;
int m = 0;
int a[105][25] = {0};

void min(int nums[]);
void max(int nums[]);

int main ()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d",&a[i][j]);
        }
        min(a[i]);
        max(a[i]);
    }
    double average[105] = {0};
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += a[i][j];
        }
        average[i] = sum * 1.0 / (m - 2);
    }

    double max = average[0];
    for (int i = 0; i < n; ++i) {
        if (max < average[i]) {
            max = average[i];
        }
    }
    printf("%.2f",max);

    return 0;
}

void min(int nums[]) {
    int min = 0;
    for (int i = 0; i < m; ++i) {
        if (nums[min] > nums[i]) {
            min = i;
        }
    }
    nums[min] = 0;
}

void max(int nums[]) {
    int max = 0;
    for (int i = 0; i < m; ++i) {
        if (nums[max] < nums[i]) {
            max = i;
        }
    }
    nums[max] = 0;
}