#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void PrintArray(int* a, int n);//打印
void Swap(int* p1, int* p2);//交换

void InsertSort(int* a, int n);//插入排序  升序

void ShellSort(int* a, int n);//希尔排序

void SelectSort(int* a, int n);//直接选择排序


void HeapSort(int* a, int n);//堆排序

void BubbleSort(int* a, int n);//冒泡排序

int PartSort(int* a, int begin , int end);//分制排序
int PartSort2(int* a, int begin, int end);//2.挖坑法

int PartSort2(int* a, int begin, int end); //3.前后指针法

int GetMidIndex(int* a, int left, int right);//三数取中(快排优化)
void QuickSort(int* a, int left, int right);//快速排序
