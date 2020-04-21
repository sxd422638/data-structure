#include"Stack.h"
#include"Queue.h"




void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	
	while (StackEmpty(&st) == 0)//遍历 到空的时候停止
	{
		printf(" %d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (QueueEmpty(&q) == 0)
	{
		printf(" %d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	QueueDestory(&q);


}




int main()
{
	TestStack();
	TestQueue();



	return 0;
}