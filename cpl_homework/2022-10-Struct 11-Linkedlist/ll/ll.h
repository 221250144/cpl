//
// Created by 86139 on 2022/12/19.
//

#ifndef UNTITLED4_LL_H
#define UNTITLED4_LL_H

#include <stdbool.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

typedef struct ll {
    Node *head;
    Node *tail;
} Linklist;

void Init(Linklist *list);

bool IsEmpty(const Linklist *list) ;

void Print(const Linklist *list) ;

void Append(Linklist *list, int val);

void Free(Linklist *list);


#endif //UNTITLED4_LL_H
