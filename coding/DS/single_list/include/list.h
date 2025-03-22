#ifndef LIST_H//如果LIST_H已被定义，则后续的代码块不会被编译；
//防止多个源文件调用此头文件时，被重复编译；
#define LIST_H
#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
typedef struct ListNode
{
    int data;
    struct ListNode* next;
}ListNode,*LinkList;
LinkList init();
void insert(LinkList L,int a);
bool insert_by_order(LinkList L,int position,int a);
void list_print(LinkList L);
void delete_by_order(LinkList L,int position);
void sort(LinkList L);
void reverse(LinkList L);
#endif