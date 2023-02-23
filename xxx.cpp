#include<stdio.h>
#include <string.h>

int n,p;
int cnt=1;
int mem[10000];
int ids[10000];

void append(int id,int m){
    int num=0;
    while((1<<num)<m)num++;
    for(int i=0;i<cnt;i++){
        if(ids[i]!=0){
            if(num==mem[i]){
                ids[i]=id;
                break;
            }else if(num<mem[i]){
                for(int k=cnt;k>i+1;k--){
                    mem[k]=mem[k-1];
                    ids[k]=ids[k-1];
                }
                cnt++;
                mem[i+1]=1>>mem[i];
                mem[i]=mem[i+1];
                ids[i+1]=0;ids[i]=0;
                append(id,m);
            }
        }
    }
}

void quert(){
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        printf("%d",ids[i]);
    }
    printf("\n");
}

int main(){
    scanf("%d %d",&n,&p);
    int id,m;
    for(int i=0;i<p;i++){
        char s='\n';
        while(s=='\n'){
            scanf("%c",&s);}
        if(s=='A'){
            mem[0]=1<<n;
            scanf("%d %d",&id,&m);
            append(id,m);
        }else{
            quert();
        }
    }return 0;
}