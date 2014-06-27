#include "stdafx.h"

#define CUTOFF 3 //����ݹ������޶ȣ���left�����ֻ��CUTOFF��ʱ����ֹ�����µݹ�

extern void InsertSorter(int a[], int N);

void swap(int *a, int *b)
{
	int temp ;
	temp = *a ;
	*a = *b;
	*b =temp;
}

/*******��ŦԪ�صĲ��Һ���**********
** ����������ֵ�ָ���Ƚ�A[left],A[Right]��A[Center]��ѡȡ��Сλ���м��Ԫ����Ϊpivlot
** �����������������ź����A[center]��A[Right -1]����
** Ҳ���� pivlot�����A[Right-1]��λ��
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

	swap(a+center,a+right-1);   //������A[center]��pivlotԪ����A[right -1] ����

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
	else   //��ײ�ĵݹ�����
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


