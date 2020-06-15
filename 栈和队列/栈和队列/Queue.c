#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = pq->back = NULL;

}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->front;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		
		cur = next;

	}
	pq->front = pq->back = NULL;

}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;
	if (pq->back == NULL)
	{
		pq->front = pq->back = newnode;

	}
	else
	{
		pq->back->next = newnode;
		pq->back = newnode;
	}

}
void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* next = pq->front->next;
	
	free(pq->front);
	pq->front = next;
	if (pq->front == NULL)//�������һ����㱻�ɵ������
	{
		pq->back = NULL;

	}

}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->front->data;
}
QDataType QueueBack(Queue* pq)
{
	//��֮ǰ�ȼ��������û������
	assert(pq);
	return pq->back->data;

}
int QueueEmpty(Queue* pq)//����1��ʾ�� ����0��ʾ�ǿ�
{
	return pq->front == NULL ? 1 : 0;

}
size_t QueueSize(Queue* pq)
{
	size_t n = 0;
	QueueNode* cur = pq->front;
	while (cur != NULL)
	{
		++n;
		cur = cur->next;

	}
	return n;
}



















