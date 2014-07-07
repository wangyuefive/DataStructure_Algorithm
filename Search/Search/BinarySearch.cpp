#include "stdafx.h"

/***********二分查找*****************
**参数 ：int a[] 需要查找的数组
		 int N   数组的长度
		 int e 需要查找的元素
  返回值：int 返回元素所在的位置：
		  -1  查无此元素
*************************************/
int BinarySearch(int a[], int N , int e )
{
	int low,center,high;
	low = 0;
	high = N-1;
	while(low <= high)
	{
		center = (low + high)/2;
		if(a[center] == e)
			return center;
		else if (a[center] > e)
			high = center - 1;
		else
			low = center + 1;
	}
	return -1;
}