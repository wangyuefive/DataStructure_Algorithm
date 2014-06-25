#include "stdafx.h"

/********************
** 采用递归的归并排序
*********************/

void Merge(int a[], int tempArray[] , int Lpos ,int Rpos ,int RightEnd)\
{
	int i,leftEnd,Elemcount,tmpPos;

	leftEnd = Rpos -1;     //
	tmpPos = Lpos;      //临时归并数组的 元素位置，起始值为Lpos
	Elemcount = RightEnd - Lpos + 1;

	/*main loop*/
	while(Lpos <= leftEnd &&Rpos <= RightEnd)
	{
		if(a[Lpos] < a[Rpos])
			tempArray[tmpPos++] = a[Lpos++];
		else
			tempArray[tmpPos++] = a[Rpos++];
	}

	/*copy余下的元组到临时数组*/
	while(Lpos <=leftEnd)
		tempArray[tmpPos++] = a[Lpos++];
	while(Rpos <= RightEnd)
		tempArray[tmpPos++] = a[Rpos++];

	/*将临时数组的排好序的元素 copy到原数组*/
	for(i = 0; i < Elemcount; i++,RightEnd--)
		a[RightEnd--] = tempArray[RightEnd--];
}

/**
**数组的index从left到right
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