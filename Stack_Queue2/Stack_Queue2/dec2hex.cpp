#include "stdafx.h"
#include "stack.h"

void dec2hex(pSqStack s,int n)
{
	int temp = n;
	while(temp)
	{
		Push(s,temp%2);
		temp = temp / 2;
	}
	while(!StackEmpty(s))
	{
		Pop(s,&temp);
		printf("%d",temp);
	}
	printf("\n");
}
/*
int main(void)
{
	SqStack s;
	int num;
	InitStack(&s);
	while(getchar()!= 'a')
	{
		printf("������һ����ֵ��");
		scanf("%d",&num);
		printf("���Ϊ��");
		dec2hex(&s,num);
		printf("\n");
	}
	return 0;
}
*/
