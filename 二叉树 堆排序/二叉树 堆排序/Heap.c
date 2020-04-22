#include"Heap.h"
void Swap(HPDataType* x1, HPDataType* x2)
{
	HPDataType x = *x1;
	*x1 = *x2;
	*x2 = x;
}
////С�ѵ����µ����㷨
//void AdjustDown(HPDataType* a ,int n , int root  )//����С��->root��ʾ������ĳ��λ�õ��±�
//{   
//	int parent = root;//��ʾ�±� Ĭ��childָ������
//	int child = root * 2 + 1;//��ʾ�����±�
//	while (child < n)//��child��������ķ�Χʱ �˳�ѭ��
//	{
//		if (child+1 < n && a[child + 1] < a[child])//ѡ��С�ĺ��� ��childָ��С����һ��
//		{
//			++child;
//		}
//		if (a[child] < a [parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else 
//		{
//			break;
//		}
//	}
//}

//��ѵ����µ����㷨
void AdjustDown(HPDataType* a, int n, int root)//����С��->root��ʾ������ĳ��λ�õ��±�
{
	int parent = root;//��ʾ�±� Ĭ��childָ������
	int child = root * 2 + 1;//��ʾ�����±�
	while (child < n)//��child��������ķ�Χʱ �˳�ѭ��
	{
		if (child + 1 < n && a[child + 1] > a[child])//ѡ��С�ĺ��� ��childָ��С����һ��
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

////С�����ϵ����㷨
//void AdjustUp(HPDataType* a, int n, int child)
//{
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (a[child] < a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			child = parent;
//			parent =  (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//
//	}
//	
//
//}
//

//������ϵ����㷨
void AdjustUp(HPDataType* a, int n, int child)
{
int parent = (child - 1) / 2;
while (child > 0)
{
	if (a[child] > a[parent])
	{
		Swap(&a[child], &a[parent]);
		child = parent;
		parent = (child - 1) / 2;
	}
	else
	{
		break;
	}

}


}



// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);//Ŀ�꣬Դ���ֽ��� �ڴ濽��
	hp->_size = n;
	hp->_capacity = n;
	//�����ѵ��㷨
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)//�����һ����Ҷ�ӽ�㵽��1�����һ�ν������µ���
	{
		AdjustDown(hp->_a, hp->_size, i);
	}

}


void HeapPrint(Heap* hp)
{
	for (size_t i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);

	}
	printf("\n");
}




// �ѵ�����
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);

	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	//���ϵ����㷨
	AdjustUp(hp->_a, hp->_size, hp->_size - 1);

}
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	--hp->_size;
	AdjustDown(hp->_a, hp->_size, 0);//��ʱֻ��Ҫ����һ�����µ�������
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;//�շ���1 �ǿշ���0
}
// ��������ж�����
//���򽨴�� 
//����С��
void HeapSort(int* a, int n)
{
	//1.�����
	for(int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}//�����������ڸ�
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
	/*
	int  i  = 1;
	while( i < n )
	{
	Swap(&a[0] , &a[n-i]);
	AdjustDpwn(a , n-i , 0 )
	++i;
	}
	
	
	*/
}