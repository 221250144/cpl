


#include <stdio.h>
#include <string.h>

int cnt = 1;
int num = 0;
int mem[10005];
int ids[10005];
void append(int id, int m){
    int _m = m, num = 0;
    while((1<<num)<m) num++;
    m = 1<<num;
    int aim = 0, aim2 = -1, flag = 0;
    for(int i=0; i<cnt; i++){
        if(ids[i] == 0){
            if(mem[i] == m){
                aim = i;
                flag = 1; //鍖归厤鎴愬姛
                break;
            }
            else if(mem[i] > m && aim2 == -1) {
                aim2 = i;
            }
        }
    }
    if(flag == 1){
        ids[aim] = id;
    }
    else{
        for(int i = cnt; i > aim2+1; i--){
            mem[i] = mem[i-1];
            ids[i] = ids[i-1];
        }
        cnt++;
        mem[aim2] >>= 1;
        mem[aim2+1] = mem[aim2];
        ids[aim2 + 1] = 0;
        append(id, _m);
    }
}
void query(){
    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++){
        printf("%d ", ids[i]);
    }
    printf("\n");
}
int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    mem[0] = 1<<n;
    for(int i=0; i<q; i++){
        char c = '\n';
        while(c == '\n'){
            scanf("%c", &c);
        }
        if(c == 'A'){
            int id, m;
            scanf("%d %d", &id, &m);
            append(id, m);
        }
        else if(c == 'Q') query();
    }
    return 0;
}