//#pragma once
#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int SLDataType;
typedef struct SeqList  //��typedef��Ϊ�������SeqList���������ṹ�������
{						//���ӵĻ�ÿ����������Ҫ����struct SeqList
	SLDataType* _a;
	size_t _size;
	size_t _capacity;
}SeqList;
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);

void SeqListCheckCapacity(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDataType x); //β��
void SeqListPopBack(SeqList* ps);   //βɾ
void SeqListPushFront(SeqList* ps, SLDataType x); //ͷ��
void SeqListPopFront(SeqList* ps);   //ͷɾ


int  SeqListFind(SeqList*ps, SLDataType x);//����
void SeqListInsert(SeqList*ps, size_t pos, SLDataType x);//����
void SeqListErase(SeqList*ps, size_t pos);//ɾ��ĳ��λ�õ�ֵ
void SeqListRemove(SeqList*ps, SLDataType x);//�ƶ�



void SeqListBubbleSoet(SeqList* ps);//ð������
int  SeqListBinaryFind(SeqList* ps , SLDataType x);//���ֲ���





#endif 