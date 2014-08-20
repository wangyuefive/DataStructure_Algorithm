#include "stdafx.h"

#define LeftChild(i) (2*(i)+1)

/**
*数组a[]组成一个完全二叉树，PerDown()函数默认以i为二叉树根节点 的 完全二叉树完全符合二叉堆的性质：即，父节点比儿子节点的权值要么都大，要么都小；只有根节点可能不符合。所以，PerDown（）函数的任务就是使得以i为根结点的完全二叉树变成二叉堆
*/
void PercDown(int a[] , int i ,int N)   
{
	int child;
	int temp;

	for(temp = a[i] ; LeftChild(i) < N ; i =child)
	{
		child = LeftChild(i);
		if(child !=N-1 &&a[child+1]>a[child])
			child++;     //判断 第 i 个节点的 左右孩子谁大
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
**       堆排序
**/
void HeapSorter(int a[] , int N)
{
	int i ;

	for(i = N/2 ; i >=0 ;i--)   //生成二叉堆  ，似乎是一种递归的变相
		PercDown(a, i, N);
	for(i = N-1 ; i> 0 ; i--)
	{
		Swap(&a[0], &a[i]);
		PercDown(a, 0, i);
	}
}