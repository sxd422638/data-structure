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
	while (cur != pHead)//cur = pHead��ʱ���˳�ѭ��
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}



void ListPushBack(ListNode* pHead, LTDatatype x)//β��
{
	//ListNode* newnode = BuyListNode(x);
	////head tail newnode �����������
	//ListNode* tail = pHead->prev;
	//tail->next = newnode;//tail��nextָ��newnode
	//newnode->prev = tail;
	//newnode->next = pHead;
	//pHead->prev = newnode;

	ListInsert(pHead, x);//��ͷ��ǰ����� ���β��
	
}



void ListPushFront(ListNode* pHead, LTDatatype x)//ͷ��
{
	/*ListNode* newnode = BuyListNode(x);
	ListNode* first = pHead->next;
	pHead->next = newnode;
	newnode->prev = pHead;
	newnode->next = first;
	first->prev = newnode;*/
	ListInsert(pHead->next, x);//��ͷ�ĺ������ ���ͷ��

}



void ListPopBack(ListNode* pHead)//βɾ
{
	//ɾ��tail
	ListNode* tail = pHead->prev;
	ListNode* tailPrev = tail->prev;
	tailPrev->next = pHead;
	pHead->prev = tailPrev;
	free(tail);
	//ListErase(pHead->prev);   //����Erase
}




void ListPopFront(ListNode* pHead)//ͷɾ
{
	ListNode* first = pHead->next;
	ListNode* second = first->next;
	pHead->next = second;
	second->prev = pHead;
	free(first);
	//ListErase(pHead->next); //����Erase
}




// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDatatype x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}


// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;

	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);


}