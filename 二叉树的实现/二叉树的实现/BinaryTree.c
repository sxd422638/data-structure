#include"BinaryTree.h"
#include"Queue.h"



// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);

BTNode* CreateTree(BTDataType* a, int* pindex)
{
	BTNode* root;
	if (a[*pindex] != '#')
	{




		root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pindex];

		++(*pindex);
		root->_left = CreateTree(a, pindex);//������������

		++(*pindex);//���ұ�֮ǰҪ��++һ�� 
		root->_right = CreateTree(a, pindex);

		return root;
	}
	else
	{
		return NULL;
	}
}

// ����������
void BinaryTreeDestory(BTNode** root);

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1)
		+ BinaryTreeLevelKSize(root->_right, k - 1);//ֻ�Ƿ��ظ���һ�� ���Ƿ��ظ���


}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root);
// �������������
void BinaryTreeInOrder(BTNode* root);
// �������������
void BinaryTreePostOrder(BTNode* root);
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (!QueueEmepty(&q));
	{
		BTNode* front = QueueFront(&q);
		printf("%c", front->_data);
		QueuePop(&q);
		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}

	}
	printf("\n");
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{

	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (!QueueEmepty(&q));
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}
	while (!QueueEmepty(&q));
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
			return -1;
	}
	return 0;
}
