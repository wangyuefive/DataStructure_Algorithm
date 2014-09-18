#include"stdafx.h"

/**
* google��һ�������� �� ����4 000 000 000���� f(n) = n ������n
* f(n) ͳ������ 1��2,3,4��5,6��7,8,9,10,11,12����������1���ֵĴ���
*/


/**
* ��ȡ 1 ���ֵĴ���
* �����ϰ취��ͨ��ȡ�����ͳ����ó�һ��������1�ĸ���
* ����㷨�и�ȱ�ݣ�������ȡ����̫�ķ�ʱ��
*/
int getOneCount(unsigned int num)
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


/**
* ���룺112334222  ---->1221324123   ����+���� ����ʾ��ʽ
*/
void printfStr(char *s)
{
	int count = 1 ;
	int i =0 ;
	printf("%s\n",s);
	for(i = 0; *(s+i) !='\0'; i++)
	{
		if(*(s+i) == *(s+i+1))
			count++;
		else{
			printf("%c%c",*(s+i),count+'0');
			count=1;
		}
	}
}

/*
int main(void)
{
	unsigned int MAX = 4000000000;   //�տ�ʼ����Ϊ�� int �ͣ����ֱ�ӳ���
	unsigned int i = 0;
	int count = 0 ;
	int resultcount = 0;

	printfStr("12333422222");
	timeb t1,t2;
	ftime(&t1);
	
	for(i = 0 ; i < MAX ; i++)
	{
		count = count + getOneCount(i);
		if(i == count){
  			resultcount++;
			printf("---------%d\n",i);
		}
	}
	ftime(&t2);
	printf("------------------end---------------\n");
	printf("-----time used:%dminute%dsec , sum: %d",t2.time-t1.time,t2.millitm-t1.millitm,resultcount);
	getchar();
	return 0;
}
*/
