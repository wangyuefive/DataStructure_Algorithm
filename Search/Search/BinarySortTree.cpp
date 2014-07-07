/*************************
****����������
*************************/
#include "stdafx.h"
#include "BinarySortTree.h"


/******��ն���������*****/
int EmptyTree(pTreeNode tree)
{
	pTreeNode p = tree;
	while(p != NULL)
	{
		EmptyTree(p->left);
		EmptyTree(p->right);
		free(p);
	}
	return OK;
}


/**********��������������********
** ������pTreeNode root����
		 int e ����Ԫ��
   ����ֵ��FindReturnValue����
*/
FindReturnValue Find(pTreeNode root, int e)
{
	FindReturnValue value ;
	pTreeNode preTree,curTree;

	preTree = curTree= root;
	value.flag = 0;
	value.tree = NULL;

	while(curTree != NULL)
	{
		if(curTree->data == e)   //�з���
		{
			value.flag = 1;
			value.tree = curTree;
			return value;
		}
		else if(curTree->data > e)   //û�з���
		{
			value.flag = 0;
			value.tree = preTree;
			return value;
		}
		else
		{	

		}
	}

	
}