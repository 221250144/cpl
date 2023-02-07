#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char file[25];
    struct node *next1;
    struct node *next2;
    struct node *before;
    int position;
} Node;
Node begin;

int cnt = 0;

Node *find(char *name,Node *node) ;
int Query(Node *node) ;

int main ()
{
    int n = 0;
    int m = 0;
    char file1[20] = {0};
    char file2[20] = {0};
    scanf("%d%d%s%s",&n,&m,begin.file,file1);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%s%s", file1, file2);
        Node *temp = find(file2, &begin);

        Node *node = malloc(sizeof *node);
        node->next1 = NULL;
        node->next2 = NULL;
        memset(node->file,0,24);
        strcpy(node->file,file1);
        node->before = temp;
        if (temp->next1 == NULL) {
            temp->next1 = node;
            node->position = 1;
        } else {
            temp->next2 = node;
            node->position = 2;
        }
    }

    char act[20] = {0};
    char file[25] = {0};
    for (int i = 0; i < m; ++i) {
        scanf("%s%s",act,file);
        Node *location = find(file,&begin);
        if (strcmp(act,"query") == 0) {
            printf("%d\n",Query(location));
        } else {
            if (location->position == 1) {
                location->before->next1 = NULL;
            } else {
                location->before->next2 = NULL;
            }
        }
    }


    return 0;
}

Node *find(char *name,Node *node) {
    if (node == NULL) {
        return NULL;
    }
    if (strcmp(node->file, name) == 0) {
        return node;
    }
    Node *temp = find(name, node->next1);
    if (temp != NULL) {
        return temp;
    } else {
        return find(name, node->next2);
    }
}

int Query(Node *node) {
    if (node == NULL) {
        return 0;
    } else {
        return Query(node->next1) + Query(node->next2) + 1;
    }
}