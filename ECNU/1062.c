#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000002];
char a[1000002];
int n,m;
int res[500002];
int res2[500002];

int cmp(const void* a, const void* b)   // 排序函数，通过s中的距离开头为a的字符串与为b的字符串之间的比较来对数组res进行排序
{
    int* pa = (int*) a;
    int* pb = (int*) b;
    return strcmp(s + *pa, s + *pb);
}

int main()
{
    m = 1;
    while(scanf("%s", a) != EOF)
    {
        res[++n] = m;                 //数组的第二个元素初始化为1，n可以记录输入字符串的个数
        int t = strlen(a);        //字符串长度
        for(int i = 0; i < t; i++)
            s[m + i] = a[i];           //将字符串a中的每个元素存入s中
        m += t + 1;                    //通过m记录该字符串在s中的位置，方便下面排序，同时+1是为了中间空出一个0来分割字符串
    }

    qsort(res + 1, n, sizeof(int), cmp);  //排序

    res2[1] = 1;                                         //处理出现次数的数组
    for(int i = 2; i <= n; i++)
    {
        if(strcmp(s + res[i - 1], s + res[i]) == 0)      //判断第i-1和第i个字符串是否相同
        {
            res2[i] = res2[i - 1];                       //如果一样的话将第i-1个数组的位置改为0，方便与下面输出的时候选择性输出
            res2[i - 1] = 0;
        }
        ++res2[i];                                       //无论一不一样都+1，如果不一样就是从0变1表示只出现了一次
    }

    for(int i = 1; i <= n; i++)
        if(res2[i])
            printf("%s %d\n", s + res[i], res2[i]);

    return 0;
}