#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDatatype;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;//上一个
	LTDatatype data;


}ListNode;//直接带变量名ListNode 
		 //相当于struct ListNode ListNode最后一个是结构体变量的名字

ListNode* CreateHead();

void ListDestory(ListNode* pHead);
void ListPrint(ListNode* pHead);

void ListPushBack(ListNode* pHead, LTDatatype x); //尾插
void ListPushFront(ListNode* pHead, LTDatatype x);//头插
void ListPopBack(ListNode* pHead);//尾删
void ListPopFront(ListNode* pHead);//头删


// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDatatype x);
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);



