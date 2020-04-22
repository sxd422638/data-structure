#include"Heap.h"

void TestHeap()
{


	HPDataType a[10] = { 4,3,7,1,8,0,5,6,9,2 };//输出0 1 4 3 2 7 5 6 9 8
	Heap hp;
	HeapCreate(&hp, a, 10);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPush(&hp, 0);
	HeapPrint(&hp);
	HeapPush(&hp, -1);
	HeapPrint(&hp);
}

//TopK问题 陕西省排名前10李白 建立10个数据的小堆
//找最大的前K个 ， 建立K个数的小堆
//找最小的前K个 ， 建立K个数的大堆


void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int)*n);
	srand(time(NULL));
	for (size_t i = 0; i < n; i++)
	{
		a[i] = rand() % 1000000;
	}
	/*a[5] = 176878;
	a[522] = 276878;
	a[554] = 10078678;
	a[546] = 100008678;
	a[2345] = 2222678;
	a[4355] = 7777678;
	a[5234] = 8888879;
	a[234] = 7666879;
	a[6546] = 212121789;
	a[9578] = 1343789;*/

	//1.找最大的前10个
	Heap hp;
	HeapCreate(&hp, a,10);
	for(size_t i = 10 ; i < n ; ++i )
	{ 
		if (a[i] > HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	
	}
	HeapPrint(&hp);

}









int  main()
{
	/*TestHeap();*/
	/*TestTopk();*/



	
	int  a[10] = { 4,3,7,1,8,0,5,6,9,2 };
	HeapSort(a , 10);
	for (int i = 0; i < 10; ++i)
	{
		printf(" %d ", a[i]);
	}

	return 0;

}