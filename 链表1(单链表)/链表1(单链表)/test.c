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
	SListNode* ret = SListFind(plist, 1);//查找  修改
	if (ret)
		ret->_data = 30;
	SListPrint(plist);



	SListNode* pos = SListFind(plist, 30);

	SListInsertAfter(pos, 10000);       //插入后一位 
	SListPrint(plist);
	SListEraseAfter(plist);
	SListPrint(plist);                  //删除后一位

}
int main()
{
	TestList1();


	return 0;

}