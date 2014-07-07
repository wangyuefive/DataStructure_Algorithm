/*************************
****二叉排序树
*************************/
#include "stdafx.h"
#include "BinarySortTree.h"


/******清空二叉排序树*****/
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


/**********二叉排序树查找********
** 参数：pTreeNode root：根
		 int e 待查元素
   返回值：FindReturnValue类型
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
		if(curTree->data == e)   //有发现
		{
			value.flag = 1;
			value.tree = curTree;
			return value;
		}
		else if(curTree->data > e)   //没有发现
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