#include "stdafx.h"

/**  ���������---ð��
*int a[] ָ�����������ָ��
*int N : N����ĳ���
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