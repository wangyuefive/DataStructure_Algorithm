#include "stdafx.h"

extern int HibbardArray[32];   //���������ж���   

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
	int i = 0;
	for(i = 0 ; i < 32 ; i++)
	{
		if(HibbardArray[i]  <= N/2 && HibbardArray[i+1] > N/2  )
			return i;
	}
	return -1;
}

/***
  *ϣ������,����Hibbard���� ��1 3 7   ��������2^k-1 
*/
void ShellSorter_Hibbard(int a[] , const int N)
{
	int i ,j;
	int inc;
	int temp;
	int k = find(N);

	for(inc =HibbardArray[k]; inc > 0 ; inc = HibbardArray[--k])   //��������  ,��pow ��log ���ĵ�ʱ��̫����
		for(i = inc ; i < N ; i++)   //���ò��뷨����  Ԫ���м���Ϊinc
		{
			temp = a[i];
			for( j = i; j >= inc; j =j -inc)
				if(temp < a[j - inc])
					a[j] = a[j-inc];
				else
					break;
			a[j] = temp;
				
		}
}
