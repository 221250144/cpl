#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    int staff;
    struct node *next;
    struct node *before;
} Node;
Node *a[100005];

void Append(int number,int staff,int position) ;
Node *find(int position) ;
int find2(int position,int num) ;

int main()
{
    int n = 0;
    int q = 0;
    scanf("%d%d",&n,&q);

    int type = 0;
    for (int i = 0; i < q; ++i) {
        scanf("%d",&type);
        if (type == 1) {
            int temp[3] = {0};
            scanf("%d%d%d",&temp[0],&temp[1],&temp[2]);
            Append(temp[1],temp[2],temp[0]);
        } else {
            int temp[2] = {0};
            scanf("%d%d",&temp[0],&temp[1]);
            printf("%d", find2(temp[0],temp[1]));
        }
    }

    return 0;
}

Node *find(int position) {
    Node *node = a[position];
    while (node->next != NULL) {
        node = node->next;
    }
    return node;
}

void Append(int number,int staff,int position) {
    if (staff == 0) {
        if (a[position]->before == NULL) {
            a[position] = NULL;
        } else {
            Node *node = find(position);
            node->before->next = node->next;
        }
    } else {
        if (a[position] == NULL) {
            Node *node = malloc(sizeof *node);
            node->next = NULL;
            node->before = NULL;
            node->staff = staff;
            node->number = number;
            a[position] = node;
        } else {
            Node *node = find(position);
            Node *ret = malloc(sizeof *ret);
            ret->staff = staff;
            ret->number = number;
            ret->before = node;
            node->next = ret;
        }
    }
}

int find2(int position,int num) {
    Node *node = a[position];
    while (node->number != num) {
        node = node->next;
    }
    return node->staff;
}