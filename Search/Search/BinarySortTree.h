#ifndef _BinarySortTree_H
#define _BinarySortTree_H

typedef struct TreeNode{
	int data;     //数据
	int position; //位于数组中的位置
	struct TreeNode *left;  //左孩子
	struct TreeNode *right; //右孩子
}TreeNode, *pTreeNode;

/******用于查找的返回值******/
typedef struct {
	int flag;    //0，没有查到  ； 1：查到 
	pTreeNode tree; 
}FindReturnValue;

#endif