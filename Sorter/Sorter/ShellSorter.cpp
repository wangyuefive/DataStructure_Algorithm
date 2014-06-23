#include "stdafx.h"

/***
  *ϣ������,��������Ķ�����������
*/
void ShellSorter(int a[] , const int N)
{
	int i ,j,inc;
	int temp;
	for(inc = N/2 ; inc > 0 ; inc /=2)   //��������
		for(i = inc ; i < N ; i++)   //���ò��뷨����  Ԫ���м���Ϊinc
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
**�ҳ�2^k-1 < N/2 ���� 2^(k+1) -1 > N/2�� k ��ֵ
**��ʵ���Ҳ�����Ż�
**/
int find(int N)
{
	double k ;
	double half = N/2 ;
	k = log((double)(half + 1)) / log((double)2);
	if(k < half && k+1 > half)
		return (int)k;
	else{
		perror("error in function find()");
		return 0;
	}
}

/***
  *ϣ������,����Hibbard���� ��1 3 7   ��������2^k-1 
*/
void ShellSorter_Hibbard(int a[] , const int N)
{
	int i ,j;
	double inc;
	int temp;
	int k = find(N);
	for(inc = pow( ; inc > 0 ; inc = pow())   //��������
		for(i = inc ; i < N ; i++)   //���ò��뷨����  Ԫ���м���Ϊinc
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
