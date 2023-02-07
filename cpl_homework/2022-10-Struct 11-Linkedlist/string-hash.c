#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 60000

typedef struct node {
    char name[1005];
    struct node *next;
} Node;
Node *a[60005];

bool judge(char *name,int position) ;
int hash(char *s) ;
void Append(char *name,int position) ;
Node *find(int position) ;

int main()
{
    int m = 0;
    int q = 0;
    scanf("%d%d",&m,&q);
    char str[1005] = {0};
    for (int i = 0; i < m; ++i) {
        scanf("%s",str);
        Append(str, hash(str));
    }
    for (int i = 0; i < q; ++i) {
        scanf("%s",str);
        if (judge(str, hash(str)) == true) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}

int hash(char *s) {
    size_t len = strlen(s);
    int ret = 0;
    for (int i = 0; i < len; i++) {
        ret = (ret + s[i] * (i + 1)) % N;
    }
    return ret;
}

Node *find(int position) {
    Node *node = a[position];
    while (node->next != NULL) {
        node = node->next;
    }
    return node;
}

void Append(char *name,int position) {
    if (a[position] == NULL) {
        Node *node = malloc(sizeof *node);
        node->next = NULL;
        strcpy(node->name,name);
        a[position] = node;
    } else {
        Node *node = find(position);
        Node *ret = malloc(sizeof *ret);
        strcpy(ret->name, name);
        node->next = ret;
    }
}

bool judge(char *name,int position) {
    Node *node = a[position];
    while (node != NULL) {
        if (strcmp(name,node->name) == 0) {
            return true;
        }
        node = node->next;
    }
    return false;
}