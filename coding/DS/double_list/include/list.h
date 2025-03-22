#ifndef LIST_H//如果LIST_H已被定义，则后续的代码块不会被编译；
//防止多个源文件调用此头文件时，被重复编译；
#define LIST_H
#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
typedef struct DNode
{
    int data;
    //int length;
    struct DNode* next;
    struct DNode* pre;
}DNode,*DList;

DList init(DList L);
void insert(DList L,int elem);
void print_list(DList L);
void delete_by_order(DList L,int position);
#endif