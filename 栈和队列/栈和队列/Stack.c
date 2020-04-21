#include"Stack.h"





void StackInit(Stack* pst)//初始化
{
	assert(pst);
	pst->a = NULL;
	pst->top = pst->capacity = 0;



}
void StackDestory(Stack* pst)//销毁
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;



}
void StackPush(Stack* pst, STDataType x) //只允许在栈顶进行插入
{
	assert(pst);
	if (pst->top == pst->capacity);
	{
		size_t newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		pst->a = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));//增容
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;//top是最后一个位置的下一个位置

}
void StackPop(Stack* pst)//只允许在栈顶进行删除
{
	assert(pst && pst->top > 0 );
	--pst->top;



}
STDataType StackTop(Stack* pst)//top是最后一个位置的下一个位置 作为数组下标的时候要-1
{
	assert(pst);
	return pst->a[pst->top - 1];

}
int StackEmpty(Stack* pst)//返回1表示空 返回0表示非空
{
	assert(pst);
	return pst->top == 0 ? 1 : 0;

}
size_t StackSize(Stack* pst)//返回数据的个数 这时候不用-1 它表示实际的个数
{
	assert(pst);
	return pst->top;
}

