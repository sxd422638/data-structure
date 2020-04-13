#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDatatype;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;//��һ��
	LTDatatype data;


}ListNode;//ֱ�Ӵ�������ListNode 
		 //�൱��struct ListNode ListNode���һ���ǽṹ�����������

ListNode* CreateHead();

void ListDestory(ListNode* pHead);
void ListPrint(ListNode* pHead);

void ListPushBack(ListNode* pHead, LTDatatype x); //β��
void ListPushFront(ListNode* pHead, LTDatatype x);//ͷ��
void ListPopBack(ListNode* pHead);//βɾ
void ListPopFront(ListNode* pHead);//ͷɾ


// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDatatype x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);



