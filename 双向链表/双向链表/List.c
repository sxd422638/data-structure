#include"List.h"



ListNode* BuyListNode(LTDatatype x)
{
	ListNode* node= (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

ListNode* CreateHead()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}
void ListPrint(ListNode* pHead)
{
	ListNode* cur = pHead->next;
	while (cur != pHead)//cur = pHead的时候退出循环
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}



void ListPushBack(ListNode* pHead, LTDatatype x)//尾插
{
	//ListNode* newnode = BuyListNode(x);
	////head tail newnode 互相进行链接
	//ListNode* tail = pHead->prev;
	//tail->next = newnode;//tail的next指向newnode
	//newnode->prev = tail;
	//newnode->next = pHead;
	//pHead->prev = newnode;

	ListInsert(pHead, x);//在头的前面插入 变成尾插
	
}



void ListPushFront(ListNode* pHead, LTDatatype x)//头插
{
	/*ListNode* newnode = BuyListNode(x);
	ListNode* first = pHead->next;
	pHead->next = newnode;
	newnode->prev = pHead;
	newnode->next = first;
	first->prev = newnode;*/
	ListInsert(pHead->next, x);//在头的后面插入 变成头插

}



void ListPopBack(ListNode* pHead)//尾删
{
	//删除tail
	ListNode* tail = pHead->prev;
	ListNode* tailPrev = tail->prev;
	tailPrev->next = pHead;
	pHead->prev = tailPrev;
	free(tail);
	//ListErase(pHead->prev);   //复用Erase
}




void ListPopFront(ListNode* pHead)//头删
{
	ListNode* first = pHead->next;
	ListNode* second = first->next;
	pHead->next = second;
	second->prev = pHead;
	free(first);
	//ListErase(pHead->next); //复用Erase
}




// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDatatype x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}


// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;

	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);


}