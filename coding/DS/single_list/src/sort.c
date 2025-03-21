#include"../include/list.h"
void sort(LinkList L)
{
    ListNode*p=L->next;
    ListNode*q=NULL;
    ListNode* min=NULL;
    for(p;p!=NULL;p=p->next)
    {
        min=p;
        for(q=p;q!=NULL;q=q->next)
        {
            if(q->data<min->data)
            {
                min=q;
            }
        }
        if(min!=p)
        {
            int temp=min->data;
            min->data=p->data;
            p->data=temp;
        }
    }
    //printf("the sorted list is:\n");
}