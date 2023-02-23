#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 2000

typedef struct node {
    char str[SIZE];
    int size;
    struct node *next;
} Node;
Node *head;

void Init (Node *node) {
    node->size = 0;
    node->next = NULL;
    memset(node->str,0,SIZE);
}

void Insert (int index,char *s) {
    Node *tmp = head;
    while (index >= tmp->size) {
        index -= tmp->size;
        tmp = tmp->next;
    }

    Node *node = (Node*) malloc(sizeof (Node));
    Init(node);
    strncpy(node->str,tmp->str + index,tmp->size - index);
    memset(tmp->str + index,0,tmp->size - index);

    size_t len = strlen(s);
    int t = 0;
    while (t < len / SIZE - 1) {
        Node *t1 = (Node*) malloc(sizeof (Node));
        Init(t1);
        strncpy(t1->str,s + SIZE * t,SIZE);
        t1->size = SIZE;
        tmp->next = t1;
        if (len / SIZE >= 1) {
            tmp = t1;
        }
        t++;
    }
    if (len % SIZE != 0 && len / SIZE >= 1) {
        Node *t2 = (Node*) malloc(sizeof (Node));
        Init(t2);
        t2->size = len % SIZE;
        strncpy(t2->str,s + SIZE * t,len % SIZE);
        tmp->next = t2;
    }

    if (tmp->next->size + node->size <= SIZE) {
        strncpy(tmp->next->str + tmp->next->size,node->str,node->size);
    } else if (len <= SIZE && len + tmp->size <= SIZE) {

    }

//    if (size <= SIZE) {
//        Node *node = (Node*) malloc(sizeof (Node));
//        Init(node);
//        strncpy(node->str,s,size);
//        node->size = size;
//    }
}

char Query (int index) {
    Node *tmp = head;
    while (index >= tmp->size) {
        index -= tmp->size;
        tmp = tmp->next;
    }
    return tmp->str[index];
}

int main () {
    int n = 0;
    int q = 0;
    char str[100005] = {0};
    scanf("%d%d%s",&n,&q,str);
    getchar();
    head = (Node*) malloc(sizeof (Node));
    strncpy(head->str,str,SIZE);

    Node *tmp = head;
    int t = 1;
    while (t < n / SIZE) {
        Node *node = (Node*) malloc(sizeof (Node));
        Init(node);
        strncpy(node->str,str + SIZE * t,SIZE);
        node->size = SIZE;
        tmp->next = node;
        tmp = node;
        t++;
    }
    if (n % SIZE != 0 && n / SIZE >= 1) {
        Node *node = (Node*) malloc(sizeof (Node));
        Init(node);
        node->size = n % SIZE;
        strncpy(node->str,str + SIZE * t,n % SIZE);
        tmp->next = node;
    }

    while (q--) {
        char type = 0;
        scanf("%c",&type);
        if (type == 'Q') {
            int index = 0;
            scanf("%d",&index);
            printf("%c\n",Query(index - 1));
        } else {
            int index = 0;
            char s[100005] = {0};
            scanf("%d%s",&index,s);
            Insert(index,s);
        }
        getchar();
    }

    return 0;
}