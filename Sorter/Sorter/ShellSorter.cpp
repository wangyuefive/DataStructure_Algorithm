#include "stdafx.h"

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
	double k ;
	double half = N/2 ;
	k = log((double)(half + 1)) / log((double)2);
	//if(k < half && k+1 > half)
	return (int)k;
	//else{
	//	perror("error in function find()");
		//return 0;
	//}
}

/***
  *希尔排序,采用Hibbard序列 ：1 3 7   。。。。2^k-1 
*/
void ShellSorter_Hibbard(int a[] , const int N)
{
	int i ,j;
	int inc;
	int temp;
	int k = find(N);

	for(inc =(int)pow((double)2,k); inc > 0 ; inc = (int)pow((double)2,--k))   //增量序列  ,求pow 和log 消耗的时间太多了
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
