
#include"BinaryTree.h"
#include"Queue.h"
int main()
{


	char a[] = "ABD##E#H##CF##G##";

	int index = 0;
	int i = 0;
	BTNode* root = CreateTree(a, &index);
	printf("Size:%d\n", BinaryTreeSize(root));// 二叉树节点个数
	printf("LeafSize:%d\n", BinaryTreeLeafSize(root));// 二叉树叶子节点个数
	printf("K Level:%d\n", BinaryTreeLevelKSize(root , 4));// 二叉树第k层节点个数
	printf("%s\n", &a[i]);
	BinaryTreeLevelOrder(root);
	
	
	return 0;

}