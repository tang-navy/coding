#include"../include/list.h"
LinkList init()
{
    ListNode* L=(ListNode*)malloc(sizeof(ListNode));
    L->next=NULL;
    return L;
}