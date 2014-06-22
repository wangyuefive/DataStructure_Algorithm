#include "stdafx.h"

/**  最基本排序法---冒泡
*int a[] 指向数组的数组指针
*int N : N数组的长度
*/
void BasicSorter(int a[], int N)
{
	int i,j ;
	int temp;
	for( i = 1 ; i < N ; i++)
		for(j = i ; j < N ; j++ )
			if(a[i] > a[j])
			{
				temp = a[j] ;
				a[j] = a[i];
				a[i] = temp;
			}
}