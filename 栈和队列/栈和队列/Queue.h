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
	QueueNode* front;//队头
	QueueNode* back;//队尾
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq , QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);//返回1表示空 返回0表示非空
size_t QueueSize(Queue* pq);



















