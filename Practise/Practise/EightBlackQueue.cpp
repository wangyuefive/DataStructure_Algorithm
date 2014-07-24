//八个皇后的问题
// 动态规划 + 回朔算法
#include"stdafx.h"

int a[8] = {0,0,0,0,0,0,0,0};  //全局状态变量
int count =0;  //状态计数器
int NUM = 8;   //几桃皇后？？？

/****************************************
* int n : 第n列
* int k : 第k行  在第n列上把皇后放在第k行上
******************************************/
int judge(int n, int k)
{
	int i = 0;
	if(n == 0)  //第一列的任何一位都是可以的
		return 1;
	for(i =0 ; i < n ; i++)
	{
		if(a[i] == k || abs(n-k) == abs(i-a[i]) || (n+k) == (i+a[i]))
			return 0;
	}
	return 1;
}

void printResult()
{
	int i = 0;
	printf("=========第%d个结果为：",++count);
	for(i = 0 ; i< NUM ; i++)
	{
		printf(" %d",a[i]);
	}
	printf("\n");
}

/**************************
** int N :表示第N列
******************************/
void EightQueue(int N)
{
	int i =0;
	for(i =0 ; i < NUM; i++)
	{
		if(judge(N , i))
		{
			a[N] = i;
			if(N==NUM-1)
				printResult();
			else
				EightQueue(N+1);
		}
	}
	return ;
}

int main()
{
	EightQueue(0);
	getchar();
}