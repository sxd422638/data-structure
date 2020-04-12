#include"SList.h"


//����+����ͷ+ѭ��
typedef  int SLTDataType;



SListNode* BuySListNode(SLTDataType x)  //�ѽ�㿪�ã������г�ʼ��
{
	//��̬����һ���ռ䣬�������һ����㣬������ʱָ��nodeָ��������
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));

	node->_data = x;   //��������洢����ǰ����data����
	node->_next = NULL;//���õ�ǰ���ĺ��ָ��Ϊ��
	return node;
}


void SListPushBack(SListNode** pplist, SLTDataType x)//β�巨
//plist ��pplist�ĵ�ַ *pplist����plist
{
	SListNode* newnode = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tail = *pplist;//��β
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		tail->_next = newnode;

	}


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



SListNode* SListPopBack(SListNode** pplist)                //βɾ
{
	assert(pplist);
	//��һ�� ��β
	SListNode* prev = NULL;   //����tail��һ���� 
	SListNode* tail = *pplist;
	//1.�� ��ֻ��һ�����
	//2.���������ϵĽ��
	if (tail == NULL || tail->_next == NULL)
	{
		free(tail);
		*pplist = NULL;
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
	
}
SListNode* SListPushFront(SListNode** pplist, SLTDataType x)//ͷ��
{
	/*1.��
	2.�ǿ�*/

	SListNode* newnode = BuySListNode(x);
	if (*pplist != NULL)
	{
		newnode->_next = *pplist;
		*pplist = newnode;
	}
	else
	{
		*pplist = newnode;
	}

}
SListNode* SListPopFront(SListNode** pplist)                //ͷɾ
{/*
	1.��
	2.һ��
	3.��������*/
	//SListNode* first = *pplist;
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->_next == NULL)
	{
		free(*pplist);
		//plist = NULL;//�ﲻ��Ч�� ��Ϊplistֻ�Ǿֲ�����
		*pplist = NULL;

	}
	else
	{
		SListNode* _next = (*pplist)->_next;
		free(*pplist);
		*pplist = _next;
	}

}


//����ı�����ͷ����һ��ָ�룬��ı���ö���ָ��
SListNode* SListFind(SListNode* plist, SLTDataType x) //����
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;

		}
		cur = cur->_next;

	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)  //�����һ��  �м� �߽�  ͷ�� ������ʹ��
{
	assert(pos);
	SListNode* next = pos->_next;
	//pos newnode next
	SListNode* newnode = BuySListNode(x);
	pos->_next = newnode;
	newnode->_next = next;


}


void SListEraseAfter(SListNode* pos)//ɾ����һ�� �м� �߽�  ͷ�� ������ʹ��
{
	//pos newnode next
	assert(pos);
	SListNode* next = pos->_next;
	if (next != NULL)
	{
		SListNode* nextnext = next->_next;
		free(next);
		pos->_next = nextnext;

	}

}









