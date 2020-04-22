#include"Heap.h"
void Swap(HPDataType* x1, HPDataType* x2)
{
	HPDataType x = *x1;
	*x1 = *x2;
	*x2 = x;
}
////小堆的向下调整算法
//void AdjustDown(HPDataType* a ,int n , int root  )//构建小堆->root表示数组中某个位置的下标
//{   
//	int parent = root;//表示下标 默认child指向左孩子
//	int child = root * 2 + 1;//表示左孩子下标
//	while (child < n)//当child超出数组的范围时 退出循环
//	{
//		if (child+1 < n && a[child + 1] < a[child])//选出小的孩子 让child指向小的那一个
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

//大堆的向下调整算法
void AdjustDown(HPDataType* a, int n, int root)//构建小堆->root表示数组中某个位置的下标
{
	int parent = root;//表示下标 默认child指向左孩子
	int child = root * 2 + 1;//表示左孩子下标
	while (child < n)//当child超出数组的范围时 退出循环
	{
		if (child + 1 < n && a[child + 1] > a[child])//选出小的孩子 让child指向小的那一个
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

////小堆向上调整算法
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

//大堆向上调整算法
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



// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);//目标，源，字节数 内存拷贝
	hp->_size = n;
	hp->_capacity = n;
	//构建堆的算法
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)//从最后一个非叶子结点到第1个结点一次进行向下调整
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




// 堆的销毁
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);

	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	//向上调整算法
	AdjustUp(hp->_a, hp->_size, hp->_size - 1);

}
// 堆的删除
void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	--hp->_size;
	AdjustDown(hp->_a, hp->_size, 0);//这时只需要进行一次向下调整即可
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;//空返回1 非空返回0
}
// 对数组进行堆排序
//升序建大堆 
//降序建小堆
void HeapSort(int* a, int n)
{
	//1.建大堆
	for(int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}//现在最大的数在根
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