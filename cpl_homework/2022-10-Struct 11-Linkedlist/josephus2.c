#include <stdio.h>
#include "ll/ll.h"

#define NUM 10

void SitAroundCircle(Linklist *list,int num) ;
void KillUntilOne(Linklist *list) ;
int GetSurvivor(const Linklist *list) ;

int main()
{
    Linklist list;
    Init(&list);

    SitAroundCircle(&list,NUM);
    Print(&list);
    KillUntilOne(&list);
    int survivor = GetSurvivor(&list);
    printf("%d : %d\n",NUM,survivor);

    Free(&list);

    return 0;
}

void SitAroundCircle(Linklist *list,int num) {
    for (int i = 1; i <= num; ++i) {
        Append(list,i);
    }
}

void KillUntilOne(Linklist *list) {
    Node *node = list->head;

    while (!IsSingleton(list)) {
        Delete(list,node);
        node = node->next;
    }
}

int GetSurvivor(const Linklist *list) {

}