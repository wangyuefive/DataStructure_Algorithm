#include "stdafx.h"
/***
  *ϣ������
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
