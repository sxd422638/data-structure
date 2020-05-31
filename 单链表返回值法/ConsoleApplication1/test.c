#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<assert.h>





typedef  int SLTDataType;
typedef struct SListNode     //(单链表)
{

	SLTDataType _data;       //数据域
	struct SListNode* _next; //指针域


}SListNode;

SListNode* SListPushFront(SListNode* head, SLTDataType x)//头插法 返回值
{

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	if (head == NULL)
	{
		head = newnode; //确定新的头
		return head;
	}
	else
	{
		newnode->_next = head;


	}
	head = newnode;
	return head;
}









SListNode* SListPopFront(SListNode* head)
{
	SListNode* cur = head;
	if (cur == NULL)
	{
		return ;
	}
	else if (cur->_next == NULL)
	{
		free(cur);
		cur = NULL;
	}
	else
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	head = cur;
	return head;
}
void  SListPrint(SListNode* plist)//打印
{
	SListNode* cur = plist;
	while (cur != NULL)//遍历一遍
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}


SListNode* SListPopBack(SListNode* head)  //尾删 返回值法
{
	assert(head);
	//第一步 找尾
	SListNode* prev = NULL;   //定义tail上一个数 
	SListNode* tail = head;
	//1.空 、只有一个结点
	//2.两个及以上的结点
	if (tail == NULL || tail->_next == NULL)
	{
		free(tail);
		head = NULL;
	}

	else
	{
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		tail = NULL;
		prev->_next = NULL;

	}
	
	return head;

}







void TestList2()
{
	SListNode* head = NULL;
	head =  SListPushFront(head, 1);
	head = SListPushFront(head, 2);
	head = SListPushFront(head, 3);
	head = SListPushFront(head, 4);
	SListPrint(head);
	head =  SListPopBack(head);
	head = SListPopBack(head);
	head = SListPopBack(head);
	head = SListPopBack(head);

	SListPrint(head);
}






int main()
{
	 TestList2();
		return 0;


}