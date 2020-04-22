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
//打印
void HeapPrint(Heap* hp);
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);//O(N)
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);//O(logN)
// 堆的删除
void HeapPop(Heap* hp);//O(logN)
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);//O(1)
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
// 对数组进行堆排序
void HeapSort(int* a, int n);
///交换
void Swap(HPDataType* x1, HPDataType* x2);

//大堆的向下调整算法
void AdjustDown(HPDataType* a, int n, int root);

//大堆向上调整算法
void AdjustUp(HPDataType* a, int n, int child);