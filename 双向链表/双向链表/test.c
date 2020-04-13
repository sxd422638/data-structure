#include"List.h"



void TestList1()
{
	ListNode* pHead = CreateHead();
	ListPushBack(pHead, 1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPushBack(pHead, 4);
	ListPushFront(pHead, 1);
	ListPushFront(pHead, 2);
	ListPushFront(pHead, 3);
	ListPushFront(pHead, 4);
	ListPrint(pHead);
	ListPopFront(pHead); 
	ListPrint(pHead);
}

int main()
{

	TestList1();


}