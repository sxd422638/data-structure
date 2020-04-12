#include"SList.h"


//单向+不带头+循环
typedef  int SLTDataType;



SListNode* BuySListNode(SLTDataType x)  //把结点开好，并进行初始化
{
	//动态申请一个空间，用来存放一个结点，并用临时指针node指向这个结点
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));

	node->_data = x;   //将数据域存储到当前结点的data域中
	node->_next = NULL;//设置当前结点的后继指针为空
	return node;
}


void SListPushBack(SListNode** pplist, SLTDataType x)//尾插法
//plist 是pplist的地址 *pplist就是plist
{
	SListNode* newnode = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tail = *pplist;//找尾
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		tail->_next = newnode;

	}


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



SListNode* SListPopBack(SListNode** pplist)                //尾删
{
	assert(pplist);
	//第一步 找尾
	SListNode* prev = NULL;   //定义tail上一个数 
	SListNode* tail = *pplist;
	//1.空 、只有一个结点
	//2.两个及以上的结点
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
SListNode* SListPushFront(SListNode** pplist, SLTDataType x)//头插
{
	/*1.空
	2.非空*/

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
SListNode* SListPopFront(SListNode** pplist)                //头删
{/*
	1.空
	2.一个
	3.两个以上*/
	//SListNode* first = *pplist;
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->_next == NULL)
	{
		free(*pplist);
		//plist = NULL;//达不到效果 因为plist只是局部变量
		*pplist = NULL;

	}
	else
	{
		SListNode* _next = (*pplist)->_next;
		free(*pplist);
		*pplist = _next;
	}

}


//不会改变链表头的用一级指针，会改变的用二级指针
SListNode* SListFind(SListNode* plist, SLTDataType x) //查找
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

void SListInsertAfter(SListNode* pos, SLTDataType x)  //插入后一个  中间 边界  头部 都可以使用
{
	assert(pos);
	SListNode* next = pos->_next;
	//pos newnode next
	SListNode* newnode = BuySListNode(x);
	pos->_next = newnode;
	newnode->_next = next;


}


void SListEraseAfter(SListNode* pos)//删除后一个 中间 边界  头部 都可以使用
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









