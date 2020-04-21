#include"Stack.h"





void StackInit(Stack* pst)//��ʼ��
{
	assert(pst);
	pst->a = NULL;
	pst->top = pst->capacity = 0;



}
void StackDestory(Stack* pst)//����
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;



}
void StackPush(Stack* pst, STDataType x) //ֻ������ջ�����в���
{
	assert(pst);
	if (pst->top == pst->capacity);
	{
		size_t newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		pst->a = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));//����
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;//top�����һ��λ�õ���һ��λ��

}
void StackPop(Stack* pst)//ֻ������ջ������ɾ��
{
	assert(pst && pst->top > 0 );
	--pst->top;



}
STDataType StackTop(Stack* pst)//top�����һ��λ�õ���һ��λ�� ��Ϊ�����±��ʱ��Ҫ-1
{
	assert(pst);
	return pst->a[pst->top - 1];

}
int StackEmpty(Stack* pst)//����1��ʾ�� ����0��ʾ�ǿ�
{
	assert(pst);
	return pst->top == 0 ? 1 : 0;

}
size_t StackSize(Stack* pst)//�������ݵĸ��� ��ʱ����-1 ����ʾʵ�ʵĸ���
{
	assert(pst);
	return pst->top;
}

