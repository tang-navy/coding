#include"../include/list.h"
void delete_by_order(DList L,int position)
{
    DNode*p=L->next;
    int i=1;
    if(position<1)
    {
        printf("the order you entered must no less than 1\n");
        return;
    }
    if(p==L)
    {
        printf("the list is empty\n");
        return;
    }
    while(p!=L&&i!=position)
    {
        p=p->next;
        i++;
    }
    if(p==L)
    {
        printf("the order you entered is more than the length of list\n");
        return;
    }
    else{
        p->pre->next=p->next;
        p->next->pre=p->pre;
        printf("deleted element %d in position %d\n",p->data,position);
        free(p);
    }

}