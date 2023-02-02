#include <stdio.h>
#include <string.h>

int main() {
    char str[105] = {0};
    scanf("%s", str);
    int len = strlen(str);
    int num[105] = {0};
    for (int i = 0; i < len; ++i) { // 桶计数法
        if (str[i] == 'J') num[59]++;
        else if (str[i] == 'Q') num[60]++;
        else if (str[i] == 'K') num[61]++;
        else if (str[i] == 'A') num[62]++;
        else if (str[i] == '1' && str[i + 1] == '0') {
            num[58]++;
            i++;
        } else num[str[i]]++;
    }

    int cnt[105] = {0}; // 这步好像多余了。。。。（ 用来判断是否出现两个及以上
    for (int i = 51; i <= 62; ++i) {
        if (num[i] >= 2) {
            cnt[i] = 1;
        }
    }
    int lens[15][20] = {0}; //判断每个连续连对的开始和结束位置
    int a[15] = {0}; // 每个连对的长度
    int t = 0;
    for (int i = 51; i <= 62; i++) {
        if (cnt[i]) { // 开始位置
            lens[t][0] = i;
            while (cnt[i] && i <= 62) {
                i++;
                lens[t][1] = i; // 结束位置
            }
            a[t] = lens[t][1] - lens[t][0];
            t++;
        }
    }
    int max = 0; // 最长的连对
    for (int i = 0; i < t; ++i) {
        if (a[i] > a[max]) max = i;
    }
    for (int i = lens[max][0]; i < lens[max][1]; ++i) { // 输出
        if (i == 58) printf("1010");
        else if (i == 59) printf("JJ");
        else if (i == 60) printf("QQ");
        else if (i == 61) printf("KK");
        else if (i == 62) printf("AA");
        else printf("%c%c", i, i);
    }

    return 0;
}