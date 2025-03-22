#include"../include/list.h"
void reverse(LinkList L)
{
    printf("before reverse:\n");
    list_print(L);
    ListNode* p=L->next;
    LinkList li=(LinkList)malloc(sizeof(ListNode));
    li->next=NULL;
    while(p!=NULL)
    {
        insert(li,p->data);
        p=p->next;
    }
    p=L;
    while(p!=NULL)
    {
        ListNode*temp=p->next;
        free(p);
        p=temp;
    }
    L=li;
    printf("after reverse:\n");
    list_print(L);

}