#include"sort.h"


void PrintArray(int* a, int n)//��ӡ
{
	for (size_t i = 0; i < n ; ++i)
	{
		printf(" %d", a[i]);

	}
	printf("\n");
}





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//1.��������
void InsertSort(int* a, int n)//    ��ȥ���ƶ�������
{								
	//��д�������� ��tmp����[0 , end]�������䣬���ɱ�������
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
		a[end + 1] = tmp;//������end�� ����tmp�� tmp��������end+1��λ��
	}
	
}

//2.ϣ������
void ShellSort(int* a, int n)
{
	//�ȵ������򣬼��Ϊgap�Ĳ�������
	//[0 ,end ] tmp ��඼��gap
	//��gap > 1ʱ ��ɵ���Ԥ����
	//��gap = 1�� ��ɵ��ǲ�������
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

//3.ֱ��ѡ������
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




//4.������
void AdjustDown(int* a, int n , int root)//   ���� / ���� �����㷨
{

	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child +1 < n && a[child + 1] > a[child])//ȷ���Һ��Ӵ���
		{
			++child;//��ʱѡ���˴�ĺ���
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);//������Ӵ��ڸ��� ����
			parent = child;             //�������µ� ֱ������Ҷ��
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}

	}
}
void HeapSort(int* a, int n)//������
{
	// ����� 
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)//i��ʾ���ĸ�λ�ÿ�ʼ
	{
		AdjustDown(a, n, i);//��ʱѡ����������
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






