
#include"BinaryTree.h"
#include"Queue.h"
int main()
{


	char a[] = "ABD##E#H##CF##G##";

	int index = 0;
	int i = 0;
	BTNode* root = CreateTree(a, &index);
	printf("Size:%d\n", BinaryTreeSize(root));// �������ڵ����
	printf("LeafSize:%d\n", BinaryTreeLeafSize(root));// ������Ҷ�ӽڵ����
	printf("K Level:%d\n", BinaryTreeLevelKSize(root , 4));// ��������k��ڵ����
	printf("%s\n", &a[i]);
	BinaryTreeLevelOrder(root);
	
	
	return 0;

}