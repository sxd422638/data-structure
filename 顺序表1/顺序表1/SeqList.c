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

void SeqListCheckCapacity(SeqList* ps)//���ռ�����
{

	if (ps->_size == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		//==0 ��ֵ4 ������0 ִ�к����*2
		ps->_a = realloc(ps->_a, newcapacity * sizeof(SLDataType));
		//realloc��Ҫ�������ڴ��ַ��������Ĵ�С����Ҫ�ֽ������ռ�����
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




void SeqListPushBack(SeqList* ps, SLDataType x) //β��
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->_a[ps->_size++] = x;//size��ʾ�������һ��λ�õ���һ��λ��
							//ps->_size++;						//size++���Ƿ��ص���++֮ǰ��ֵ

}
void SeqListPopBack(SeqList* ps)  //βɾ
{
	assert(ps && ps->_size > 0);
	//ps->_a[ps->_size - 1] = 0;
	ps->_size--;

}
void SeqListPushFront(SeqList* ps, SLDataType x) //ͷ��
{
	assert(ps);
	//�ռ�����
	SeqListCheckCapacity(ps);
	//Ų������  �Ӻ���ǰŲ
	int end = ps->_size - 1;
	for (; end >= 0; --end)
	{
		ps->_a[end + 1] = ps->_a[end];  //ǰ��ĸ�����ĸ�ֵ һ�������ƶ�
	}
	ps->_a[0] = x;
	ps->_size++;


}
void SeqListPopFront(SeqList* ps)  //ͷɾ
{
	assert(ps && ps->_size > 0);

	for (size_t start = 0; start <= ps->_size - 1; ++start)
	{
		ps->_a[start] = ps->_a[start + 1];
	}

	ps->_size--;
}

int  SeqListFind(SeqList*ps, SLDataType x)//����
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

void SeqListInsert(SeqList*ps, size_t pos, SLDataType x)//����
{
	assert(ps && pos < ps->_size);
	SeqListCheckCapacity(ps);
	size_t  end = ps->_size + 1;  //���������з���Խ�������

	while (end > pos)
	{
		ps->_a[end] = ps->_a[end - 1];
		--end;
	}
	ps->_a[pos] = x;
	ps->_size++;
}

void SeqListErase(SeqList*ps, size_t pos)//ɾ��

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

//SeqListRemove(SeqList*ps, SLDataType x)  //�ƶ�
//{
//	int pos = SeqListFind(ps, x);
//	if (pos >= 0)
//	{
//		SeqListErase(ps, pos);
//
//	}
//}

 void SeqListBubbleSoet(SeqList* ps)//ð������
{
	 //����ð�ݵ���ֹλ��
	 for (size_t end = ps->_size; end > 0; --end)
	 {
		 int exchange = 0;
		 //����ð��
		 for (size_t i = 0; i < end - 1; i++)//ע����ʼλ������ֹλ��
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
 int  SeqListBinaryFind(SeqList* ps, SLDataType x) //���ֲ���
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
	 //����2
	size_t begin = 0, end = ps->_size; //<------- �����ɣ�  ������
	 while (begin < end )  //<------- ����ȥ��=
	 {
		 size_t mid = (begin + end) / 2;
		 if (ps->_a[mid] == x)
		 {
			 return mid;
		 }
		 else if (ps->_a[mid] < x)
		 {
			 begin = mid + 1; //<-------  ������ [  ������
		 }
		 else
		 {
			 end = mid ;//<------- ����ȥ�� +1 ��ɣ� ������
		 }
	 }
	 return -1; 
	 
	 
	 */
 }






