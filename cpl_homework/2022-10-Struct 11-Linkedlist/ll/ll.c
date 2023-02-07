//
// Created by 86139 on 2022/12/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void Init(Linklist *list) {
    list->head = NULL;
    list->tail = NULL;
}

bool IsEmpty(const Linklist *list) {
    return list->head == NULL;
}

void Print(const Linklist *list) {
    Node *node = list->head;
     do {
        printf("%d ",node->val);
        node = node->next;
    } while (node != list->head);
}

void Append(Linklist *list, int val) {
    Node *node = malloc(sizeof *node);
    if (node == NULL) {
        printf("Error : malloc failed in Append()\n");
        return;
    }

    node->val = val;

    if (IsEmpty(list)) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->tail->next = list->head;



}

void Free(Linklist *list) {
    //TODO:
}