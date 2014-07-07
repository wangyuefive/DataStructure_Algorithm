// Search.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BinarySortTree.h"

#define COUNT  20U   //个数
#define MAXNUM 30U   //最大的数
#define MINNUM 1U    //最小的数
#define DEBUG


/*自定义的数组*/
typedef struct intArray{
	int a[COUNT];
	int length;
}intArray,*pintArray;


/**
*生成一个长度为COUNT ,大小位于MAXNUM-MINNUM之间的随机数组
*返回pintArray的数组指针;
*/
pintArray createArray(void)
{
	pintArray result;
	int i = 0;
	int count = 0;
	result = (pintArray)calloc(1,sizeof(intArray));
	if(NULL == result)
	{
		perror("error in calloc");
		return NULL;
	}
	srand((unsigned int)time(NULL));   //种随机种子
	for(i = 0 ; i < COUNT; i++)
	{
		*(result->a+i) = rand() % (MAXNUM+1 -MINNUM) + MINNUM;
		count++;
	}
	result->length = count;
#ifdef DEBUG
	{
		printf("生成的数组如下:长度为%d\n",count);
		for( i = 0 ; i < result->length ; i++)
			printf("%d ",*(result->a+i));
		printf("\n");
	}
#endif
	return result;
}

void clearArray(pintArray arr)
{
	int i=0 ;
	while(i < arr->length)
	{
		*(arr->a+i)= 0;
		i++;
	}
	arr->length = 0;
}

void printArray(int a[],int N)
{
	int i = 0 ;
	while(i < N)
		printf("%d ",a[i++]);
	printf("\n");
}

int getNum(void)
{
	int num;
	printf("\n请输入查找的数：");
	scanf("%d",&num);
	while(getchar()!='\n');
	return num;
}

int _tmain(int argc, _TCHAR* argv[])
{
	pintArray intarray;
	intArray temparray;    //用于保存初始数据
	timeb t1,t2;
	time_t time ;

	intarray = createArray();  //生成原始数组
	temparray = *intarray;  
	
	if(NULL == intarray)
	{
		perror("error in creatArray");
		exit(-1);
	}

	free(intarray);
	getchar();
	return 0;
}

