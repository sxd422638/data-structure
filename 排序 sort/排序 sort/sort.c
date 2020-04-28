#include"sort.h"


void PrintArray(int* a, int n)//打印
{
	for (size_t i = 0; i < n ; ++i)
	{
		printf(" %d", a[i]);

	}
	printf("\n");
}





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1.插入排序
void InsertSort(int* a, int n)//    再去控制多趟排序
{								
	//先写单趟排序 将tmp插入[0 , end]有序区间，依旧保持有序

	for (size_t i = 0; i < n - 1 ; ++i)
	{
		int end = i ;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}

		}
		a[end + 1] = tmp;//不管是end大 还是tmp大 tmp都插入在end+1的位置
	}
	
}

//2.希尔排序
void ShellSort(int* a, int n)
{
	//先单趟排序，间距为gap的插入排序
	//[0 ,end ] tmp 间距都是gap
	//当gap > 1时 完成的是预排序
	//当gap = 1是 完成的是插入排序
	int gap = n;
	while (gap > 1)
	{

		gap = gap / 3 + 1;
		for (size_t i = 0; i < n - gap; ++i)
		{


			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//3.直接选择排序
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int  end = n - 1;
	while (begin < end)
	{


		int mini = begin;
		int maxi = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
			maxi = mini;
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}




//4.堆排序
void AdjustDown(int* a, int n , int root)//   向下 / 向上 调整算法
{

	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child +1 < n && a[child + 1] > a[child])//确保右孩子存在
		{
			++child;//此时选出了大的孩子
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);//如果孩子大于父亲 交换
			parent = child;             //继续往下调 直到调到叶子
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}

	}
}
void HeapSort(int* a, int n)//堆排序
{
	// 建大堆 
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)//i表示从哪个位置开始
	{
		AdjustDown(a, n, i);//此时选出了最大的数
	}
	int end = n - 1;
	while (end > 0)
	{
		
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
	


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//5.冒泡排序
void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0)
	{
		int exchange = 0;
		//单趟冒泡
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
		--end;//控制end的终止位置
	}
}

//6.分制排序 相当于单趟的快速排序





//三数取中 把中间数的下标找出来 (一种优化的方式)
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;

	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else// a[begin] > a[mid]
	{

		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}

}





//[begin , end ]左边去做key
//int PartSort(int* a, int begin , int end )
//{
//	
//	int key = begin;
//	while (begin < end)
//	{
//		//end先走 找小
//		while (begin < end && a[end] >= a[key])//a[end] < a[key]的时候停下来
//		{
//			--end;
//		}
//		//begin走 找大
//		while (begin < end && a[begin] <= a[key])//a[end] < a[key]的时候停下来
//		{
//			++begin;
//		}
//		Swap(&a[begin], &a[end]);
//	}
//	Swap(&a[key], &a[begin]);
//	return begin;
//}

//右边去做key

int PartSort1(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[end]);
	int key = end;
	while (begin < end)
	{
		//begin先走 找大
		while (begin < end && a[begin] <= a[key])//a[end] < a[key]的时候停下来
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
		//end后走 找小
		while (begin < end && a[end] >= a[key])//a[end] < a[key]的时候停下来
		{
			--end;
		}
		
	}
	Swap(&a[key], &a[begin]);
	return begin;
}




//2.挖坑法
int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		a[begin] = a[end];//begin是第一个坑位

		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[end] = a[begin];
	}
	a[begin] = key;
	return begin;
	
}

//3.前后指针法
int PartSort2(int* a, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int key = end;
	while (cur < end)
	{
		if (a[cur] < a[key])//if(a[cur] < a[key] && ++prve != cur )
		{
			++prev;
			Swap(&a[prev], &a[cur]);
		}
			++cur;
	}
	++prev;
	Swap(&a[prev], &a[key]);
}













//快速排序(递归)
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	if ((right - left + 1) < 10)//表示个数
	{
		InesrtSort( a+left ,  right - left + 1);

	}

		int keyIndex = PartSort(a, left, right);
		//[left , keyindex-1] [keyindex] [keyindex , right]
		QuickSort(a, left, keyIndex - 1);
		QuickSort(a, keyIndex + 1, right);
	
 }

















