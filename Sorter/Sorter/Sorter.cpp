// Sorter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define COUNT 100U    //个数
#define MAXNUM 1000U   //最大的数
#define MINNUM 1U    //最小的数
#define DEBUG

extern void InsertSorter(int a[], int N);
extern void ShellSorter(int a[] , int N);
extern void BasicSorter(int a[], int N);

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
			printf("%d  ",*(result->a+i));
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

void printResult(int a[],int N)
{
	int i = 0 ;
	printf("排序后的结果为:\n");
	while(i < N)
		printf("%d ",a[i++]);
	printf("\n");
}

int main(int argc, _TCHAR* argv[])
{
	pintArray intarray;
	timeb t1,t2;
	time_t time ;

	intarray = createArray();
	
	if(NULL == intarray)
	{
		perror("error in creatArray");
		exit(-1);
	}

	printf("/******采用插入排序法********/\n");
	ftime(&t1);   //获取当前时间
	InsertSorter(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printResult(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("所用时间为:%ld毫秒\n",time);

	clearArray(intarray);
	intarray = createArray();
	printf("/******采用希尔排序法********/\n");
	ftime(&t1);   //获取当前时间
	ShellSorter(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printResult(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("所用时间为:%ld毫秒\n",time);


	free(intarray);
	getchar();
	return 0;
}

