#include "stdafx.h"

/**  插入排序法
*int a[] 指向数组的数组指针
*int N : N数组的长度
*/
void InsertSorter(int a[], int N)
{
	int i,j ;
	int temp;
	for( i = 1 ; i < N ; i++)
	{
		temp = *(a+i);
		for(j = i ; j > 0 && a[j-1] > temp ; j-- )
			a[j] = a[j-1];
		a[j] = temp;
	}

}