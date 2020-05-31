#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<assert.h>





typedef  int SLTDataType;
typedef struct SListNode     //(������)
{

	SLTDataType _data;       //������
	struct SListNode* _next; //ָ����


}SListNode;

SListNode* SListPushFront(SListNode* head, SLTDataType x)//ͷ�巨 ����ֵ
{

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	if (head == NULL)
	{
		head = newnode; //ȷ���µ�ͷ
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
void  SListPrint(SListNode* plist)//��ӡ
{
	SListNode* cur = plist;
	while (cur != NULL)//����һ��
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}


SListNode* SListPopBack(SListNode* head)  //βɾ ����ֵ��
{
	assert(head);
	//��һ�� ��β
	SListNode* prev = NULL;   //����tail��һ���� 
	SListNode* tail = head;
	//1.�� ��ֻ��һ�����
	//2.���������ϵĽ��
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