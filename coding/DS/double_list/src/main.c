#include"../include/list.h"
int main()
{
    DList L=NULL;
    L=init(L);
    insert(L,4);
    insert(L,41);
    insert(L,44);
    insert(L,9);
    print_list(L);
    delete_by_order(L,2);
    print_list(L);
}