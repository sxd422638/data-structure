#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;

}QueueNode;

typedef struct Queue
{
	QueueNode* front;//��ͷ
	QueueNode* back;//��β
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq , QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);//����1��ʾ�� ����0��ʾ�ǿ�
size_t QueueSize(Queue* pq);



















