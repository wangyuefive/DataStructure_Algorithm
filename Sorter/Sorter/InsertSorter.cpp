#include "stdafx.h"

/**  ��������
*int a[] ָ�����������ָ��
*int N : N����ĳ���
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