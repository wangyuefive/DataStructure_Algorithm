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
		if(p->left != NULL)
			EmptyTree(p->left);
		if(p->right != NULL)
			EmptyTree(p->right);
		while(pos != NULL); 
		{
			free(pos);
			pos = pos->next;
		}
		free(p);
	}
	return OK;
}


/**********��������������********
** ������pTreeNode root����
		 int e ����Ԫ��
   ����ֵ��FindReturnValue����
		 FindReturnValue->flag = 0 ; û�з���  FindReturnValue->treeΪδ����Ԫ�ص�
		 FindReturnValue->flag = 1 ; ����Ԫ��  FindReturnValue->treeΪԪ��λ�ڲ������е�λ��
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
		else if(curTree->data < e)   //û�з���
		{
			preTree = curTree;
			curTree = curTree->right;
		}
		else
		{	
			preTree = curTree;
			curTree = curTree->left;
		}
	}
	value.flag = 0;    //�Ҳ����Ľڵ�һ��������һ��Ҷ�ӽڵ��������������������
	value.tree=preTree;
	return value;
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

void FindNum(pTreeNode tree)
{
	int num;
	FindedReturnValue value ;

	while(1){
		printf("\n��������ҵ�����������0�˳�\n");
		scanf("%d",&num);
		while(getchar()!='\n');
		if(num ==0){
			printf("������������\n");
			break;
		}

		value = Find(tree,num);
		if(value.flag == 0 )
			printf("û���ҵ�Ԫ��%d",num);
		else
			printResult(value.tree);
	}
}

/*********�����ظ���Ԫ�����Ԫ�ص�λ��**********
** ����ֵ: 1: ��ӳɹ�
		   -1 ���ʧ��
   ����: position *p  :��ʼλ��
         int pos      :��ӵ�Ԫ�ص�λ��
*/

int AddPosition(pTreeNode tree , int pos)
{
	position *temp = (position *)calloc(1,sizeof(position));  
	position *p = tree->nextposition;

	if(temp == NULL){
		perror("error in calloc in func addPostion\n");
		return -1;
	}
	temp->index = pos;
	temp->next = NULL;

	if(NULL == p)
	{
		tree->nextposition = temp;
		return 1;
	}
	else{
		while(p->next != NULL)
			p = p->next;
		p->next = temp;
	}
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
		AddPosition(value.tree, pos) ;	  
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
		AddPosition(p, pos) ;//����ڵ�

		if(value.tree->data < e)
			value.tree->right = p;
		else if(value.tree->data > e)
			value.tree->left = p;
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
	position *firstPos = (position *)calloc(1,sizeof(position)); //��һ��Ԫ�ص�λ��

	root = (pTreeNode)calloc(1,sizeof(TreeNode));
	if(NULL == root)
	{
		perror("error in calloc in func createBST()");
		return NULL;
	}
	/*��ʼ�����ڵ�*/
	firstPos->index = 0;
	firstPos->next = NULL;
	root->data = a[0];
	root->count =1;
	root->nextposition = firstPos;
	root->left =NULL;
	root->right =NULL ;

	/*�������index 1 ��ʼ*/
	for(i = 1 ; i < length ; i++)
	{
		if(Insert( root, a[i], i) == -1)
		{
			perror("error in createBST in the func Insert()");
			return NULL;
		};
	}

	return root;
}

/*********************
** ��ӡTreeNode�Ľ��
**********************/
void printResult(pTreeNode tree)
{
	position *pos = tree->nextposition;
	printf("\n-------���������ڵ��ӡ---------\n");
	printf(">>>>pTree point  = %d\n",tree);
	printf(">>>>ptree->data  = %d\n",tree->data);
	printf(">>>>ptree->count = %d\n",tree->count);
	printf(">>>>λ�÷ֱ�λ�ڣ�");
	while(pos != NULL)
	{
		printf(" %d",pos->index);
		pos = pos->next;
	}
	printf("\n");
	printf("-------���ڵ��ӡ����-----------\n\n");
}