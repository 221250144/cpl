#include<stdio.h>
#include<math.h>

long long Link[10000000] = {1};
long long ans[10000000] = {0};
int Number_of_link = 1;
int count = 0;
int n = 0;

int Length(int number) {   //第number个链的长度
    int cnt = 0;
    int begin;
    for (int i = 0;; ++i) {
        if (Link[i] == 1) {
            cnt++;
            if (cnt == number) {
                begin = i;
                break;
            }
        }
    }
    for (int i = begin + 1;; ++i) {
        if (Link[i] == 1) {
            return i - begin;
        }
    }
}


int Find(int id,int m) {
    for (int i = 1; i <= Number_of_link; ++i) {  //找到正好合适的链
        if (Length(i) == m) {
            ans[count++] = id;
            return 0;
        }
    }
    for (int i = 1; i <= Number_of_link; ++i) {    //找到大一点的链并拆成两个小的
        int cnt = 0;
        if (Length(i) > m) {
            for (int j = 0;; ++j) {
                if (Link[j] == 1) {
                    cnt++;
                    if (cnt == i) {
                        Link[j + Length(i) / 2] = 1;
                        break;
                    }
                }
            }
            Number_of_link++;
            break;
        }
    }
    Find(id,m);
}

int main()
{
    int q = 0;
    scanf("%d%d",&n,&q);
    int t = pow(2,n);
    Link[t] = 1;
    int cnt = q;
    char Read[10005] = {0};
    for (int i = 0; i < cnt; ++i) {
        scanf("%s",&Read[i]);
        if (Read[i] == 'A') {
            cnt += 2;
        }
    }
    for (int i = 0; i < cnt; ++i) {
        if (Read[i] == 'A') {
            Find(Read[i + 1] - 48,Read[i + 2] - 48);
        }
        if (Read[i] == 'Q') {
            printf("%d\n",Number_of_link);
            for (int j = 0; j < Number_of_link; ++j) {
                printf("%lld ",ans[j]);
            }
            printf("\n");
        }
    }

    return 0;
}