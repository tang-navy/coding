#include"../include/list.h"
void insert(LinkList L,int a)
{
    ListNode* node=(ListNode*)malloc(sizeof(ListNode));
    node->data=a;
    node->next=L->next;
    L->next=node;
}