/*************************
****二叉排序树
*************************/
#include "stdafx.h"
#include "BinarySortTree.h"


/******清空二叉排序树*****/
int EmptyTree(pTreeNode tree)
{
	pTreeNode p = tree;
	position *pos = tree->nextposition;
	while(p != NULL)
	{
		EmptyTree(p->left);
		EmptyTree(p->right);
		while(pos != NULL);
		{
			pos = pos->next;
			free(pos);
		}
		free(p);
	}
	return OK;
}


/**********二叉排序树查找********
** 参数：pTreeNode root：根
		 int e 待查元素
   返回值：FindReturnValue类型
*/
FindedReturnValue Find(pTreeNode const root, int e)
{
	FindedReturnValue value ;
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
			preTree = curTree;
			curTree = curTree->right;
		}
		else
		{	
			preTree = curTree;
			curTree = curTree->left;
		}
		value.flag = 0;    //找不到的节点一定是最后的一个叶子节点的左子数或者右子数；
		value.tree=preTree;
		return value;
	}
}

pTreeNode FindMax(pTreeNode const root)
{
	pTreeNode p = root;
	if( p == NULL)
		return NULL;
	while(p->left != NULL)
		p = p->left;
	return p;
}

pTreeNode FindMin(pTreeNode const root)
{
	pTreeNode p = root;
	if( p == NULL)
		return NULL;
	while(p->right != NULL)
		p = p->right;
	return p;
}

/*********对于重复的元素添加元素的位置**********
** 返回值: 1: 添加成功
		   -1 添加失败
   参数: position *p  :起始位置
         int pos      :添加的元素的位置
*/

int AddPosition(position *p , int pos)
{
	position *temp = (position *)calloc(1,sizeof(position));
	if(temp == NULL){
		perror("error in calloc in func addPostion\n");
		return -1;
	}
	while(p->next != NULL)
		p = p->next;
	p->next = temp;
	return 1;
}

/********插入元素************
** 参数 :pTreeNode root   //二叉排序树的根
		 int e   //要插入的元素
		 int pos //要插入元素的位置
*/
int Insert(pTreeNode root, int e, int pos)
{
	pTreeNode p = NULL ;
	FindedReturnValue value ;

	value = Find( root,  e);

	if(value.flag == 1)   //此数已经存在
	{
		value.tree->count++;
		addPosition(value.tree->nextposition, pos) ;	  
	}
	else  //未发现元素
	{
		p = (pTreeNode)calloc(1,sizeof(TreeNode));
		if( p == NULL ){
			perror("error in calloc in the func Insert()");
			return -1;
			}
		p->data = e;
		p->count = 1;
		addPosition(value.tree->nextposition, pos) ;	 
		if(value.tree->data < e)
			value.tree->left = p;
		else if(value.tree->data > e)
			value.tree->right = p;
	}
	return 1;
}


/**********二叉树删除***********
** 采用懒惰删除法，也就是数节点的个数count
	设置为0;
*/
int Delete(pTreeNode const root, int e)
{
	FindedReturnValue result;
	result =Find(root, e);
	if(result.flag == 0)
	{
		printf("can not delete element %d ,because it is not fonud\n",e);
		return -1;
	}
	else
		result.tree->count = 0;    //标记个数为0表示删除了
	return 1;
}

/**************生成二叉排序树**************
** 参数 : int a[] 原始数组
		  int length 数组长度
   返回值:pTreeNode类型的二叉树根节点
*/
pTreeNode createBST(int a[], int length)
{
	pTreeNode root = NULL;
	int i;

	root = (pTreeNode)calloc(1,sizeof(TreeNode));
	if(NULL == root)
	{
		perror("error in calloc in func createBST()");
		return NULL;
	}

	for(i = 0 ; i < length ; i++)
	{
		Insert( root, a[i], i);
	}

	return root;
}