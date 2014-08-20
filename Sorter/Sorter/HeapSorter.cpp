#include "stdafx.h"

#define LeftChild(i) (2*(i)+1)

/**
*����a[]���һ����ȫ��������PerDown()����Ĭ����iΪ���������ڵ� �� ��ȫ��������ȫ���϶���ѵ����ʣ��������ڵ�ȶ��ӽڵ��ȨֵҪô����Ҫô��С��ֻ�и��ڵ���ܲ����ϡ����ԣ�PerDown�����������������ʹ����iΪ��������ȫ��������ɶ����
*/
void PercDown(int a[] , int i ,int N)   
{
	int child;
	int temp;

	for(temp = a[i] ; LeftChild(i) < N ; i =child)
	{
		child = LeftChild(i);
		if(child !=N-1 &&a[child+1]>a[child])
			child++;     //�ж� �� i ���ڵ�� ���Һ���˭��
		if(temp < a[child])
			a[i]=a[child];
		else
			break;
	}
	a[i] = temp;
}

void Swap(int *a, int *b)
{
	int temp;
	temp =*a;
	*a = *b;
	*b =temp;
}

/***
**       ������
**/
void HeapSorter(int a[] , int N)
{
	int i ;

	for(i = N/2 ; i >=0 ;i--)   //���ɶ����  ���ƺ���һ�ֵݹ�ı���
		PercDown(a, i, N);
	for(i = N-1 ; i> 0 ; i--)
	{
		Swap(&a[0], &a[i]);
		PercDown(a, 0, i);
	}
}