#include "stdafx.h"

/********************
** ���õݹ�Ĺ鲢����
*********************/

void Merge(int a[], int tempArray[] , int Lpos ,int Rpos ,int RightEnd)\
{
	int i,leftEnd,Elemcount,tmpPos;

	leftEnd = Rpos -1;     //
	tmpPos = Lpos;      //��ʱ�鲢����� Ԫ��λ�ã���ʼֵΪLpos
	Elemcount = RightEnd - Lpos + 1;

	/*main loop*/
	while(Lpos <= leftEnd &&Rpos <= RightEnd)
	{
		if(a[Lpos] < a[Rpos])
			tempArray[tmpPos++] = a[Lpos++];
		else
			tempArray[tmpPos++] = a[Rpos++];
	}

	/*copy���µ�Ԫ�鵽��ʱ����*/
	while(Lpos <=leftEnd)
		tempArray[tmpPos++] = a[Lpos++];
	while(Rpos <= RightEnd)
		tempArray[tmpPos++] = a[Rpos++];

	/*����ʱ������ź����Ԫ�� copy��ԭ����*/
	for(i = 0; i < Elemcount; i++,RightEnd--)
		a[RightEnd--] = tempArray[RightEnd--];
}

/**
**�����index��left��right
**/
void Msort(int a[] , int tempArray[] , int left , int right)
{
	int center;

	while(left < right)
	{
		center = (right + left) /2;
		Msort(a,tempArray,left,center);
		Msort(a,tempArray,center +1,right);
		Merge(a,tempArray,left,center+1,right);
	}
}

void MergeSorter(int a[] ,int N)
{
	int *tempArray;

	tempArray = (int*)malloc(N*sizeof(int));
	if(NULL != tempArray)
	{
		Msort(a,tempArray,0,N-1);
		free(tempArray);
	}
	else
		perror("error in malloc()");
}