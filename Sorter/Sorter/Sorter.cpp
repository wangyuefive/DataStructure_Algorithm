// Sorter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define COUNT  200000U   //个数
#define MAXNUM 300000U   //最大的数
#define MINNUM 1U    //最小的数
//#define DEBUG

extern void InsertSorter(int a[], int N);
extern void ShellSorter(int a[] , int N);
extern void BasicSorter(int a[], int N);
extern void CreateHibbardArray(int HibbardArray[] ) ; //创建HIbbard序列
extern void ShellSorter_Hibbard(int a[] , const int N);
extern void HeapSorter(int a[] , int N);
extern void MergeSorter(int a[] ,int N);
extern void QuickSort(int a[], int N);

/*自定义的数组*/
typedef struct intArray{
	int a[COUNT];
	int length;
}intArray,*pintArray;

extern int HibbardArray[32];    //希尔排序_Hibbard序列;对于32位int，2^32次方已经到了顶了


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

int main(int argc, _TCHAR* argv[])
{
	pintArray intarray;
	intArray temparray;    //用于保存初始数据
	timeb t1,t2;
	time_t time ;

	intarray = createArray();
	temparray = *intarray;  
	
	if(NULL == intarray)
	{
		perror("error in creatArray");
		exit(-1);
	}
	
	printf("\n\n\n");
	printf("/******采用基本冒泡排序法********/\n");
	ftime(&t1);   //获取当前时间
	BasicSorter(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printf("排序后的结果为:\n");
	printArray(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("所用时间为:%ld毫秒\n",time);

	printf("\n\n\n");
	*intarray =temparray;
	printf("/******采用插入排序法********/\n");
#ifdef DEBUG
	printf("初始数组为:\n");
	printArray(intarray->a, intarray->length);
#endif
	ftime(&t1);   //获取当前时间
	InsertSorter(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printf("排序后的结果为:\n");
	printArray(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("所用时间为:%ld毫秒\n",time);

	printf("\n\n\n");
	*intarray =temparray;
	printf("/******采用希尔_二分增量排序法********/\n");
#ifdef DEBUG
	printf("初始数组为:\n");
	printArray(intarray->a, intarray->length);
#endif
	ftime(&t1);   //获取当前时间
	ShellSorter(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printf("排序后的结果为:\n");
	printArray(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("所用时间为:%ld毫秒\n",time);


	CreateHibbardArray(HibbardArray);   //生成HIbbard序列
	printf("\n\n\n");
	*intarray =temparray;
	printf("/******采用希尔_Hibbard增量排序法********/\n");
#ifdef DEBUG
	printf("初始数组为:\n");
	printArray(intarray->a, intarray->length);
#endif
	ftime(&t1);   //获取当前时间
	ShellSorter_Hibbard(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printf("排序后的结果为:\n");
	printArray(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("所用时间为:%ld毫秒\n",time);


	printf("\n\n\n");
	*intarray =temparray;
	printf("/******采用堆排序法********/\n");
#ifdef DEBUG
	printf("初始数组为:\n");
	printArray(intarray->a, intarray->length);
#endif
	ftime(&t1);   //获取当前时间
	HeapSorter(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printf("排序后的结果为:\n");
	printArray(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("所用时间为:%ld毫秒\n",time);


	printf("\n\n\n");
	*intarray =temparray;
	printf("/******采用归并排序法********/\n");
#ifdef DEBUG
	printf("初始数组为:\n");
	printArray(intarray->a, intarray->length);
#endif
	ftime(&t1);   //获取当前时间
	MergeSorter(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printf("排序后的结果为:\n");
	printArray(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("所用时间为:%ld毫秒\n",time);

	printf("\n\n\n");
	*intarray =temparray;
	printf("/******采用快速排序法********/\n");
#ifdef DEBUG
	printf("初始数组为:\n");
	printArray(intarray->a, intarray->length);
#endif
	ftime(&t1);   //获取当前时间
	QuickSort(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printf("排序后的结果为:\n");
	printArray(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("所用时间为:%ld毫秒\n",time);


	free(intarray);
	getchar();
	return 0;
}

