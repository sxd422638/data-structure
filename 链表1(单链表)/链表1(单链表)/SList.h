#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<assert.h>



//����+����ͷ+ѭ��
typedef  int SLTDataType;
typedef struct SListNode     //(������)
{

	SLTDataType _data;       //������
	struct SListNode* _next; //ָ����


}SListNode;



SListNode* BuySListNode(SLTDataType x); //�ѽ�㿪�ã������г�ʼ�� ���ռ�

void SListPushBack(SListNode** pplist, SLTDataType x);//β�巨 ��дʱҪ������ָ��
void  SListPrint(SListNode* plist);						//ֻ����ʱ��һ��ָ��

SListNode* SListPopBack(SListNode** pplist);                 //βɾ
SListNode* SListPushFront(SListNode** pplist, SLTDataType x);//ͷ��
SListNode* SListPopFront(SListNode** pplist);                //ͷɾ
SListNode* SListFind(SListNode* plist, SLTDataType x);//����

void SListInsertAfter(SListNode* pos, SLTDataType x);      //����
void SListEraseAfter(SListNode* pos);//ɾ��









