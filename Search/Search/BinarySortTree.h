#ifndef _BinarySortTree_H
#define _BinarySortTree_H

typedef struct TreeNode{
	int data;     //����
	int position; //λ�������е�λ��
	struct TreeNode *left;  //����
	struct TreeNode *right; //�Һ���
}TreeNode, *pTreeNode;

/******���ڲ��ҵķ���ֵ******/
typedef struct {
	int flag;    //0��û�в鵽  �� 1���鵽 
	pTreeNode tree; 
}FindReturnValue;

#endif