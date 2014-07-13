#ifndef _BinarySortTree_H
#define _BinarySortTree_H

typedef struct position
{
	int index;
	struct position *next;
}position;   //ָʾԪ�ص�λ��

typedef struct TreeNode{
	int data;     //����
	int count;    //���ݵĸ���
	position *nextposition; //λ�������е�λ��
	struct TreeNode *left;  //����
	struct TreeNode *right; //�Һ���
}TreeNode, *pTreeNode;

/******���ڲ��ҵķ���ֵ******/
typedef struct {
	int flag;    //0��û�в鵽  �� 1���鵽 
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