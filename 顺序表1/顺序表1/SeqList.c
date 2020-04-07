#include"SeqList.h"
void SeqListInit(SeqList* ps)
{

	assert(ps);
	ps->_a = NULL;
	ps->_size = 0;
	ps->_capacity = 0;
}


void SeqListDestory(SeqList* ps)
{
	free(ps->_a);
	ps->_a = NULL;
	ps->_size = ps->_capacity = 0;
}

void SeqListCheckCapacity(SeqList* ps)//检查空间容量
{

	if (ps->_size == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		//==0 赋值4 不等于0 执行后面的*2
		ps->_a = realloc(ps->_a, newcapacity * sizeof(SLDataType));
		//realloc（要调整的内存地址，调整后的大小——要字节数）空间扩容
		ps->_capacity = newcapacity;

	}

}


void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_a[i]);
	}
	printf("\n");
}




void SeqListPushBack(SeqList* ps, SLDataType x) //尾插
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->_a[ps->_size++] = x;//size表示的是最后一个位置的下一个位置
							//ps->_size++;						//size++但是返回的是++之前的值

}
void SeqListPopBack(SeqList* ps)  //尾删
{
	assert(ps && ps->_size > 0);
	//ps->_a[ps->_size - 1] = 0;
	ps->_size--;

}
void SeqListPushFront(SeqList* ps, SLDataType x) //头插
{
	assert(ps);
	//空间扩容
	SeqListCheckCapacity(ps);
	//挪动数据  从后往前挪
	int end = ps->_size - 1;
	for (; end >= 0; --end)
	{
		ps->_a[end + 1] = ps->_a[end];  //前面的给后面的赋值 一次往后移动
	}
	ps->_a[0] = x;
	ps->_size++;


}
void SeqListPopFront(SeqList* ps)  //头删
{
	assert(ps && ps->_size > 0);

	for (size_t start = 0; start <= ps->_size - 1; ++start)
	{
		ps->_a[start] = ps->_a[start + 1];
	}

	ps->_size--;
}

int  SeqListFind(SeqList*ps, SLDataType x)//查找
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; ++i)
	{
		if (ps->_a[i] == x)
		{
			return i;
		}

	}
	return -1;

}

void SeqListInsert(SeqList*ps, size_t pos, SLDataType x)//插入
{
	assert(ps && pos < ps->_size);
	SeqListCheckCapacity(ps);
	size_t  end = ps->_size + 1;  //这样不会有访问越界的问题

	while (end > pos)
	{
		ps->_a[end] = ps->_a[end - 1];
		--end;
	}
	ps->_a[pos] = x;
	ps->_size++;
}

void SeqListErase(SeqList*ps, size_t pos)//删除

{
	assert(ps && pos < ps->_size);
	size_t i = pos + 1;
	while (i < ps->_size)
	{
		ps->_a[i - 1] = ps->_a[i];
		++i;
	}

	ps->_size--;


}

//SeqListRemove(SeqList*ps, SLDataType x)  //移动
//{
//	int pos = SeqListFind(ps, x);
//	if (pos >= 0)
//	{
//		SeqListErase(ps, pos);
//
//	}
//}

 void SeqListBubbleSoet(SeqList* ps)//冒泡排序
{
	 //控制冒泡的终止位置
	 for (size_t end = ps->_size; end > 0; --end)
	 {
		 int exchange = 0;
		 //单趟冒泡
		 for (size_t i = 0; i < end - 1; i++)//注意起始位置与终止位置
		 {
			 if (ps->_a[i] > ps->_a[i + 1])
			 {
				 SLDataType tmp = ps->_a[i];
				 ps->_a[i] = ps->_a[i + 1];
				 ps->_a[i + 1] = tmp;

				 exchange = 1;
			 }
		 }
		 if (exchange == 0)
		 {
			 break;
		 }
	 }
}
 //[0 , size-1]
 //[0 , size-1)
 int  SeqListBinaryFind(SeqList* ps, SLDataType x) //二分查找
 {
	 size_t begin = 0, end = ps->_size-1;
	 while (begin <= end )
	 {
		 size_t mid = (begin + end) / 2;
		 if (ps->_a[mid] == x)
		 {
			 return mid;
		 }
		 else if (ps->_a[mid] < x)
		 {
			 begin = mid + 1;
		 }
		 else
		 {
			 end = mid - 1;
		 }
	 }
	 return -1;
	 /*
	 //方法2
	size_t begin = 0, end = ps->_size; //<------- 这里变成（  开区间
	 while (begin < end )  //<------- 这里去掉=
	 {
		 size_t mid = (begin + end) / 2;
		 if (ps->_a[mid] == x)
		 {
			 return mid;
		 }
		 else if (ps->_a[mid] < x)
		 {
			 begin = mid + 1; //<-------  这里变成 [  闭区间
		 }
		 else
		 {
			 end = mid ;//<------- 这里去掉 +1 变成（ 开区间
		 }
	 }
	 return -1; 
	 
	 
	 */
 }






