#include"../include/list.h"
void insert(DList L,int elem)
{
    DNode* p=(DNode*)malloc(sizeof(DNode));
    p->data=elem;
    if(L==L->next)//链表为空
    {
        L->next=p;
        p->pre=L;
        p->next=L;
        L->pre=p;
    }
    else
    {
        DNode* q=L->next;
        L->next=p;
        p->pre=L;
        p->next=q;
        q->pre=p;
    }
    
}