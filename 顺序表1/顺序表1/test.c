#include"SeqList.h"




void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);
	SeqListInsert(&s, 0, -1);
	SeqListPrint(&s);
	//SeqListErase(&s, 0, -1);
	//SeqListPrint(&s);

	//

}
void TestSeqList2()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 10);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);
	SeqListBubbleSoet(&s);
	SeqListPrint(&s);


	printf("%d\n", SeqListBinaryFind(&s, 2));
	printf("%d\n", SeqListBinaryFind(&s, 1));
	printf("%d\n", SeqListBinaryFind(&s, 10));
	printf("%d\n", SeqListBinaryFind(&s, 8));
	printf("%d\n", SeqListBinaryFind(&s, 6));
	printf("%d\n", SeqListBinaryFind(&s, 3));
	

	
}
int main()
{

	TestSeqList2();

	return 0;

}