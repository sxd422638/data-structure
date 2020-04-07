//#pragma once
#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int SLDataType;
typedef struct SeqList  //加typedef是为了让这个SeqList代表整个结构体的名字
{						//不加的话每次输入名字要输入struct SeqList
	SLDataType* _a;
	size_t _size;
	size_t _capacity;
}SeqList;
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);

void SeqListCheckCapacity(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDataType x); //尾插
void SeqListPopBack(SeqList* ps);   //尾删
void SeqListPushFront(SeqList* ps, SLDataType x); //头插
void SeqListPopFront(SeqList* ps);   //头删


int  SeqListFind(SeqList*ps, SLDataType x);//查找
void SeqListInsert(SeqList*ps, size_t pos, SLDataType x);//插入
void SeqListErase(SeqList*ps, size_t pos);//删除某个位置的值
void SeqListRemove(SeqList*ps, SLDataType x);//移动



void SeqListBubbleSoet(SeqList* ps);//冒泡排序
int  SeqListBinaryFind(SeqList* ps , SLDataType x);//二分查找





#endif 