#include"../include/list.h"
DList init(DList L)
{
    L=(DNode*)malloc(sizeof(DNode));
    L->next=L;
    L->pre=L;
    return L;
}