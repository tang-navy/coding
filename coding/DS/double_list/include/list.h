#ifndef LIST_H//如果LIST_H已被定义，则后续的代码块不会被编译；
//防止多个源文件调用此头文件时，被重复编译；
#define LIST_H
#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
typedef struct DNode
{
    int data;
    struct DNode* next;
    struct DNode* pre;
}DNode,*DList;

#endif