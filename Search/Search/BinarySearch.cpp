#include "stdafx.h"

/***********���ֲ���*****************
**���� ��int a[] ��Ҫ���ҵ�����
		 int N   ����ĳ���
		 int e ��Ҫ���ҵ�Ԫ��
  ����ֵ��int ����Ԫ�����ڵ�λ�ã�
		  -1  ���޴�Ԫ��
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