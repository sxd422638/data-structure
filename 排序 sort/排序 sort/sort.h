#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void PrintArray(int* a, int n);//��ӡ
void Swap(int* p1, int* p2);//����

void InsertSort(int* a, int n);//��������  ����

void ShellSort(int* a, int n);//ϣ������

void SelectSort(int* a, int n);//ֱ��ѡ������


void HeapSort(int* a, int n);//������

void BubbleSort(int* a, int n);//ð������

int PartSort(int* a, int begin , int end);//��������
int PartSort2(int* a, int begin, int end);//2.�ڿӷ�

int PartSort2(int* a, int begin, int end); //3.ǰ��ָ�뷨

int GetMidIndex(int* a, int left, int right);//����ȡ��(�����Ż�)
void QuickSort(int* a, int left, int right);//��������
