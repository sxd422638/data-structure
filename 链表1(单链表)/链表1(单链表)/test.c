#include"SList.h"





void TestList1()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
    SListPushFront(&plist, 100);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);

}
int main()
{
	TestList1();


	return 0;

}