/*************************
****����������
*************************/
#include "stdafx.h"
#include "BinarySortTree.h"


/******��ն���������*****/
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


/**********��������������********
** ������pTreeNode root����
		 int e ����Ԫ��
   ����ֵ��FindReturnValue����
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
		if(curTree->data == e)   //�з���
		{
			value.flag = 1;
			value.tree = curTree;
			return value;
		}
		else if(curTree->data > e)   //û�з���
		{
			preTree = curTree;
			curTree = curTree->right;
		}
		else
		{	
			preTree = curTree;
			curTree = curTree->left;
		}
		value.flag = 0;    //�Ҳ����Ľڵ�һ��������һ��Ҷ�ӽڵ��������������������
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

/*********�����ظ���Ԫ�����Ԫ�ص�λ��**********
** ����ֵ: 1: ��ӳɹ�
		   -1 ���ʧ��
   ����: position *p  :��ʼλ��
         int pos      :��ӵ�Ԫ�ص�λ��
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

/********����Ԫ��************
** ���� :pTreeNode root   //�����������ĸ�
		 int e   //Ҫ�����Ԫ��
		 int pos //Ҫ����Ԫ�ص�λ��
*/
int Insert(pTreeNode root, int e, int pos)
{
	pTreeNode p = NULL ;
	FindedReturnValue value ;

	value = Find( root,  e);

	if(value.flag == 1)   //�����Ѿ�����
	{
		value.tree->count++;
		addPosition(value.tree->nextposition, pos) ;	  
	}
	else  //δ����Ԫ��
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


/**********������ɾ��***********
** ��������ɾ������Ҳ�������ڵ�ĸ���count
	����Ϊ0;
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
		result.tree->count = 0;    //��Ǹ���Ϊ0��ʾɾ����
	return 1;
}

/**************���ɶ���������**************
** ���� : int a[] ԭʼ����
		  int length ���鳤��
   ����ֵ:pTreeNode���͵Ķ��������ڵ�
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