#include"../include/list.h"
void list_print(LinkList L)
{
    ListNode*p=L->next;
    while(p!=NULL)
    {
        if(p->next!=NULL)
        {
            printf("%d->",p->data);
        }
        else
        {
            printf("%d\n",p->data);
        }
        p=p->next;
        
    }

}