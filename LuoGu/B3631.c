//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node {
//    int val;
//    struct node *next;
//} Node;
//
//Node *find(int num,Node *node) ;
//void Add(int num,Node *node) ;
//void Delete(int num,Node *node) ;
//
//int main()
//{
//    Node begin;
//    begin.next = NULL;
//    begin.val = 1;
//    int q = 0;
//    scanf("%d",&q);
//    for (int i = 0; i < q; ++i) {
//        int temp[2] = {0};
//        scanf("%d%d",&temp[0],&temp[1]);
//        if (temp[0] == 1) {
//            scanf("%d",&temp[0]);
//            Add(temp[0], find(temp[1],&begin));
//        } else if (temp[0] == 2) {
//            Node *require = find(temp[1],&begin);
//            if (require->next != NULL) {
//                printf("%d\n",require->next->val);
//            } else {
//                printf("0\n");
//            }
//        } else {
//            Delete(temp[1],&begin);
//        }
//    }
//
//    return 0;
//}
//
//Node *find(int num,Node *node) {
//    while (node != NULL) {
//        if (node->val == num) {
//            break;
//        }
//        node = node->next;
//    }
//    return node;
//}
//
//void Add(int num,Node *node) {
//    Node *ret = malloc(sizeof *ret);
//    ret->val = num;
//    ret->next = node->next;
//    node->next = ret;
//}
//
//void Delete(int num,Node *node) {
//    Node *ret = find(num,node);
//    Node *tem = ret->next;
//    ret->next = tem->next;
//    free(tem);
//}

#include <stdio.h>

int node[1000005] = {0};

void Add(int x,int y) {
    node[y] = node[x];
    node[x] = y;
}

void Delete(int x) {
    node[x] = node[node[x]];
}

int main() {
    //node[1] = 1;
    int q = 0;
    scanf("%d",&q);
    for (int i = 0; i < q; ++i) {
        int op = 0;
        int x = 0;
        int y = 0;
        scanf("%d",&op);
        if (op == 1) {
            scanf("%d%d",&x,&y);
            Add(x,y);
        } else if (op == 2) {
            scanf("%d",&x);
            printf("%d\n",node[x]);
        } else {
            scanf("%d",&x);
            Delete(x);
        }
    }

    return 0;
}