#include<stdio.h>
#include<math.h>

int main()
{
    int len = 0;
    int N = 0;
    scanf("%d%d",&len,&N);
    int number = 1;
    int sum = 0;

    char a[1000] = {0};
    char h = 0;
    for(int i = -1;i < len;i++){
        if((h = getchar()) != '\n'){
            a[i] = h;
        }
    }
    int b[1000] = {0};

    for (int i = 0; i < len; ++i) {
        if(a[i] <= 57 && a[i] >= 48) {
            b[i] = a[i] - '0';
        } else {
            b[i] = a[i] - 'A' + 10;
        }
    }
    //读入字符串
    for (int i = 0; i <= len; ++i) {
        if(b[i]>= N){
            printf("Error");
            number = 0;
            break;
        }
    }
    //判断是否合法
    if(number == 1){
        for (int i = len - 1; i >= 0; i--) {
            sum += b[i] * pow(N,len - i - 1);
        }
        printf("%d",sum);
    }

    return 0;
}