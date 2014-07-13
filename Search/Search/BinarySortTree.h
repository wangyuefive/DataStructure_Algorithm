#ifndef _BinarySortTree_H
#define _BinarySortTree_H

typedef struct position
{
	int index;
	struct position *next;
}position;   //指示元素的位置

typedef struct TreeNode{
	int data;     //数据
	int count;    //数据的个数
	position *nextposition; //位于数组中的位置
	struct TreeNode *left;  //左孩子
	struct TreeNode *right; //右孩子
}TreeNode, *pTreeNode;

/******用于查找的返回值******/
typedef struct {
	int flag;    //0，没有查到  ； 1：查到 
	pTreeNode tree; 
}FindedReturnValue;

extern int EmptyTree(pTreeNode tree);
extern FindedReturnValue Find(pTreeNode const root, int e);
extern pTreeNode FindMax(pTreeNode const root);
extern pTreeNode FindMin(pTreeNode const root);
extern int AddPosition(position *p , int pos);
extern int Insert(pTreeNode root, int e, int pos);
extern int Delete(pTreeNode const root, int e);
extern pTreeNode createBST(int a[], int length);
extern void printResult(pTreeNode tree);
extern void FindNum(pTreeNode tree);

#endif