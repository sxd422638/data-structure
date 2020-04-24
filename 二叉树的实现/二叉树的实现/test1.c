#include<stdio.h>
#include<malloc.h>
typedef struct BTreeNode
{
	struct BTreeNode* left;
	struct BTreeNode* right;
	int val;
}BTreeNode;



BTreeNode* CreateTree(char* a, int* pindex)
{
	if (a[*pindex] == '#');
	return NULL;
	BTreeNode* root = (BTreeNode*)malloc(sizeof(BTreeNode));
	root->val = a[*pindex];
	++(*pindex);
	root->left = CreateTree(a, pindex);//构建它的左树
	++(*pindex);//进右边之前要再++一次 
	root->right = CreateTree(a, pindex);
	return root;
}
void InOrder(BTreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	InOrder(root->left);
	printf("%c ", root->val);//走当前结点
	InOrder(root->right);

}
int main()
{
	char a[100] = { 0 };
	scanf("%s ", a);
	int index = 0;
	BTreeNode* root = CreateTree(a, &index);
	//PrevOrder InOrder PostOrder
	InOrder(root);
	return 0;
}