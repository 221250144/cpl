#include <stdio.h>
#include <string.h>
#include <math.h>

int E[100000][2];
int T[100000][2];

void End (const char str[], long long lens,int M[][2],int number,int *cnt)
{
    int cntW = 0;
    int cntL = 0;
    for (int i = 1,j = 1; i <= lens; ++i) {
        if (str[i] == 'W'){
            cntW++;
        } else {
            cntL++;
        }
        if (((cntW >= number || cntL >= number) && abs(cntW - cntL) >= 2) || i == lens) {
            M[j][0] = cntW;
            M[j][1] = cntL;
            cntL = 0;
            cntW = 0;
            j++;
            *cnt += 1;
        }
    }
}

int main()
{
    char ch;
    char string[100000] = {0};
    string[0] = '0';

    for (int i = 1; ; ++i) {
        scanf("%c",&ch);
        if (ch != 'E' && ch != '\n') {
            string[i] = ch;
        } else if (ch == 'E'){
            break;
        } else if (ch == '\n') {
            i--;
        }
    }

    long long len = strlen(string);
    int cnt1 = 0;
    int cnt2 = 0;

    End(string,len - 1,E,11,&cnt1);
    End(string,len - 1,T,21,&cnt2);

    for (int i = 1; i <= cnt1; ++i) {
        printf("%d:%d\n",E[i][0],E[i][1]);
    }
    printf("\n");
    for (int i = 1; i <= cnt2; ++i) {
        printf("%d:%d\n",T[i][0],T[i][1]);
    }

    return 0;
}