#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int STDataType;
typedef struct Stack
{
	//�������龡����������
	STDataType* a;
	size_t top;		//ջ��
	size_t capacity;


}Stack;

void StackInit(Stack* pst);
void StackDestory(Stack* pst);
void StackPush(Stack* pst , STDataType x ); //ֻ������ջ�����в���ɾ��
void StackPop(Stack* pst);//ɾ��
STDataType StackTop(Stack* pst);
int StackEmpty(Stack* pst);//����1��ʾ�� ����0��ʾ�ǿ�
size_t StackSize(Stack* pst);//�������ݵĸ���


































