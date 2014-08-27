#include"stdafx.h"

/**
* google��һ�������� �� ����4 000 000 000���� f(n) = n ������n
* f(n) ͳ������ 1��2,3,4��5,6��7,8,9,10,11,12����������1���ֵĴ���
*/


/**
* ��ȡ 1 ���ֵĴ���
*/
int getOneCount(int num)
{
	int count = 0;
	while(num > 0)
	{
		if(num % 10 == 1)
			count++;
		num /= 10;
	}
	return count ;
}

int main(void)
{
	double MAX = 4000000000;   //�տ�ʼ����Ϊ�� int �ͣ����ֱ�ӳ���
	int i = 0;
	int count = 0 ;

	printf("%d\n",getOneCount(101));
	for(i = 0 ; i < MAX ; i++)
	{
		count = count + getOneCount(i);
		if(i == count)
			printf("---------%d\n",i);
	}
	printf("------------------end------------------");
	getchar();
	return 0;
}
