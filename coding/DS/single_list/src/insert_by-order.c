#include"../include/list.h"
bool insert_by_order(LinkList L,int position,int a)
{
    if(position<1)
    {
        printf("the order you entered must no less than 1\n");
        return false;
    }
    ListNode* p=L;
    int i=0;
    while(p!=NULL&i!=position-1)
    {
        i++;
        p=p->next;
    }
    if(p==NULL)
    {
        printf("the order you entered is more than the length of list\n");
        return false;
    }
    else{
        ListNode* node=(ListNode*)malloc(sizeof(ListNode));
        node->data=a;
        node->next=p->next;
        p->next=node;
        printf("inserted %d successfully in %d\n",a,position);
        return true;

    }

}