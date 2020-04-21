#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int STDataType;
typedef struct Stack
{
	//能用数组尽量不用链表
	STDataType* a;
	size_t top;		//栈顶
	size_t capacity;


}Stack;

void StackInit(Stack* pst);
void StackDestory(Stack* pst);
void StackPush(Stack* pst , STDataType x ); //只允许在栈顶进行插入删除
void StackPop(Stack* pst);//删除
STDataType StackTop(Stack* pst);
int StackEmpty(Stack* pst);//返回1表示空 返回0表示非空
size_t StackSize(Stack* pst);//返回数据的个数


































