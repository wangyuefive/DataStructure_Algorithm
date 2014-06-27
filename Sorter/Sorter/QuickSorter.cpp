#include "stdafx.h"

#define CUTOFF 3 //定义递归的最低限度，当left与相差只有CUTOFF的时候，终止再往下递归

extern void InsertSorter(int a[], int N);

void swap(int *a, int *b)
{
	int temp ;
	temp = *a ;
	*a = *b;
	*b =temp;
}

/*******枢纽元素的查找函数**********
** 采用三数中值分割法，比较A[left],A[Right]，A[Center]，选取大小位于中间的元素作为pivlot
** 对上述三个数排序，排好序后，A[center]与A[Right -1]互换
** 也就是 pivlot存放在A[Right-1]的位置
**/
int Median3(int a[] , int left ,int right)
{
	int center = (left+right)/2;
	if(a[left] > a[center])
		swap(&a[left],&a[center]);
	if(a[left] > a[right])
		swap(&a[left],&a[right]);
	if(a[center] > a[right])
		swap(&a[center],&a[right]);

	swap(a+center,a+right-1);   //将存于A[center]的pivlot元素与A[right -1] 互换

	return a[right-1];
}

void QSort(int a[], int left, int right)
{
	int i,j;
	int pivlot ;

	if(left + CUTOFF <= right)
	{
		pivlot = Median3(a,left,right);
		i = left;
		j = right -1;
		while(1)
		{
			while(a[++i] < pivlot) ;
			while(a[--j] > pivlot) ;
			if(i < j)
				swap(a + i,a + j);
			else
				break;
		}
		swap(a + i, a + right - 1);

		QSort(a, left, i - 1);
		QSort(a, i + 1, right);
	}
	else   //最底层的递归排序
	{
		for(i = left; i < right; i++)
			for( j = left + 1; j <= right; j++)
			{
				if(a[i] > a[j])
					swap(a + i, a + j);
			}
	}
}

void QuickSort(int a[], int N)
{
	QSort(a,0,N-1);
}


