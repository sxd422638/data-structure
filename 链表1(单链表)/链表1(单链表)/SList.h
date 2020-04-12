#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<assert.h>



//单向+不带头+循环
typedef  int SLTDataType;
typedef struct SListNode     //(单链表)
{

	SLTDataType _data;       //数据域
	struct SListNode* _next; //指针域


}SListNode;



SListNode* BuySListNode(SLTDataType x); //把结点开好，并进行初始化 开空间

void SListPushBack(SListNode** pplist, SLTDataType x);//尾插法 读写时要传二级指针
void  SListPrint(SListNode* plist);						//只读的时候一级指针

SListNode* SListPopBack(SListNode** pplist);                 //尾删
SListNode* SListPushFront(SListNode** pplist, SLTDataType x);//头插
SListNode* SListPopFront(SListNode** pplist);                //头删
SListNode* SListFind(SListNode* plist, SLTDataType x);//查找

void SListInsertAfter(SListNode* pos, SLTDataType x);      //插入
void SListEraseAfter(SListNode* pos);//删除









