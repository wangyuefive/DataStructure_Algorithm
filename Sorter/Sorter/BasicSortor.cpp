#include "stdafx.h"

/**  ���������---ð��
*int a[] ָ�����������ָ��
*int N : N����ĳ���
*/
void BasicSorter(int a[], const int N)
{
	int i,j ;
	int temp;
	for( i = 0 ; i < N -1 ; i++)
		for(j = i + 1 ; j < N ; j++ )
			if(a[i] > a[j])
			{
				temp = a[j] ;
				a[j] = a[i];
				a[i] = temp;
			}
}