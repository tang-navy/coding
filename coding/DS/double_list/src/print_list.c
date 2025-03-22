#include"../include/list.h"
//从头节点顺序打印，也可以从头节点逆向打印
void print_list(DList L)
{
    DNode* p=L;
    while(p->next!=L)
    {
        printf("%d<->",p->next->data);
        p=p->next;
    }
    printf("\n");
}
