#include"stdafx.h"

/**
* 重建二叉树   
**/

#define FINDLEFT  0
#define FINDRIGHT 1

typedef struct BiTree{
	int data;
	struct BiTree *p_left;
	struct BiTree *p_right;
}BiTree ;

typedef struct IndexPointer{
	int PreOrderStart;
	int PreOrderEnd;
	int InOrderStart;
	int InOrderEnd;
}IndexPointer;

/**
*
*/
int FindIndexPointer(int *preArray , int *inArray ,IndexPointer index , int flag , IndexPointer *result)
{
	int ps = index.PreOrderStart;
	int pe = index.PreOrderEnd;
	int is = index.InOrderStart;
	int ie = index.InOrderEnd;
	int rootindex = 0 ; 
	int i = is;

	if(preArray == NULL || inArray == NULL)
	{
		perror("error in pointer");
		return ERROR;
	}

	for(i = is ; i <= ie ; i++)
	{
		if(inArray[i] = preArray[ps])   //中序数列中找到根 ，然后划分 左子树  右子数
		{	
			rootindex = i;
			break;
		}
	}

	if(flag == FINDLEFT)
	{
		result->InOrderStart = is ;
		result->InOrderEnd = rootindex -1;
		result->PreOrderStart = ps + 1;
		result->PreOrderEnd = ps + 1 + (rootindex - is) ;
	}else{
		result->InOrderStart = rootindex + 1;
		result->InOrderEnd = ie ;
		result->PreOrderStart = ps + 1 + (rootindex - is) + 1;
		result->PreOrderEnd = pe ;
	}
	return OK;
}

int ConstructCore(int *preA, int *inA, IndexPointer index, BiTree* result)
{
	int ps = index.PreOrderStart;
	int pe = index.PreOrderEnd;
	int is = index.InOrderStart;
	int ie = index.InOrderEnd;

	if(preA == NULL || inA == NULL)
	{
		perror("error in pointer,array pointer canot be null");
		return ERROR;
	}



}