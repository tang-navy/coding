#include"../include/list.h"
void delete_by_order(LinkList L,int position)
{
    ListNode*p=L->next;
    int i=1;
    if(position<1)
    {
        printf("the order you entered must no less than 1\n");
        return;
    }
    
    while(p!=NULL&&i!=position-1)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)
    {
        printf("the order you entered is more than the length of list\n");
        return;
    }
    else{
        ListNode*temp=p->next;
        p->next=p->next->next;
        printf("deleted element %d in position %d\n",temp->data,position);
        free(temp);
    }


    
}
