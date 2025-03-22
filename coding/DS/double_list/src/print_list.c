#include"../include/list.h"
void print_list(DList L)
{
    DNode* p=L;
    while(p->next!=L)
    {
        printf("%d<->",p->next->data);
        p=p->next;
    }
}