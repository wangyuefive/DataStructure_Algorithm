#include "stdafx.h"

int HibbardArray[32];   //在主程序中定义   

void CreateHibbardArray(int HibbardArray[] )
{
	int i = 0;
	HibbardArray[0] = 1;
	for(i = 1; i < 32 ; i++)
		HibbardArray[i] = HibbardArray[i-1] *2;
}

/***
  *希尔排序,采用最常见的二分增量序列
*/
void ShellSorter(int a[] , const int N)
{
	int i ,j,inc;
	int temp;
	for(inc = N/2 ; inc > 0 ; inc /=2)   //增量序列
		for(i = inc ; i < N ; i++)   //采用插入法排序  元素中间间隔为inc
		{
			temp = a[i];
			for( j = i; j >= inc; j -= inc)
				if(temp < a[j - inc])
					a[j] = a[j-inc];
				else
					break;
			a[j] = temp;
				
		}
}

/**
**找出2^k-1 < N/2 并且 2^(k+1) -1 > N/2的 k 的值
**其实这个也可以优化
**/
int find(int N)
{
	int i = 0;
	for(i = 0 ; i < 32 ; i++)
	{
		if(HibbardArray[i]  <= N/2 && HibbardArray[i+1] > N/2  )
			return i;
	}
	return -1;
}

/***
  *希尔排序,采用Hibbard序列 ：1 3 7   。。。。2^k-1 
  *调用前，先使用 CreateHibbardArray()创建一个HIbbard序列并引用;
*/
void ShellSorter_Hibbard(int a[] , const int N)
{
	int i ,j;
	int inc;
	int temp;
	int k = find(N);

	for(inc =HibbardArray[k]; inc > 0 ; inc = HibbardArray[--k])   //增量序列  ,求pow 和log 消耗的时间太多了
		for(i = inc ; i < N ; i++)   //采用插入法排序  元素中间间隔为inc
		{
			temp = a[i];
			for( j = i; j >= inc; j =j -inc)
				if(temp < a[j - inc])
					a[j] = a[j-inc];
				else
					break;
			a[j] = temp;
				
		}
}
