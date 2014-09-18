#include"stdafx.h"

/**
* google的一道面试题 ， 计算4 000 000 000以内 f(n) = n 的最大的n
* f(n) 统计数字 1，2,3,4，5,6，7,8,9,10,11,12。。。。中1出现的次数
*/


/**
* 获取 1 出现的次数
* 这是老办法，通过取余数和除法得出一个数的中1的个数
* 这个算法有个缺陷，除法和取余数太耗费时间
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
* 输入：112334222  ---->1221324123   数字+个数 的显示方式
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
	unsigned int MAX = 4000000000;   //刚开始定义为了 int 型，结果直接超了
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
