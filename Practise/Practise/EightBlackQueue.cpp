//�˸��ʺ������
// ��̬�滮 + ��˷�㷨
#include"stdafx.h"

int a[8] = {0,0,0,0,0,0,0,0};  //ȫ��״̬����
int count =0;  //״̬������
int NUM = 8;   //���һʺ󣿣���

/****************************************
* int n : ��n��
* int k : ��k��  �ڵ�n���ϰѻʺ���ڵ�k����
******************************************/
int judge(int n, int k)
{
	int i = 0;
	if(n == 0)  //��һ�е��κ�һλ���ǿ��Ե�
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
	printf("=========��%d�����Ϊ��",++count);
	for(i = 0 ; i< NUM ; i++)
	{
		printf(" %d",a[i]);
	}
	printf("\n");
}

/**************************
** int N :��ʾ��N��
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

/*
int main()
{
	EightQueue(0);
	getchar();
}*/