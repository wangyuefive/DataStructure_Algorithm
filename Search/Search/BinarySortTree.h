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

#endif