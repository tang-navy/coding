#include"../include/list.h"
int main()
{
    LinkList L=init();
    insert(L,-1);
    insert(L,4);
    insert(L,9);
    insert(L,2);
    insert(L,11);
    insert_by_order(L,3,18);
   list_print(L);
   delete_by_order(L,6);
   list_print(L);
   sort(L);
   list_print(L);
   reverse(L);

}