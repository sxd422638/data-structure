#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	size_t _size;
	size_t _capacity;


}Heap;
//��ӡ
void HeapPrint(Heap* hp);
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);//O(N)
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);//O(logN)
// �ѵ�ɾ��
void HeapPop(Heap* hp);//O(logN)
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);//O(1)
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
// ��������ж�����
void HeapSort(int* a, int n);
///����
void Swap(HPDataType* x1, HPDataType* x2);

//��ѵ����µ����㷨
void AdjustDown(HPDataType* a, int n, int root);

//������ϵ����㷨
void AdjustUp(HPDataType* a, int n, int child);